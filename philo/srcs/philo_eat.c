/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/10/02 14:35:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(char *str, t_philo *philo, int id)
{
	long	timestamp;

	timestamp = ft_get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->wait_print);
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

void	ft_eat_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->neibor_fork);
	print_message(FORKS, philo, philo->id);
	pthread_mutex_lock(&philo->own_fork);
	print_message(FORKS, philo, philo->id);
	print_message(EAT, philo, philo->id);
	pthread_mutex_lock(&philo->data->last_meal);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->data->last_meal);
	philo->last_eat++;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->own_fork);
	pthread_mutex_unlock(philo->neibor_fork);
}
