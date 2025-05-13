/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 16:02:02 by tfournie         ###   ########.fr       */
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

# define ERROR 1
# define VALID 0

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
	bool		fork_L;
	bool		*fork_R;
}				t_philo;

int				parsing(t_data data);
void			init_data(t_data data);
int				init_philo(t_philo *philo, t_data data);

#endif