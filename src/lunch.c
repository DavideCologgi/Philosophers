/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:42:36 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/23 16:33:15 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*doctor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(&philo->table->write);
	printf("data val: %d", philo->table->death);
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

void	*chef(void *table_ptr)
{
	t_philo *philo;

	philo = (t_philo *)table_ptr;
	while (philo->table->death == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			status(DIED, philo);
		if (philo->eat_count == philo->table->meals_nb)
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

void	start_thread(t_table *table)
{
	int			i;
	pthread_t	th;

	i = -1;
	table->start_time = get_time(table);
	if (table->meals_nb > 0)
	{
		if (pthread_create(&th, NULL, &chef, &table->philos[0]) != 0)
		{
			printf("Errore creazione chef_thread\n");
			close_program(table);
		}
	}
	while (++i < table->philo_nb)
	{
		if (pthread_create(&table->tid[i], NULL, &lunch, &table->philos[i]) != 0)
		{
			printf("Errore creazione thread\n");
			close_program(table);
		}
		ft_usleep(1);
	}
	i = -1;
	while (++i < table->philo_nb)
	{
		if (pthread_join(table->tid[i], NULL))
		{
			printf("Errore nel join dei thread\n");
			close_program(table);
		}
	}
}
