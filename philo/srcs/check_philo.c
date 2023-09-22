/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/09/22 15:33:01 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_someone_died(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (ft_get_time() - philo->last_meal_time >= philo->data->time_to_die)
	{
		philo->state = PHILO_STATE_DEAD;
		print_message(philo, philo->state);
	}
	return (0);
}
