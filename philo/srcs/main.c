/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:52:09 by ihama             #+#    #+#             */
/*   Updated: 2023/09/06 17:26:02 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		i;

	if (argc != 5 && argc != 6)
		error_message("Error: more or less argument provied");
	i = 1;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit(1);
	while (i < argc)
	{
		if (!ft_check_number(argv[i]))
			error_message("Error: Numeric argument required");
		i++;
	}
	ft_init_data(data, argc, argv);
	ft_create_each_philo(data);
	return (0);
}
