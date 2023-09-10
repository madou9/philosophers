/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:18:06 by ihama             #+#    #+#             */
/*   Updated: 2023/09/10 17:14:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(char *str, t_philo *philo)
{
	long int	timestamp;

	timestamp = ft_get_time() - philo->start_time;
	pthread_mutex_lock(philo->wait_to_print);
	printf("%ld %d %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(philo->wait_to_print);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken fork", philo);
	ft_usleep(philo->time_to_die);
	return ;
}

void	ft_think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

int	ft_eat_meal(t_philo *philo)
{
	if (philo->phil_nbr == 1)
	{
		one_philo(philo);
		return (1);
	}
	pthread_mutex_lock(philo->wait_to_eat);
	ft_take_fork(philo);
	philo->eating = 1;
	print_message("Is eating", philo);
	philo->last_meal = ft_get_time();
	philo->is_eating++;
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->wait_to_eat);
	drop_fork(philo);
	return (0);
}
