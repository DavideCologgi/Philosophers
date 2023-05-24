/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:01:50 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/24 16:18:39 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_malloc(t_table *table)
{
	table->tid = malloc(sizeof(pthread_t) * table->philo_nb);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	table->philos = malloc(sizeof(t_philo) * table->philo_nb);
	if (!table->tid || !table->forks || !table->philos)
		return (print_error("Errore nel malloc\n", table));
	return (0);
}

int	put_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
		pthread_mutex_init(&table->forks[i], NULL);
	i = 0;
	table->philos[0].l_fork = &table->forks[0];
	table->philos[0].r_fork = &table->forks[table->philo_nb - 1];
	i = 1;
	while (i < table->philo_nb)
	{
		table->philos[i].l_fork = &table->forks[i];
		table->philos[i].r_fork = &table->forks[i - 1];
		i++;
	}
	return (0);
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].time_to_die = table->die_time;
		table->philos[i].eat_count = 0;
		table->philos[i].eating = 0;
		table->philos[i].status = 0;
		pthread_mutex_init(&table->philos[i].lock, NULL);
		i++;
	}
}

int	prepare_table(t_table *table, char **argv, int argc)
{
	table->philo_nb = (int) ft_atoi(argv[1]);
	if (check_philo_nb(table->philo_nb))
		return (1);
	table->die_time = (uint64_t) ft_atoi(argv[2]);
	table->eat_time = (uint64_t) ft_atoi(argv[3]);
	table->sleep_time = (uint64_t) ft_atoi(argv[4]);
	if (argc == 6)
		table->min_meals = (int) ft_atoi(argv[5]);
	else
		table->min_meals = -1;
	table->death = 0;
	table->finish = 0;
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->lock, NULL);
	return (0);
}

int	init(t_table *table, char **argv, int argc)
{
	if (prepare_table(table, argv, argc))
		return (1);
	if (init_malloc(table))
		return (1);
	if (put_forks(table))
		return (1);
	init_philos(table);
	return (0);
}
