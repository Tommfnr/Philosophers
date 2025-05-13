/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:23 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 16:13:41 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	init_data(t_data data)
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

int init_philo(t_philo *philo, t_data data)
{
	int i;

	i = 0;
	philo = malloc(5 *sizeof(t_philo));
	if (philo == NULL)
		return (ERROR);
	while (i < data.nb_philo)
	{
		philo[i].data = data;
		philo[i].id = i;
		philo[i].pt = -1;
		philo[i].fork_L = true;
		if (i == 0)
			philo[0].fork_R = &philo[data.nb_philo].fork_L;
		else
			philo[i].fork_R = &philo[i - 1].fork_L;
		i++;
	}
	return (VALID);
}
