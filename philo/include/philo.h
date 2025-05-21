/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/21 12:01:09 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # define RED "\033[31m"
// # define GREEN "\033[32m"
// # define YELLOW "\033[33m"
// # define BLUE "\033[34m"
// # define RESET "\033[0m"

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

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
	pthread_mutex_t	mu_fork_l;
	pthread_mutex_t	mu_fork_r;
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
	bool			have_fork_l;
	bool			have_fork_r;
	size_t			timer_to_die;
	size_t			timer_to_eat;
	size_t			timer_to_sleep;
	int				nb_eaten;
}					t_philo;

//==================exit===============================//

void				p_error_usage(void);
void				destroy_and_free(t_philo *philo);

//==================parsing============================//

int					parsing(t_data data);

//==================init===============================//

t_philo				*init_main(t_data *data);

//==================routine============================//

void				*routine(void *arg);
void				print_logs(t_philo *philo, t_logs log);

//==================routine_utils======================//

int					all_philo_alive(t_philo *philo);
int					finished_eating(t_philo *philo);
void				think(t_philo *philo, size_t nb_time_waiting);
void				eat(t_philo *philo);
void				ft_sleep(t_philo *philo);

//==================routine_utils_fork=================//

void				put_down_fork(t_philo *philo);
int					take_fork_l(t_philo *philo);
int					take_fork_r(t_philo *philo);
int					take_forks(t_philo *philo);

#endif