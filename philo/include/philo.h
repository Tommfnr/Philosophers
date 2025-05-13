/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 17:25:03 by tfournie         ###   ########.fr       */
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

typedef enum e_output
{
	ERROR = 1,
	VALID = 0
}				t_output;

typedef struct s_data
{
	int			argc;
	char		**argv;
	int			nb_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			nb_time;

}				t_data;

typedef struct s_philo
{
	t_data		data;
	int			id;
	pthread_t	pt;
	bool		fork_l;
	bool		*fork_r;
}				t_philo;

int				parsing(t_data data);
void			init_data(t_data *data);
t_philo			*init_philo(t_data *data);

#endif