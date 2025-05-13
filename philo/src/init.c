/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:23 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 13:40:07 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"

void init_data(t_data data)
{
	data.nb_philo = ft_atoi(data.argv[2]);
	data.time_die = ft_atoi(data.argv[3]);
	data.time_eat = ft_atoi(data.argv[4]);
	data.time_sleep = ft_atoi(data.argv[5]);
	if (data.argv[6] != NULL)
		data.nb_time = ft_atoi(data.argv[6]);
	else 
	data.nb_time = -1;
}
