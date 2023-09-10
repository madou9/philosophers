/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:09 by ihama             #+#    #+#             */
/*   Updated: 2023/09/10 18:45:22 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	t_data			data;
	int				i;

	i = 1;
	if (argc != 5 && argc != 6)
		error_message("Error: more or less argument provided");
	while (i < argc)
	{
		if (!ft_check_number(argv[i]))
			error_message("Error: NUmeric argument required");
		i++;
	}
	ft_init_data(philo, argc, argv);
	init_data(&data, philo);
	ft_init_philo(philo, &data);
	ft_fork_init(philo, forks);
	ft_create_thread(&data);
	cleanup(&data, forks);
	return (0);
}
