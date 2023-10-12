/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:53:03 by ihama             #+#    #+#             */
/*   Updated: 2023/10/10 11:24:32 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_get_time(void)
{
	struct timeval	time_val;

	if (gettimeofday(&time_val, NULL))
		return (1);
	return ((time_val.tv_sec * 1000) + (time_val.tv_usec / 1000));
}

int	ft_usleep(useconds_t usec)
{
	long	before;
	long	after;

	before = ft_get_time();
	after = before + usec;
	while (ft_get_time() < after)
	{
		if (usleep(50) == -1)
			return (-1);
	}
	return (0);
}
