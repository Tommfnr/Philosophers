/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:29:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/06/10 18:29:05 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&(data->mu_time), NULL);
	pthread_mutex_init(&(data->mu_dead), NULL);
	pthread_mutex_init(&(data->mu_init), NULL);
	pthread_mutex_init(&(data->mu_eat), NULL);
	pthread_mutex_init(&(data->mu_eaten), NULL);
}

int	join_threads(t_philo *philo, int init)
{
	int	i;

	i = 0;
	while (i < init)
	{
		if (pthread_join(philo[i].pt, NULL) != 0)
		{
			printf("Error with the join of the thread");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->nb_philo)
	{
		if (pthread_create(&philo[i].pt, NULL, routine, &philo[i]) != 0)
		{
			printf("Error with the creation of the thread\n");
			pthread_mutex_lock(&philo->data->mu_init);
			philo->data->nb_philo_init = -1;
			pthread_mutex_unlock(&philo->data->mu_init);
			join_threads(philo, i);
			return (EXIT_FAILURE);
		}
		i++;
		if (i == philo->data->nb_philo)
		{
			pthread_mutex_lock(&philo->data->mu_init);
			philo->data->nb_philo_init = i;
			pthread_mutex_unlock(&philo->data->mu_init);
		}
	}
	return (join_threads(philo, i));
}
