/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:23:43 by ihama             #+#    #+#             */
/*   Updated: 2023/09/08 22:27:50 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_message("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

int	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	return (0);
}

int	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	return (0);
}

int	ft_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (take_right_fork(philo) != 0)
		{
			drop_fork(philo);
			return (1);
		}
	}
	else
	{
		if (take_left_fork(philo) != 0)
		{
			drop_fork(philo);
			return (1);
		}
	}
	return (0);
}
