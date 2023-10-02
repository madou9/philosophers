/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/10/02 14:15:59 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_dead(t_philo *philo)
{
	int		i;
	long	time_last_meal;

	i = 0;
	while (i < philo->data->phil_nbr)
	{
		pthread_mutex_lock(&philo->data->last_meal);
		time_last_meal = philo->last_meal_time;
		pthread_mutex_unlock(&philo->data->last_meal);
		if (ft_get_time() - time_last_meal >= philo->death_time)
		{
			print_message(DIED, &philo[i], philo[i].id);
			pthread_mutex_lock(&philo->data->lock);
			philo->data->philo_died = 1;
			pthread_mutex_unlock(&philo->data->lock);
			return (1);
		}
		i++;
	}
	return (0);
}
