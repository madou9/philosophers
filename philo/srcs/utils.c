/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:03:15 by ihama             #+#    #+#             */
/*   Updated: 2023/09/08 23:27:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	ft_check_die(t_philo *philo)
{
	t_data	*data;
	data = philo->data;
	int	terminate;

	terminate = 0;
	philo->last_meal_time = ft_get_time() - philo->data->start_time;
	// printf("\nreal time: %ld", ft_get_time());
	// printf("\nstart_time: %lld", philo->data->start_time);
	// printf("\nlast_meal_time: %ld\n", philo->last_meal_time);
	// printf("\ntime_to_die: %ld\n", data->time_to_die);
	// while (terminate == 0)
	// {
		pthread_mutex_lock(&philo->lock);
		if (ft_get_time() >= data->time_to_die)
		{
			print_message("has died", philo);
			exit(0);
			return (true);
		}
		return (false);
		terminate = data->philo_died;
	// }
}

// bool	ft_check_eat(t_philo *philo)
// {
// 	if (ft_get_time() >= philo->last_meal_time)
// 	{
// 		print_message("has died", philo);
// 		return (true);
// 	}
// 	return (false);
// }
