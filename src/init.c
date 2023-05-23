/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:34:04 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/23 15:45:13 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_input(t_table *table)
{
	if (table->philo_nb < 1)
	{
		printf("Non c'é nessuno a tavola!\n");
		exit (1);
	}
	else if (table->philo_nb > 200)
	{
		printf("Dove li metto tutti questi filosofi??? Anche meno bro!\n");
		exit (1);
	}
}

void	init_malloc(t_table *table)
{
	table->tid = malloc(sizeof(pthread_t) * table->philo_nb);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	table->philos = malloc(sizeof(t_philo) * table->philo_nb);
	if (!table->tid || !table->forks || !table->philos)
	{
		printf("Errore di allocazione\n");
		close_program(table);
	}
}

void	init_forks(t_table *table)
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
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].eating = 0;
		table->philos[i].time_to_die = table->die_time;
		pthread_mutex_init(&table->philos[i].lock, NULL);
		i++;
	}

}

void	init_table(t_table *table, char **argv)
{
	table->philo_nb = ft_atoi(argv[1]);
	table->die_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	if (table->flag_opt == 1)
		table->meals_nb = ft_atoi(argv[5]);
	else
		table->meals_nb = -1;
	table->death = 0;
	table->finish = 0;
	check_input(table);
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->lock, NULL);
	init_malloc(table);
	init_forks(table);
	init_philos(table);
}
