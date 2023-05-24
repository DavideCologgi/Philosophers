/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:41:48 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/24 14:16:46 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*chef(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->table->write);
	printf("val: %d", philo->table->death);
	pthread_mutex_unlock(&philo->table->write);
	while (philo->table->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->table->finish >= philo->table->philo_nb)
			philo->table->death = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*doctor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->table->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo);
		if (philo->eat_count == philo->table->min_meals)
		{
			pthread_mutex_lock(&philo->table->lock);
			philo->table->finish++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->table->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*lunch(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	philo->time_to_die = philo->table->die_time + get_time();
	if (pthread_create(&philo->th, NULL, &doctor, (void *)philo))
		return ((void *)1);
	while (philo->table->death == 0)
	{
		eat(philo);
		status(THINKING, philo);
	}
	if (pthread_join(philo->th, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	thread_init(t_table *table)
{
	int			i;
	pthread_t	t0;

	i = -1;
	table->start_time = get_time();
	if (table->meals_nb > 0)
	{
		if (pthread_create(&t0, NULL, &chef, &table->philos[0]))
			return (error(TH_ERR, table));
	}
	while (++i < table->philo_num)
	{
		if (pthread_create(&table->tid[i], NULL, &lunch, &table->philos[i]))
			return (error(TH_ERR, table));
		ft_usleep(1);
	}
	i = -1;
	while (++i < table->philo_num)
	{
		if (pthread_join(table->tid[i], NULL))
			return (error(JOIN_ERR, table));
	}
	return (0);
}
