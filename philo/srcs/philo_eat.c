/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/13 19:14:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(char *str, t_philo *philo)
{
	long int	timestamp;

	timestamp = ft_get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->wait_to_print);
	printf("%ld %d %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(&philo->data->wait_to_print);
}

void	ft_think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		print_message("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message("has taken a fork", philo);
		pthread_mutex_lock(philo->right_fork);
		print_message("has taken a fork", philo);
	}
}

void	ft_eat_meal(t_philo *philo)
{
	ft_take_fork(philo);
	philo->eating = 1;
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal_time = ft_get_time();
	philo->last_eat++;
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
