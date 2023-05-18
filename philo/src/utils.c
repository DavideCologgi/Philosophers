/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:42:21 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/18 14:48:51 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(t_table *table, const char *str)
{
	int			i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
		{
			printf("Qualche parametro non e' numerico\n");
			close_program(table, 0);
		}
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
	{
		printf("Parametri troppo grandi\n");
		close_program(table, 0);
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

int	ft_usleep (int time)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Errore di gettimeofday\n");
		exit(1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
