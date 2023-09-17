/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/15 17:36:27 by ihama            ###   ########.fr       */
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
		printf("%ld\t%d has taken a fork\n", timestamp, id);
		printf("%ld\t%d has taken a fork\n", timestamp, id);
		printf("%ld\t%d is eating\n", timestamp, id);
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
	philo->state = PHILO_STATE_THINKING;
	print_message(philo, philo->state);
}

void	ft_sleep(t_philo *philo)
{
	philo->state = PHILO_STATE_SLEEPING;
	print_message(philo, philo->state);
	ft_usleep(philo->data->time_to_sleep);
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
	philo->eating = 1;
	philo->state = PHILO_STATE_EATING;
	print_message(philo, philo->state);
	philo->last_meal_time = ft_get_time();
	philo->last_eat++;
	ft_usleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->neibor_fork);
	pthread_mutex_unlock(&philo->own_fork);
}
