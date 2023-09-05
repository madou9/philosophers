/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:05 by ihama             #+#    #+#             */
/*   Updated: 2023/09/05 15:53:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_fork_init(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->phil_nbr);
	if (!data)
		exit(1);
	while (i < data->phil_nbr)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	data->philo[0].left_fork = &data->fork[0];
	data->philo[0].right_fork = &data->fork[data->phil_nbr - 1];
	i = 1;
	while (i < data->phil_nbr)
	{
		data->philo[i].left_fork = &data->fork[i];
		data->philo[i].right_fork = &data->fork[i - 1];
		++i;
	}
	return (0);
}

int	ft_init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	data->phil_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	if (argc == 6)
		data->max_to_eat = ft_atoi(argv[5]);
	else
		data->max_to_eat = -1;
	data->th_id = malloc(sizeof(pthread_t) * data->phil_nbr);
	data->philo = malloc(sizeof(t_philo) * data->phil_nbr);
	while (i < data->phil_nbr)
	{
		data->philo[i].data = data;
		i++;
	}


	if (!data->th_id || !data->philo)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_take_fork(t_philo *philo)
{
	long long timestamp;

	timestamp = ft_get_time() - philo->data->start_time;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%llu Philosopher %d has picked up the left for\n", timestamp, philo->id);
		pthread_mutex_lock(philo->left_fork);
		printf("%llu Philosopher %d has picked up the right for\n", timestamp, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%llu Philosopher %d has picked up the left for\n", timestamp, philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%llu Philosopher %d has picked up the right for\n", timestamp, philo->id);
	}
}

void	ft_unlock_fork(t_philo *philo)
{
	long long timestamp;

	timestamp = ft_get_time() - philo->data->start_time;
	pthread_mutex_unlock(philo->left_fork);
	printf("%llu Philosopher %d has put down the left fork\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->right_fork);
	printf("%llu Philosopher %d has put down the right fork\n", timestamp, philo->id);
}

void	ft_eat_meal(t_philo *philo)
{
	long long	timestamp;

	timestamp = ft_get_time() - philo->data->time_to_eat;
	printf("%llu Phlosopher %d is eating\n", timestamp, philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	long long timestamp;

	timestamp = ft_get_time() - philo->data->start_time;
	while (i < 5)
	{
		// Think (simulate thinking activity)
		printf("%s %llu Philosopher %d is thinking\n", YELLOW, timestamp, philo->id);
		// Pick up forks (mutex locks)
		ft_take_fork(philo);
		// Eat
		ft_eat_meal(philo);
		// Put down forks (release mutex locks)
		ft_unlock_fork(philo);
		// Sleep (simulate sleeping activity)
		printf("Philosopher %d is sleeping\n", philo->id);
		ft_usleep(1000);
		i++;
	}
	return (NULL);
}

int	ft_create_each_philo(t_data *data)
{
	int		i;

	i = 0;
	ft_fork_init(data);
	while (i < data->phil_nbr)
	{
		data->philo[i].id = i + 1;
		if (pthread_create(&data->th_id[i], NULL, &routine, &data->philo[i]))
			cleanup(data);
		i++;
	}
	i = 0;
	while (i < data->phil_nbr)
	{
		if (pthread_join(data->th_id[i], NULL) != 0)
			return (2);
		printf("thread %d has finished execution\n", i);
		i++;
		sleep(1);
	}
	printf("Num: %lld\n", data->start_time);
	cleanup(data);
	return (0);
}
