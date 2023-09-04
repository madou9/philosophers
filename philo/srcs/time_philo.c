/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:53:03 by ihama             #+#    #+#             */
/*   Updated: 2023/09/04 19:41:10 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// ft_get_time is a function that returns the current time in milliseconds 
// using the gettimeofday function, which is a function that returns the current
// time in seconds and microseconds. We multiply the seconds by 1000 to get the
// time in milliseconds, and then divide the microseconds by 1000 to get the
// time in milliseconds.
long int	ft_get_time(void)
{
	struct timeval	valu_time;

	if (gettimeofday(&valu_time, NULL))
		return (1);
	return ((valu_time.tv_sec * (uint64_t)1000) + (valu_time.tv_usec / 1000));
}
