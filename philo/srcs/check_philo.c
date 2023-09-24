/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/09/24 20:45:47 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->last_meal);
	if (ft_get_time() - philo->last_meal_time >= philo->death_time)
		return (pthread_mutex_unlock(&philo->data->last_meal), 1);
	pthread_mutex_unlock(&philo->data->last_meal);
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int i = -1;

	data = (t_data *)arg;
	philo = data->philo;
	while (i++ < philo->data->phil_nbr)
	{
		if (check_dead(philo))
		{
			printf("nombre philo");
			print_message(DIED, &philo[i], philo->id);
			pthread_mutex_lock(&philo->data->lock);
			philo->data->philo_died = 1;
			pthread_mutex_unlock(&philo->data->lock);
		}
	}
	return (arg);
}
