/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/10 19:14:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, t_philo *philo)
{
	data->dead_flag = 0;
	data->philo = philo;
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->wait_to_print, NULL);
	pthread_mutex_init(&data->wait_to_eat, NULL);
}

int	check_if_someone_died(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->philo_dead == 1)
		return (pthread_mutex_unlock(philo->death_lock), 1);
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int i = 0;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(1);
	while (i < philo->num_to_eat)
	{
		ft_think(philo);
		ft_eat_meal(philo);
		ft_sleep(philo);
	}
	return (arg);
}
