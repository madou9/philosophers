/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:05 by ihama             #+#    #+#             */
/*   Updated: 2023/09/13 22:31:50 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fork_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_nbr)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	data->philo[0].left_fork = &data->fork[0];
	data->philo[0].right_fork = &data->fork[0];
	i = 0;
	while (i < data->phil_nbr)
	{
		data->philo[i].left_fork = &data->fork[i];
		data->philo[i].right_fork = &data->fork[(i + 1) % data->phil_nbr];
		++i;
	}
	return (0);
}

int	ft_init_data(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->phil_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	if (argv[5])
		data->max_to_eat = ft_atoi(argv[5]);
	else
		data->max_to_eat = INT_MAX;
	pthread_mutex_init(&data->wait_to_print, NULL);
	data->th_id = malloc(sizeof(pthread_t) * data->phil_nbr);
	data->philo = malloc(sizeof(t_philo) * data->phil_nbr);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->phil_nbr);
	if (!data->th_id || !data->philo || !data->fork)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->phil_nbr)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].eating = 0;
		data->philo[i].last_eat = 0;
		data->philo[i].philo_died = 0;
		data->philo[i].last_meal_time = data->start_time;
		pthread_mutex_init(&data->philo->lock, NULL);
	}
	return (0);
}

int	ft_create_each_philo(t_data *data)
{
	int			i;
	// long int	time;

	i = 0;
	while (i < data->phil_nbr)
	{
		if (pthread_create(&data->th_id[i], NULL, &routine, &data->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	// while (!data->philo[i % data->phil_nbr].philo_died && data->philo->last_eat)
	// {
	// 	time = ft_get_time() - data->philo[i % data->phil_nbr].last_eat;
	// 	if (check_dead(&data->philo[i % data->phil_nbr], time))
	// 		check_if_someone_died(&data->philo[i % data->phil_nbr]);
	// }
	while (i < data->phil_nbr)
	{
		if (pthread_join(data->th_id[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
