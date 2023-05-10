/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:06:23 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/10 10:39:16 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_program(void)
{
	exit (1);
}

void	init(t_data *philo, char **argv)
{
	philo->nb = ft_atoi(argv[1]);
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	if (philo->flag_opt == 1);
		philo->max_eat == ft_atoi(argv[5]);
}

int	main (int argc, char **argv)
{
	t_data	philo;

	philo.flag_opt == 0;
	if (argc < 5)
	{
		printf("Troppi pochi argomenti in ingresso");
		close_program();
	}
	else if (argc == 5)
	{
		init(&philo, argv);
		start(&philo);
	}
	else if (argc == 6)
	{
		philo.flag_opt == 1;
		init(&philo, argv);
		start(&philo);
	}
	else
	{
		printf("Troppi argomenti in ingresso");
		close_program();
	}
}
