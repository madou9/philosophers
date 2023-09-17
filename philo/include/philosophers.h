/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:51:27 by ihama             #+#    #+#             */
/*   Updated: 2023/09/15 19:42:04 by ihama            ###   ########.fr       */
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

#define PHILO_STATE_EATING 1
#define PHILO_STATE_SLEEPING 2
#define PHILO_STATE_THINKING 3
#define PHILO_STATE_DEAD 4

typedef struct s_philo
{
	struct s_data	*data;
	long int		last_meal_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	wait_to_print;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*neibor_fork;
	int				id;
	int				state;
	int				philo_died;
	int				eating;
	int				last_eat;
}	t_philo;

typedef struct s_data
{
	long long		start_time;
	pthread_t		*th_id;
	pthread_t		*ckeck_vie;
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
void		check_if_someone_died(t_philo *philo);
void		*routine(void *arg);
int			ft_create_each_philo(t_data *data);
void		ft_eat_meal(t_philo *philo);
void		print_message(t_philo *philo, int state);

/*take fork */
void		drop_fork(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);

/*tools thread */
int			ft_check_number(char *str);
void		cleanup(t_data *data);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
void 		ft_take_fork(t_philo *philo);

int			check_if_all_ate(t_philo *philo);
int			philosopher_dead(t_philo *philo, long int time_to_die);
int			check_if_dead(t_philo *philo);
void		*monitor(void *pointer);
#endif
