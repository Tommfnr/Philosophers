/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 15:05:53 by tfournie         ###   ########.fr       */
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
# include <sys/time.h>
# include <unistd.h>

typedef enum e_output
{
	ERROR = 1,
	VALID = 0
}					t_output;

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
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_time_eat;
	size_t			timer;
	bool			dead;

}					t_data;

typedef struct s_philo
{
	t_data			data;
	int				id;
	pthread_t		pt;
	bool			fork_l;
	bool			*fork_r;
	size_t			timer_to_die;
	size_t			timer_to_eat;
	size_t			timer_to_sleep;
	pthread_mutex_t	mu_time;
}					t_philo;

void				p_error_usage(void);
void				destroy_and_free(t_philo *philo);

int					parsing(t_data data);

t_philo				*init_main(t_data *data);

void				*routine(void *arg);

#endif