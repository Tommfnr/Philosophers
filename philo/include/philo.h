/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:59 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/05 18:03:25 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"


# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

//a enlever
#include <stdlib.h>



// typedef enum e_error
// {
// 	RED,
// 	GREEN,
// 	BLUE
// }	t_error;

typedef struct s_data
{
	int		argc;
	char	**argv;
	int		nb_philo;
}			t_data;

#endif