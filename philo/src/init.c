/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:23 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 18:21:09 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	init_data(t_data *data)
{
	data->nb_philo = ft_atoi(data->argv[1]);
	data->time_die = ft_atoi(data->argv[2]);
	data->time_eat = ft_atoi(data->argv[3]);
	data->time_sleep = ft_atoi(data->argv[4]);
	if (data->argv[5] != NULL)
		data->nb_time = ft_atoi(data->argv[5]);
	else
		data->nb_time = -1;
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (i < data->nb_philo)
	{
		philo[i].data = *data;
		philo[i].id = i + 1;
		philo[i].pt = -1;
		philo[i].fork_l = true;
		if (i == 0)
			philo[0].fork_r = &philo[data->nb_philo].fork_l;
		else
			philo[i].fork_r = &philo[i - 1].fork_l;
		i++;
	}
	return (philo);
}

void	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data.nb_philo)
	{
		if (pthread_create(&philo[i].pt, NULL, routine, &philo[i]) != 0)
		{
			perror("Erreur lors de la création du thread");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < philo[0].data.nb_philo)
	{
		pthread_join(philo[i].pt, NULL);
		i++;
	}
}
