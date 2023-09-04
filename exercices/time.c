/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:11:32 by ihama             #+#    #+#             */
/*   Updated: 2023/09/04 19:19:50 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf
#include <sys/time.h> // time
#include <stdint.h> // uint64_t
#include <unistd.h> // usleep
#include <stdlib.h> // usleep

// struct timeval {
//     time_t      tv_sec;     // seconds
//     suseconds_t tv_usec;    // microseconds
// };

//int gettimeofday(struct timeval *tv, struct timezone *tz);

uint64_t	get_time(void) // returns time in milliseconds
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void    example_1()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    printf("%ld seconds\n", time.tv_sec);
    printf("%d macroseconds\n", time.tv_usec);
    printf("\n%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
}

void    example_2()
{
    uint64_t    start_time;
    uint64_t    now;

    start_time = get_time();
    usleep(10000); // accepts in microseconds
    now = get_time();
    printf("%llu milliseconds passed since the start\n", now - start_time);
}

int main()
{
    //example_1();
    example_2();

    return (0);
}
