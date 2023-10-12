/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:09 by ihama             #+#    #+#             */
/*   Updated: 2023/10/10 11:42:08 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	error_1(void)
{
	write (2, "Error: The project said no more than 200 philosophers!\n", 55);
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

// void	leaks(void)
// {
// 	system("leaks philo");
// }
// 	atexit(&leaks);


int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		error();
	if (ft_atoi(argv[1]) > 200)
		error_1();
	ft_check_number(argc, argv);
	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	data->philo_died = 0;
	ft_init_data(data, argv);
	ft_init_philo(data);
	ft_fork_init(data);
	ft_create_each_philo(data);
	cleanup(data);
	return (0);
}
