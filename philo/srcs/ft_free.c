/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:35:55 by ihama             #+#    #+#             */
/*   Updated: 2023/09/26 15:11:36 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_nbr)
	{
		pthread_mutex_destroy(&data->philo[i].own_fork);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->wait_print);
	pthread_mutex_destroy(&data->last_meal);
	free(data->th_id);
	free(data->philo);
}
