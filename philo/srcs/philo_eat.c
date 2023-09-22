/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/22 20:25:19 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	print_message(char *str, t_philo *philo)
// {
// 	long	timestamp;

// 	pthread_mutex_lock(&philo->wait_to_print);
// 	timestamp = ft_get_time() - philo->data->start_time;
// 	pthread_mutex_unlock(&philo->wait_to_print);
// 	printf("%ld %d %s\n", timestamp, philo->id, str);
// }

void	print_message(t_philo *philo, int state)
{
	int		id;
	long	timestamp;

	id = philo->id;
	timestamp = ft_get_time() - philo->data->start_time;
	if (state == PHILO_STATE_EATING)
	{
		pthread_mutex_lock(&philo->data->lock);
		printf("%ld\t%d has taken a fork\n", timestamp, id);
		printf("%ld\t%d has taken a fork\n", timestamp, id);
		printf("%ld\t%d is eating\n", timestamp, id);
		pthread_mutex_unlock(&philo->data->lock);
	}
	else if (state == PHILO_STATE_SLEEPING)
		printf("%ld\t%d is sleeping\n", timestamp, id);
	else if (state == PHILO_STATE_THINKING)
		printf("%ld\t%d is thinking\n", timestamp, id);
	else if (state == PHILO_STATE_DEAD)
		printf("%ld\t%d is dead\n", timestamp, id);
}

void	ft_think(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->lock);
	philo->state = PHILO_STATE_THINKING;
	print_message(philo, philo->state);
	// pthread_mutex_unlock(&philo->data->lock);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	philo->state = PHILO_STATE_SLEEPING;
	print_message(philo, philo->state);
	ft_usleep(philo->data->time_to_sleep);
	pthread_mutex_unlock(&philo->data->lock);
}

void	ft_take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->neibor_fork);
		pthread_mutex_lock(&philo->own_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->own_fork);
		pthread_mutex_lock(philo->neibor_fork);
	}
}

void	ft_eat_meal(t_philo *philo)
{
	ft_take_fork(philo);
	philo->state = PHILO_STATE_EATING;
	print_message(philo, philo->state);
	pthread_mutex_lock(&philo->data->lock);
	
	philo->last_meal_time = ft_get_time();
	philo->last_eat++;
	pthread_mutex_unlock(&philo->data->lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->neibor_fork);
	pthread_mutex_unlock(&philo->own_fork);
}
