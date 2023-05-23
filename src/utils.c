/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:42:21 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/23 16:37:59 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
		{
			printf("Qualche parametro negativo e/o non numerico\n");
			exit (1);
		}
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
	{
		printf("Parametri con troppe cifre\n");
		exit (1);
	}
	return (result);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(char *)str1 - *(char *)str2);
}

int	ft_usleep (uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Errore di gettimeofday\n");
		exit(1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
