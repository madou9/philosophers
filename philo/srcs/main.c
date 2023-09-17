/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:09 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 10:40:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		i;

	if (argc != 5 && argc != 6)
		write (2,"Error: more or less argument provied", 1);
	i = 1;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit(1);
	while (i < argc)
	{
		if (!ft_check_number(argv[i]))
			write(2,"Error: Numeric argument required", 1);
		i++;
	}
	ft_init_data(data, argv);
	ft_init_philo(data);
	ft_fork_init(data);
	ft_create_each_philo(data);
	cleanup(data);
	return (0);
}
