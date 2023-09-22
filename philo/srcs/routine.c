/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/22 20:24:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_someone_died(t_philo *philo)
{
	printf("check\n");
	pthread_mutex_lock(&philo->data->lock);
	if (philo->philo_died == 1)
	{
		printf("philo dead\n");
		pthread_mutex_unlock(&philo->data->lock);
		pthread_exit(NULL);
	}
	pthread_mutex_unlock(&philo->data->lock);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while ((philo->data->max_to_eat > philo->last_eat)
		&& philo->data->phil_nbr != 1)
	{
		check_someone_died(philo);
		ft_eat_meal(philo);
		check_someone_died(philo);
		ft_sleep(philo);
		check_someone_died(philo);
		ft_think(philo);
		check_someone_died(philo);
	}
	if (philo->data->phil_nbr == 1)
	{
		philo->state = PHILO_STATE_DEAD;
		print_message(philo, philo->state);
	}
	return (philo);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int i = -1;

	data = (t_data *)arg;
	philo = data->philo;
	pthread_mutex_lock(&philo->data->lock);
	while (++i < philo->data->phil_nbr)
	{
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->data->lock);
		if (ft_get_time() - philo->last_meal_time >= philo->data->time_to_die)
		{
			philo->state = PHILO_STATE_DEAD;
			philo->philo_died = 1;
			print_message(philo, philo->state);
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->data->lock);
	}
	return (arg);
}
