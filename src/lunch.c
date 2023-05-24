/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:41:48 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/24 16:12:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*chef(void *table_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) table_ptr;
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
			status(DIED, philo);
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
		eat_meal(philo);
		status(THINKING, philo);
	}
	if (pthread_join(philo->th, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	start_thread(t_table *table)
{
	int			i;
	pthread_t	thread;

	i = -1;
	table->start_time = get_time();
	if (table->min_meals > 0)
	{
		if (pthread_create(&thread, NULL, &chef, &table->philos[0]))
			return (print_error("Errore creazione thread chef\n", table));
	}
	while (++i < table->philo_nb)
	{
		if (pthread_create(&table->tid[i], NULL, &lunch, &table->philos[i]))
			return (print_error("Errore creazione thread\n", table));
		ft_usleep(1);
	}
	i = -1;
	while (++i < table->philo_nb)
	{
		if (pthread_join(table->tid[i], NULL))
			return (print_error("Errore join thread\n", table));
	}
	return (0);
}
