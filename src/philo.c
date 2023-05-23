/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:06:23 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/23 15:54:12 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	close_program(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].lock);
	}
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->lock);
	if (table->tid)
		free(table->tid);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	table.flag_opt = 0;
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Troppi pochi argomenti in ingresso\n");
		else
			printf("Troppi argomenti in ingresso\n");
		exit (1);
	}
	else
	{
		if (argc == 6)
			table.flag_opt = 1;
		init_table(&table, argv);
		start_thread(&table);
	}
	close_program(&table);
	return (0);
}
