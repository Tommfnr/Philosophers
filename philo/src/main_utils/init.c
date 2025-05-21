/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:23 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/21 12:12:41 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

static void	init_data(t_data *data)
{
	data->nb_philo = ft_atoi(data->argv[1]);
	data->time_die = ft_atoi(data->argv[2]);
	data->time_eat = ft_atoi(data->argv[3]);
	data->time_sleep = ft_atoi(data->argv[4]);
	if (data->argv[5] != NULL)
		data->nb_eat = ft_atoi(data->argv[5]);
	else
		data->nb_eat = -1;
	data->dead = 0;
	data->timer = get_current_time();
	data->nb_philo_init = 0;
	data->nb_all_eaten = 0;
}

static t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (i < data->nb_philo)
	{
		memset(&philo[i], 0, sizeof(t_philo));
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].pt = -1;
		philo[i].fork_l = true;
		if (i == 0)
			philo[0].fork_r = &philo[data->nb_philo - 1].fork_l;
		else
			philo[i].fork_r = &philo[i - 1].fork_l;
		philo[i].have_fork_l = false;
		philo[i].have_fork_r = false;
		i++;
	}
	return (philo);
}

static void	init_mutex(t_data *data)
{
	pthread_mutex_init(&(data->mu_time), NULL);
	pthread_mutex_init(&(data->mu_fork_l), NULL);
	pthread_mutex_init(&(data->mu_fork_r), NULL);
	pthread_mutex_init(&(data->mu_dead), NULL);
	pthread_mutex_init(&(data->mu_init), NULL);
	pthread_mutex_init(&(data->mu_eat), NULL);
	pthread_mutex_init(&(data->mu_eaten), NULL);
}

static int	init_threads(t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < philo[0].data->nb_philo)
	{
		if (pthread_create(&philo[i].pt, NULL, routine, &philo[i]) != 0)
		{
			printf("Error with the creation of the thread");
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
	// printf("================ start of philo %d\n", philo->id);

	i = 0;
	while (i < philo[0].data->nb_philo)
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

t_philo	*init_main(t_data *data)
{
	t_philo	*philo;

	init_data(data);
	philo = init_philo(data);
	// printf("%zu\n", philo->timer_to_die);
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
