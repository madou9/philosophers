/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:05 by ihama             #+#    #+#             */
/*   Updated: 2023/09/10 18:17:02 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_data(t_philo *philo, char **argv)
{
	philo->phil_nbr = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_to_eat = ft_atoi(argv[5]);
	else
		philo->num_to_eat = INT_MAX;
	return (0);
}

int	ft_fork_init(t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < philo->phil_nbr)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo->phil_nbr)
	{
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[(i + 1) % philo->phil_nbr];
		++i;
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
		philo[i].is_eating = 0;
		philo[i].start_time = ft_get_time();
		philo[i].last_meal = ft_get_time();
		philo[i].philo_dead = data->dead_flag;
		philo[i].wait_to_print = &data->wait_to_print;
		philo[i].wait_to_eat = &data->wait_to_eat;
		philo[i].death_lock = &data->death_lock;
		i++;
	}
}

int	ft_create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo->phil_nbr)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
			&routine, &data->philo[i]) != 0)
			return (1);
	}
	i = 0;
	while (i < data->philo[0].phil_nbr)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
