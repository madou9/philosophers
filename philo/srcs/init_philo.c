/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:05 by ihama             #+#    #+#             */
/*   Updated: 2023/09/25 20:18:44 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fork_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_nbr)
	{
		pthread_mutex_init(&data->philo[i].own_fork, NULL);
		++i;
	}
	i = 0;
	while (i < data->phil_nbr)
	{	
		if (i == data->phil_nbr - 1)
			data->philo[i].neibor_fork = &data->philo[0].own_fork;
		else
			data->philo[i].neibor_fork = &data->philo[i + 1].own_fork;
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
	if (argv[5])
		data->max_to_eat = ft_atoi(argv[5]);
	else
		data->max_to_eat = INT_MAX;
	data->th_id = malloc(sizeof(pthread_t) * data->phil_nbr);
	data->philo = malloc(sizeof(t_philo) * data->phil_nbr);
	if (!data->th_id || !data->philo)
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
		data->philo[i].death_time = data->time_to_die;
		data->philo[i].last_meal_time = data->start_time;
	}
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->wait_print, NULL);
	pthread_mutex_init(&data->last_meal, NULL);
	return (0);
}

int	ft_create_each_philo(t_data *data)
{
	int			i;
	pthread_t	observer;

	i = -1;
	data->start_time = ft_get_time();
	while (++i < data->phil_nbr)
	{
		if (pthread_create(&data->th_id[i], NULL, &routine, &data->philo[i]) != 0)
			cleanup(data);
	}
	if (pthread_create(&observer, NULL, &monitor, data) != 0)
		cleanup(data);
	i = 0;
	while (i < data->phil_nbr)
	{
		if (pthread_join(data->th_id[i], NULL) != 0)
			cleanup(data);
		i++;
		// printf("here: ft_create_each_philo\n");
	}
	if (pthread_join(observer, NULL) != 0)
		cleanup(data);
	return (0);
}
