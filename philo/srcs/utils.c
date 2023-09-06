/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:03:15 by ihama             #+#    #+#             */
/*   Updated: 2023/09/06 20:05:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_die(t_philo *philo)
{
	philo->last_meal_time = ft_get_time() - philo->data->start_time;
	if (ft_get_time() - philo->last_meal_time > philo->data->time_to_die)
		print_message("has died", philo);
}

void	ft_check_die(t_philo *philo)
{
	philo->last_meal_time = ft_get_time() - philo->data->start_time;
	if ((philo->data->time_to_eat + philo->data->time_to_sleep) < philo->data->time_to_die)
	{
		ft_eat_meal(philo);
		
	}
}