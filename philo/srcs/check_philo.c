/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:33 by ihama             #+#    #+#             */
/*   Updated: 2023/09/25 20:30:50 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_philo *philo, long time_to_die)
{
	pthread_mutex_lock(&philo->data->last_meal);
	if (ft_get_time() - philo->last_meal_time >= time_to_die)
		return (pthread_mutex_unlock(&philo->data->last_meal), 1);
	pthread_mutex_unlock(&philo->data->last_meal);
	return (0);
}

// Check if any philo died
int	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->phil_nbr)
	{
		if (check_dead(philo, philo[i].data->time_to_die))
		{
			print_message(DIED, philo, philo[i].id);
			pthread_mutex_lock(&philo[0].data->wait_print);
			philo->data->philo_died = 1;
			pthread_mutex_unlock(&philo[0].data->wait_print);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = data->philo;
	while (1)
	{
		if (check_if_dead(philo) == 1)
			break ;
	}
	return (arg);
}

// // Check if any philo died
// int	check_if_dead(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philo->data->phil_nbr)
// 	{
// 		if (check_dead(&philo[i], philo[i].data->time_to_die))
// 		{
// 			print_message(DIED, &philo[i], philo[i].id);
// 			pthread_mutex_lock(&philo[i].data->wait_print);
// 			philo->data->philo_died = 1;
// 			pthread_mutex_unlock(&philo[i].data->wait_print);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
