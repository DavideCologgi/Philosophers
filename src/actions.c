/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:54:13 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/23 14:13:58 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	status(char *str, t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->table->write);
	time = get_time(philo->table) - philo->table->start_time;
	if (ft_strcmp(DIED, str) == 0 && philo->table->death == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->table->death = 1;
	}
	if (!philo->table->death)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->table->write);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	status(SLEEPING, philo);
	ft_usleep(philo->table->sleep_time);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	status(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->r_fork);
	status(TAKE_FORKS, philo);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->table->die_time;
	status(EATING, philo);
	philo->eat_count++;
	ft_usleep(philo->table->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}
