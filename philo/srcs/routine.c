/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/24 19:20:20 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_someone_died(t_philo *philo)
{
	// printf("check\n");
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->philo_died == 1)
		return (pthread_mutex_unlock(&philo->data->lock), 1);
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_data		*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while ((philo->data->max_to_eat > philo->last_eat)
		&& philo->data->phil_nbr != 1)
	{
		ft_eat_meal(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	if (philo->data->phil_nbr == 1)
		print_message(DIED, philo, philo->id);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int i = -1;

	data = (t_data *)arg;
	philo = data->philo;
	while (i++ < philo->data->phil_nbr && philo->data->philo_died == 0)
	{
		// printf("nombre philo : %ld\n", philo->data[0].phil_nbr);
		pthread_mutex_lock(&philo->data->wait_print);
		if (ft_get_time() - philo->last_meal_time >= philo->death_time)
		{
			pthread_mutex_unlock(&philo->data->wait_print);
			pthread_mutex_lock(&philo->data->wait_print);
			philo->data->philo_died = 1;
			print_message(DIED, philo, philo->id);
			pthread_mutex_unlock(&philo->data->wait_print);
			break ;
		}
		pthread_mutex_unlock(&philo->data->wait_print);
	}
	return (NULL);
}
