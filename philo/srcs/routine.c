/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/13 22:02:01 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_someone_died(t_philo *philo)
{
	long int	time;

	time = ft_get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->lock);
	printf("%ld %d dead\n", time, philo->id);
	philo->philo_died = 1;
	pthread_mutex_unlock(&philo->lock);
	// return (0);
}

int	check_dead(t_philo *philo, long int time)
{
	if (time > philo->data->time_to_die)
	{
		check_if_someone_died(philo);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (philo->last_eat < philo->data->max_to_eat)
	{
		ft_eat_meal(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}
