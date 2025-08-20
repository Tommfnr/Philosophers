/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:00:25 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/20 10:52:54 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_and_free(t_philo *philo)
{
	int		i;
	t_data	*data;

	if (!philo)
		return ;
	i = 0;
	data = philo->data;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].mu_fork_l);
		i++;
	}
	pthread_mutex_destroy(&data->mu_dead);
	pthread_mutex_destroy(&data->mu_eat);
	pthread_mutex_destroy(&data->mu_time);
	pthread_mutex_destroy(&data->mu_init);
	pthread_mutex_destroy(&data->mu_eaten);
	free(philo);
}
