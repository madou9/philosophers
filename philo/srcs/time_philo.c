/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:53:03 by ihama             #+#    #+#             */
/*   Updated: 2023/09/25 15:14:13 by ihama            ###   ########.fr       */
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

	gettimeofday(&valu_time, NULL);
	return ((valu_time.tv_sec * 1000) + (valu_time.tv_usec / 1000));
}

// ft_usleep is a function that sleeps for a specified amount of time.
// It takes a time in microseconds (time) as an argument and delays the
// execution of the program for that amount of time. It returns 0.

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
