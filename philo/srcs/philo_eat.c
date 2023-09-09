/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/09 14:58:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(char *str, t_philo *philo)
{
	long long	timestamp;

	timestamp = ft_get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->wait_to_print);
	printf("%llu %d %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(&philo->data->wait_to_print);
}

void	ft_eat_meal(t_philo *philo)
{
	ft_take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->last_meal_time = ft_get_time();
	print_message("Is eating", philo);
	philo->eating++; // 2
	ft_usleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_fork(philo);
}
