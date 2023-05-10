/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:03:03 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/10 11:06:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_data{
	int	flag_opt;
	int	nb;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	max_eat;
}	t_data;

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int	ft_isdigit(int arg);
int	ft_atoi(const char *str);

void	close_program(void);
void	init(t_data *philo, char **argv);

void	start(t_data *philo);

#endif
