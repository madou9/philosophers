/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:51:27 by ihama             #+#    #+#             */
/*   Updated: 2023/09/13 22:32:44 by ihama            ###   ########.fr       */
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

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

typedef struct s_philo
{
	struct s_data	*data;
	long int		last_meal_time;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				id;
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
	pthread_mutex_t	*fork;
	pthread_mutex_t	wait_to_print;
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
void		print_message(char *str, t_philo *philo);

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

int	check_dead(t_philo *philo, long int time);
#endif
