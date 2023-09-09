/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:03:15 by ihama             #+#    #+#             */
/*   Updated: 2023/09/09 14:26:51 by ihama            ###   ########.fr       */
/*                             `                                               */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_die(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->wait_to_print);
	if (check_if_someone_died(philo) == 1)
	{
		print_message("has died", philo);
		philo->data->philo_died = 1;
	}
	// pthread_mutex_unlock(&philo->data->wait_to_print);
}

int	check_if_someone_died(t_philo *philo)
{
	if (ft_get_time() - philo->data->time_to_die > philo->last_meal_time)
		return (1);
	return (0);
	// if (ft_get_time() > philo->data->time_to_die) // 600
}

	// printf("\ntime_to_die: %ld\n", philo->data->time_to_die);
	// printf("\time_since_last_meal: %ld\n", time_since_last_meal);
