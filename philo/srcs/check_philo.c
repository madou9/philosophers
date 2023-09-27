/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/09/27 12:04:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_dead(t_philo *philo)
{
	int		i;
	long	t;
	t_data	*data;

	i = 0;
	data = philo->data;
	while (i < philo->data->phil_nbr)
	{
		pthread_mutex_lock(&philo->data->wait_print);
		t = philo->last_meal_time;
		pthread_mutex_unlock(&philo->data->wait_print);
		if (ft_get_time() - t >= philo->data->time_to_die && philo->eating == 0)
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
