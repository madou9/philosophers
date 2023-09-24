/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/24 19:19:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// uint64_t	get_start_time(t_data *data)
// {
// 	uint64_t	time;

// 	pthread_mutex_lock(&data->mut_start_time);
// 	time = data->start_time;
// 	pthread_mutex_unlock(&data->mut_start_time);
// 	return (time);
// }

void	print_message(char *str, t_philo *philo, int id)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->wait_print);
	timestamp = ft_get_time() - philo->data->start_time;
	if (!philo->data->philo_died)
		printf("%ld %d %s\n", timestamp, id, str);
	pthread_mutex_unlock(&philo->data->wait_print);
}

void	ft_think(t_philo *philo)
{
	print_message(THINK, philo, philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_message(SLEEP, philo, philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->neibor_fork);
		print_message(TAKE_FORKS, philo, philo->id);
		pthread_mutex_lock(&philo->own_fork);
		print_message(TAKE_FORKS, philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->own_fork);
		print_message(TAKE_FORKS, philo, philo->id);
		pthread_mutex_lock(philo->neibor_fork);
		print_message(TAKE_FORKS, philo, philo->id);
	}
}

void	ft_eat_meal(t_philo *philo)
{
	ft_take_fork(philo);
	print_message(EAT, philo, philo->id);
	pthread_mutex_lock(&philo->data->wait_print);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->data->wait_print);
	philo->last_eat++;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->neibor_fork);
	pthread_mutex_unlock(&philo->own_fork);
}
