/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:03:03 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/25 09:44:35 by dcologgi         ###   ########.fr       */
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
# include <sys/types.h>
# include <stdint.h>

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
	pthread_t		th;
	uint64_t		time_to_die;
	int				id;
	int				status;
	int				eat_count;
	int				eating;
}	t_philo;

typedef struct s_table{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	pthread_t		*tid;
	uint64_t		start_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		die_time;
	int				flag_opt;
	int				philo_nb;
	int				min_meals;
	int				death;
	int				finish;
}	t_table;

// Funzioni utils.c
int			ft_is_digit(int arg);
int			ft_strcmp(char *str1, char *str2);
int			ft_usleep(uint64_t time);
int			check_philo_nb(int philo_nb);
long int	ft_atoi(const char *str);

// Funzioni init.c
int			put_forks(t_table *table);
int			init_malloc(t_table *table);
int			init(t_table *table, char **argv, int argc);
void		init_philos(t_table *table);
void		init_table(t_table *table, char **argv);

// Funzioni lunch.c
int			start_thread(t_table *table);
void		*lunch(void *philo_ptr);
void		*doctor(void *philo_ptr);
void		*chef(void *table_ptr);

// Funzioni actions.c
void		eat_meal(t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		print_status(char *str, t_philo *philo);
uint64_t	get_time(void);

// Funzioni main.c
int			print_error(char *str, t_table *table);
void		close_program(t_table *table);
void		clear_table(t_table	*table);

#endif
