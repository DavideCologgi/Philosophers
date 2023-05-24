/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:02:23 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/24 16:29:03 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
		{
			print_error("Qualche parametro negativo e/o non numerico", NULL);
			exit (1);
		}
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

int	check_philo_nb (int	philo_nb)
{
	if (philo_nb < 1)
		return (print_error("Non c'é nessuno a tavola", NULL));
	if (philo_nb > 200)
		return( print_error("Dove li metto tutti questi filosofi!?", NULL));
	return (0);
}

int	ft_usleep(uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
