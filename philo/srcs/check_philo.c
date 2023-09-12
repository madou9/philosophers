/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/09/12 18:44:22 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_if_dead(t_philo *philo, int number_philo)
{
    int i;

    i = 0;
    pthread_mutex_lock(philo[i].wait_to_print);
    pthread_mutex_lock(philo[i].general);
    while(i < number_philo)
    {
        if(ft_get_time() - philo[i].last_meal >= philo[i].time_to_die)
        {
            philo[i].philo_dead = 1;
            pthread_mutex_unlock(philo[i].general);
            pthread_mutex_unlock(philo[i].wait_to_print);
            return (1);
        }
        i++;
    }
    pthread_mutex_unlock(philo[i].general);
    pthread_mutex_unlock(philo[i].wait_to_print);
    return (0);
}

int check_flag_died(t_philo *philo)
{
    int i;

    i= 0;
    pthread_mutex_lock(philo[i].wait_to_print);
    pthread_mutex_lock(philo[i].general);
    while (i < philo[0].phil_nbr)
    {
        if (philo[i].philo_dead == 1)
        {
            pthread_mutex_unlock(philo[i].general);
            pthread_mutex_unlock(philo[i].wait_to_print);
            return (1);
        }
        i++;   
    }
    pthread_mutex_unlock(philo[i].general);
    pthread_mutex_unlock(philo[i].wait_to_print);
    return (0);
}
