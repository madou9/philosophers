/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:09 by ihama             #+#    #+#             */
/*   Updated: 2023/09/24 14:09:05 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error(void)
{
	write (2, "Error: more or less argument provied", 36);
	exit(1);
}

int	ft_check_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error();
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (argc != 5 && argc != 6)
		error();
	ft_check_number(argc, argv);
	i = 1;
	data = malloc(sizeof(t_data));
	data->philo_died = 0;
	ft_init_data(data, argv);
	ft_init_philo(data);
	ft_fork_init(data);
	ft_create_each_philo(data);
	cleanup(data);
	return (0);
}
