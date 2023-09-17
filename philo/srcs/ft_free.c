/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:35:55 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 13:32:25 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_nbr)
	{
		pthread_mutex_destroy(&data->philo[i].own_fork);
		pthread_mutex_destroy(&data->philo->lock);
		i++;
	}
	free(data->th_id);
	free(data->philo);
}
