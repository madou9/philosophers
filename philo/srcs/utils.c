/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:03:15 by ihama             #+#    #+#             */
/*   Updated: 2023/09/13 15:19:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_die(t_philo *philo)
{
	if (check_if_someone_died(philo) == 1)
	{
		print_message("has died", philo);
		philo->data->philo_died = 1;
	}
}

int	check_if_someone_died(t_philo *philo)
{
	if (ft_get_time() - philo->data->time_to_die > philo->last_meal_time)
		return (1);
	return (0);
}
	// if (ft_get_time() > philo->data->time_to_die) // 600

	// printf("\ntime_to_die: %ld\n", philo->data->time_to_die);
	// printf("\time_since_last_meal: %ld\n", time_since_last_meal);

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
