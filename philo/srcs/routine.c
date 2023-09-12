/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/12 19:42:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, t_philo *philo)
{
	data->dead_flag = 0;
	data->philo = philo;
	pthread_mutex_init(&data->wait_to_print, NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int i = 0;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_think(philo);
	while (ft_get_time() - philo->last_meal < philo->time_to_die)
	{
		ft_eat_meal(philo);
		ft_sleep(philo);
		ft_think(philo);
		i++;
	}
	return (NULL);
}
