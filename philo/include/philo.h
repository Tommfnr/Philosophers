/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 15:27:30 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # define RED "\033[31m"
// # define GREEN "\033[32m"
// # define YELLOW "\033[33m"
// # define BLUE "\033[34m"
// # define RESET "\033[0m"


# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

# include <stdlib.h>

# define Error 1
# define Valid 0

typedef struct s_data
{
	int		argc;
	char	**argv;
	int		nb_philo;
	int		time_die;
	int 	time_eat;
	int		time_sleep;
	int 	nb_time;
	
}			t_data;

int 	parsing(t_data data);
void 	init_data(t_data data);



#endif