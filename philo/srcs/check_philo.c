/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/09/15 19:41:22 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Checks if the philosopher is dead

int	philosopher_dead(t_philo *philo, long int time_to_die)
{
	if (ft_get_time() - philo->last_eat >= time_to_die && philo->eating == 0)
		return (pthread_mutex_lock(&philo->lock), 1);
	pthread_mutex_lock(&philo->lock);
	return (0);
}
// Check if any philo died

int	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->phil_nbr)
	{
		if (philosopher_dead(&philo[i], philo[i].data->time_to_die))
		{
			pthread_mutex_lock(&philo[0].lock);
			philo->philo_died = 1;
			philo->state = PHILO_STATE_DEAD;
			print_message(philo, philo->state);
			pthread_mutex_unlock(&philo[0].lock);
			return (0);
		}
		i++;
	}
	return (0);
}

// Checks if all the philos ate the num_of_meals

int	check_if_all_ate(t_philo *philo)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philo->data->max_to_eat == -1)
		return (0);
	while (i < philo[0].data->phil_nbr)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->last_eat < philo->data->max_to_eat)
			finished_eating++;
		pthread_mutex_unlock(&philo[i].lock);
		i++;
	}
	if (finished_eating == philo[0].data->phil_nbr)
	{
		pthread_mutex_lock(&philo->lock);
		philo->philo_died = 1;
		return (1);
		pthread_mutex_unlock(&philo->lock);
	}
	return (0);
}


void	*monitor(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (pointer);
}
