/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:51:27 by ihama             #+#    #+#             */
/*   Updated: 2023/09/04 19:50:49 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "../libft/libft.h"

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

typedef struct s_philo
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long int		start_time;
	pthread_t		*th_id;
	int				time_to_eat;
	int				die;
	int				eat;
	int				sleep;
	int				phil_nbr;
	t_philo			*philo;
	pthread_mutex_t	*fork;
}					t_data;

long int	ft_get_time(void);
int			ft_fork_init(t_data *data);
int			ft_check_number(char *str);
int			ft_init_data(t_data *data, int argc, char **argv);
void		error_message(char *msg);
void		*routine(void *arg);
int			ft_create_each_philo(t_data *data);
void		cleanup(t_data *data);
void		ft_take_fork(t_philo *philo);
void		ft_unlock_fork(t_philo *philo);

#endif
