/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/22 19:05:44 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while ((philo->data->max_to_eat > philo->last_eat)
		&& philo->data->phil_nbr != 1)
	{
		ft_eat_meal(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	if (philo->data->phil_nbr == 1)
	{
		philo->state = PHILO_STATE_DEAD;
		print_message(philo, philo->state);
	}
	return (philo);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = data->philo;
	while (1)
	{
		if (ft_get_time() - philo->last_meal_time >= philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->state = PHILO_STATE_DEAD;
			print_message(philo, philo->state);
			pthread_mutex_unlock(&philo->data->lock);
		}
	}
	return (arg);
}
