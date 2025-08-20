/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:23 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/20 08:48:27 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	init_data(t_data *data)
{
	int error;
	data->nb_philo = ft_atoi(data->argv[1], &error);
	data->time_die = ft_atoi(data->argv[2], &error);
	data->time_eat = ft_atoi(data->argv[3], &error);
	data->time_sleep = ft_atoi(data->argv[4], &error);
	if (data->argv[5] != NULL)
		data->nb_eat = ft_atoi(data->argv[5], &error);
	else
		data->nb_eat = -1;
	if (error)
	{
		p_error_usage();
		exit(EXIT_FAILURE);
	}
	if (data->nb_philo < 1 || data->time_die < 0 || data->time_eat < 0
		|| data->time_sleep < 0 || (data->nb_eat < 0 && data->argv[5] != NULL))
	{
		p_error_usage();
		exit(EXIT_FAILURE);
	}
	data->dead = 0;
	data->timer = get_current_time();
	data->nb_philo_init = 0;
	data->nb_all_eaten = 0;
}

static void	init_one_philo(t_philo *philo, t_data *data, int i)
{
	memset(&philo[i], 0, sizeof(t_philo));
	philo[i].data = data;
	philo[i].id = i + 1;
	philo[i].pt = -1;
	philo[i].fork_l = true;
	pthread_mutex_init(&(philo[i].mu_fork_l), NULL);
	if (i == 0)
	{
		philo[0].fork_r = &philo[data->nb_philo - 1].fork_l;
		philo[0].mu_fork_r = &philo[data->nb_philo - 1].mu_fork_l;
	}
	else
	{
		philo[i].fork_r = &philo[i - 1].fork_l;
		philo[i].mu_fork_r = &philo[i - 1].mu_fork_l;
	}
	philo[i].have_fork_l = false;
	philo[i].have_fork_r = false;
	philo[i].done = false;
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
		init_one_philo(philo, data, i);
		i++;
	}
	return (philo);
}

t_philo	*init_main(t_data *data)
{
	t_philo	*philo;

	init_data(data);
	philo = init_philo(data);
	if (philo == NULL)
		return (NULL);
	init_mutex(data);
	if (init_threads(philo) == EXIT_FAILURE)
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}
