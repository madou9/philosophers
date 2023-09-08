/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:07 by ihama             #+#    #+#             */
/*   Updated: 2023/09/08 22:34:36 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	t_data		*context;
	int			i;

	i = 0;
	philo = (t_philo *)arg;
	context = philo->data;
	while (i < context->max_to_eat)
	{
		print_message("is thinking", philo);
		ft_eat_meal(philo);
		drop_fork(philo);
		ft_check_die(philo);
		i++;
	}
	return (NULL);
}
