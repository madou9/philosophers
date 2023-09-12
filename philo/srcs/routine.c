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
	pthread_mutex_init(&data->general, NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// printf("ID = %d\n", philo->id);
	// if (philo->id % 2 ==
	// if (philo->id % 2 == 1)
	// 	ft_usleep(2000);
	while (1)
	{
		if (check_flag_died((t_philo *)philo->all))
			return (NULL);

		pthread_mutex_lock(philo->general);

		ft_eat_meal(philo);
		ft_sleep(philo);
		ft_think(philo);
		ft_usleep(100);
	}
	return (NULL);
}
