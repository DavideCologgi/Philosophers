/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:41:22 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/25 10:10:03 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clear_table(t_table	*table)
{
	if (table->tid)
		free(table->tid);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

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
	clear_table(table);
}

int	print_error(char *str, t_table *table)
{
	printf("%s\n", str);
	if (table)
		close_program(table);
	return (1);
}

int	where_is_second_fork(t_table *table)
{
	table->start_time = get_time();
	if (pthread_create(&table->tid[0], NULL, &lunch, &table->philos[0]))
		return (print_error("Errore creazione thread\n", table));
	pthread_detach(table->tid[0]);
	while (table->death == 0)
		ft_usleep(0);
	close_program(table);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("Numero parametri errato\n");
		return (1);
	}
	if (init(&table, argv, argc))
		return (1);
	if (table.philo_nb == 1)
		return (where_is_second_fork(&table));
	if (start_thread(&table))
		return (1);
	close_program(&table);
	return (0);
}
