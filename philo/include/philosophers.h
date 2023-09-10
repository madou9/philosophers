/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:51:27 by ihama             #+#    #+#             */
/*   Updated: 2023/09/10 19:01:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include "../libft/libft.h"

# define PHILO_MAX 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				is_eating;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		start_time;
	long int		last_meal;
	int				phil_nbr;
	long int		num_to_eat;
	int				philo_dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*wait_to_print;
	pthread_mutex_t	*wait_to_eat;

}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	*fork;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	wait_to_print;
	pthread_mutex_t	wait_to_eat;
	t_philo			*philo;
}					t_data;

/* tool*/
int		ft_check_number(char *str);
void	error_message(char *msg);
void	cleanup(t_data *data, pthread_mutex_t *fork);

/*init philo */
int		ft_init_data(t_philo *philo, int argc, char **argv);
void	ft_init_philo(t_philo *philo, t_data *data);
int		ft_fork_init(t_philo *philo, pthread_mutex_t *fork);
int		ft_create_thread(t_data *data);
void	init_data(t_data *data, t_philo *philo);
int		check_if_someone_died(t_philo *philo);

/* routine */
void	*routine(void *arg);
void	one_philo(t_philo *philo);
void	print_message(char *str, t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
int		ft_eat_meal(t_philo *philo);

/*take fork*/
void	drop_fork(t_philo *philo);
int		take_right_fork(t_philo *philo);
int		take_left_fork(t_philo *philo);
int		ft_take_fork(t_philo *philo);

/*time and usleep*/
int		ft_usleep(useconds_t usec);
long	int	ft_get_time(void);

#endif