/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:03:03 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/11 15:41:27 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_table{
	int				flag_opt;
	int				philo_nb;
	int				die_time;
	int				eat_time;
	int				meals_nb;
	int				sleep_time;
	int				start_time;
	int				death;
	int				finish;
	t_philo			*philos;
	pthread_t		*tid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_table;

typedef struct s_philo{
	int				id;
	int				eat_count;
	int				eating;
	int				time_to_die;
	pthread_t		t1;
	struct s_table	*table;
	pthread_mutex_t	lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int		ft_isdigit(int arg);
int		ft_atoi(t_table *table, const char *str);

void	init_table(t_table *table, char **argv);
void	init_philos(t_table *table);
void	check_input(t_table *table);

void	close_program(t_table *table, int flag);
void	start(t_table *table);

#endif
