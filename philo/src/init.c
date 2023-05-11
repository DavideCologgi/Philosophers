/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:34:04 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/11 16:01:25 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_input(t_table *table)
{
	if (table->philo_nb < 1)
	{
		printf("Non c'é nessuno a tavola\n");
		close_program(table, 0);
	}
	else if (table->philo_nb > 200)
	{
		printf("Serve un tavolo troppo grande\n");
		close_program(table, 0);
	}
	else if (table->die_time < 0 || table->eat_time < 0 || table->sleep_time < 0)
	{
		printf("Errore nei valori dei tempi\n");
		close_program(table, 0);
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
		i++;
	}
}

void	init_table(t_table *table, char **argv)
{
	table->philo_nb = ft_atoi(table, argv[1]);
	table->die_time = ft_atoi(table, argv[2]);
	table->eat_time = ft_atoi(table, argv[3]);
	table->sleep_time = ft_atoi(table, argv[4]);
	if (table->flag_opt == 1)
		table->meals_nb = ft_atoi(table, argv[5]);
	else
		table->meals_nb = -1;
	table->death = 0;
	table->finish = 0;
	check_input(table);
	init_forks(table);
	init_philos(table);
}

void	*routine(void *data_ptr)
{

}

void	start(t_table *table)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&table->tid, NULL, &routine, NULL);
	pthread_mutex_destroy(&mutex);
}
