/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/19 13:14:22 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef enum e_logs
{
	FORK,
	EAT,
	SLEEP,
	THINKING,
	DIE
}					t_logs;

typedef struct s_data
{
	int				argc;
	char			**argv;
	int				nb_philo;
	int				nb_philo_init;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	size_t			timer;
	int				dead;
	pthread_mutex_t	mu_time;
	pthread_mutex_t	mu_dead;
	pthread_mutex_t	mu_init;
	pthread_mutex_t	mu_eat;
	pthread_mutex_t	mu_eaten;
	int				nb_all_eaten;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	pthread_t		pt;
	bool			fork_l;
	bool			*fork_r;
	pthread_mutex_t	mu_fork_l;
	pthread_mutex_t	*mu_fork_r;
	bool			have_fork_l;
	bool			have_fork_r;
	size_t			timer_to_die;
	size_t			timer_to_eat;
	size_t			timer_to_sleep;
	int				nb_eaten;
	bool			done;
}					t_philo;

//==================exit===============================//

void				destroy_and_free(t_philo *philo);

//==================init_utils=========================//

void				init_mutex(t_data *data);
int					join_threads(t_philo *philo, int init);
int					init_threads(t_philo *philo);

//==================init===============================//

void				init_data(t_data *data);
t_philo				*init_philo(t_data *data);
t_philo				*init_main(t_data *data);

//==================parsing============================//

int					parsing(t_data data);

//==================print==============================//

void				p_error_usage(void);
void				print_logs(t_philo *philo, t_logs log);
void				print_end(void);

//==================routine============================//

void				*routine(void *arg);

//==================routine_utils======================//

int					all_philo_alive(t_philo *philo);
int					finished_eating(t_philo *philo);
void				think(t_philo *philo, size_t nb_time_waiting);
void				eat(t_philo *philo);
void				ft_sleep(t_philo *philo);

//==================routine_utils_fork=================//

void				put_down_fork(t_philo *philo);
int					take_forks(t_philo *philo);

#endif