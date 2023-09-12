/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:05 by ihama             #+#    #+#             */
/*   Updated: 2023/09/12 19:50:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_data(t_philo *philo, int argc, char **argv)
{
	philo->phil_nbr = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->num_to_eat = ft_atoi(argv[5]);
	else
		philo->num_to_eat = INT_MAX;
	philo->finished = 0;
	return (0);
}

int	ft_fork_init(t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < philo->phil_nbr)
		pthread_mutex_init(&fork[i], NULL);
	i = 0;
	philo[0].left_fork = &fork[0];
	philo[0].right_fork = &fork[philo->phil_nbr - 1];
	while (++i < philo->phil_nbr)
	{
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[i - 1];
	}
	return (0);
}

void	ft_init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->phil_nbr)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].last_eat = 0;
		philo[i].start_time = ft_get_time();
		philo[i].last_meal = ft_get_time();
		philo[i].philo_dead = data->dead_flag;
		philo[i].wait_to_print = &data->wait_to_print;
		++i;
	}
}

int	ft_create_thread(t_data *data)
{
	int	i;
	pthread_t	observer;

	i = 0;
	if (pthread_create(&data->philo->thread_1, NULL, routine_1, data->philo)!= 0)
		return (1);
	while (i < data->philo[0].phil_nbr)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
			&routine, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo[0].phil_nbr)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	// if (pthread_join(data->philo->thread_1, NULL) != 0)
	// 	return (1);
	return (0);
}
