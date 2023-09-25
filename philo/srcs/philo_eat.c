/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/25 20:47:53 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(char *str, t_philo *philo, int id)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->wait_print);
	timestamp = ft_get_time() - philo->data->start_time;
	if (!check_someone_died(philo))
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
	pthread_mutex_lock(&philo->data->last_meal);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->data->last_meal);
	philo->last_eat++;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->neibor_fork);
	pthread_mutex_unlock(&philo->own_fork);
}
