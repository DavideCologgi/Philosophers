/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:03:03 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/18 15:24:57 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_philo{
	struct s_table	*table;
	pthread_mutex_t	lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		t1;
	int				id;
	int				status;
	int				eat_count;
	int				eating;
	int				time_to_die;
}	t_philo;

typedef struct s_table{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_t		*tid;
	int				flag_opt;
	int				philo_nb;
	int				die_time;
	int				eat_time;
	int				meals_nb;
	int				sleep_time;
	int				start_time;
	int				death;
	int				finish;
}	t_table;

// Funzioni utils.c
int	ft_is_digit(int arg);
int	ft_atoi(t_table *table, const char *str);
int	ft_strcmp(char *str1, char *str2);
int	ft_usleep(int time);
int	get_time();

// Funzioni init.c
void	init_table(t_table *table, char **argv);
void	check_input(t_table *table);
void	init_malloc(t_table *table);
void	init_forks(t_table *table);
void	init_philos(t_table *table);

void	close_program(t_table *table, int flag);

// Funzioni lunch.c
void	start_lunch(t_table *table);
void	*lunch(void *philo_ptr);
void	*doctor();
void	*chef();

// Funzioni actions.c
void	eat(t_philo *philo);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	status(char *str, t_philo *philo);


#endif
