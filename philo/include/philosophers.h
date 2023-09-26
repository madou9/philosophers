/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:51:27 by ihama             #+#    #+#             */
/*   Updated: 2023/09/26 20:20:00 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef struct s_philo
{
	struct s_data	*data;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*neibor_fork;
	long int		last_meal_time;
	int				id;
	long			death_time;
	int				state;
	int				eating;
	int				last_eat;
}	t_philo;

typedef struct s_data
{
	long long		start_time;
	pthread_t		*th_id;
	pthread_t		*ckeck_vie;
	pthread_mutex_t	lock;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	wait_print;
	int				flag;
	int				philo_died;
	long int		time_to_eat;
	long int		max_to_eat;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		phil_nbr;
	t_philo			*philo;
}					t_data;

/*time thread */
long int	ft_get_time(void);
int			ft_usleep(useconds_t usec);

/*init thread*/
int			ft_fork_init(t_data *data);
int			ft_init_data(t_data *data, char **argv);
int			ft_init_philo(t_data *data);

/*action routine */
void		*routine(void *arg);
int			ft_create_each_philo(t_data *data);
void		ft_eat_meal(t_philo *philo);
void		print_message(char *str, t_philo *philo, int id);

/*take fork */
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);

/*tools thread */
void		cleanup(t_data *data);
int			ft_atoi(char *str);
int			ft_isdigit(int c);

void		*monitor(void *pointer);
int			ft_check_number(int argc, char **argv);
int	check_someone_died(t_philo *philo);
int	check_dead(t_philo *philo, long int time_to_die);
int	check_if_dead(t_philo *philos);
#endif
