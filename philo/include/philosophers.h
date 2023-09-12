/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:51:27 by ihama             #+#    #+#             */
/*   Updated: 2023/09/12 19:27:24 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	pthread_t		thread;
	// pthread_t		thread_1;
	int				id;
	int				finished;
	int				eating;
	int				last_eat;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		start_time;
	long int		last_meal;
	int				phil_nbr;
	int				num_to_eat;
	int				philo_dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*wait_to_print;
	pthread_mutex_t	*lock;

}					t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	*fork;
	pthread_mutex_t	wait_to_print;
	t_philo			*philo;
}					t_data;

/* tool*/
int		ft_check_number(char *str);
void	cleanup(t_data *data, pthread_mutex_t *fork);

/*init philo */
int		ft_init_data(t_philo *philo, int argc, char **argv);
void	ft_init_philo(t_philo *philo, t_data *data);
int		ft_fork_init(t_philo *philo, pthread_mutex_t *fork);
int		ft_create_thread(t_data *data);
int		ft_create_join(t_data *data);
void	init_data(t_data *data, t_philo *philo);

/*check died */

/* routine */
void	*routine(void *arg);
void	*routine_1(void *arg);
void	one_philo(t_philo *philo);
void	print_message(char *str, t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
int		ft_eat_meal(t_philo *philo);

/*take fork*/
void	drop_fork(t_philo *philo);

/*time and usleep */

int		ft_usleep(useconds_t usec);
long	int	ft_get_time(void);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif