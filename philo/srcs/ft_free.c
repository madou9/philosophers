/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:35:55 by ihama             #+#    #+#             */
/*   Updated: 2023/09/10 17:05:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	error_message(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	cleanup(t_data *data, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->wait_to_eat);
	pthread_mutex_destroy(&data->wait_to_print);
	while (i < data->philo[0].phil_nbr)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}
