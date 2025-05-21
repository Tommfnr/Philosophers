/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:48:15 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/21 11:59:37 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"

// 0 si aucun philo n'est mort, sinon le numero de celui qui est mort
int	all_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mu_dead);
	if (philo->data->dead > 0)
	{
		pthread_mutex_unlock(&philo->data->mu_dead);
		return (philo->id);
	}
	pthread_mutex_unlock(&philo->data->mu_dead);
	if (philo->timer_to_die + (get_current_time() - philo->timer_to_die) > philo->timer_to_die + philo->data->time_die)
	{
		pthread_mutex_lock(&philo->data->mu_dead);
		philo->data->dead = philo->id;
		pthread_mutex_unlock(&philo->data->mu_dead);
		print_logs(philo, DIE);
	}
	return (0);
}

int	finished_eating(t_philo *philo)
{
	if (philo->data->nb_eat == -1)
		return (0);
	pthread_mutex_lock(&philo->data->mu_eat);
	// printf("--------nb_all_eaten: %d\n", philo->data->nb_all_eaten);
	if (philo->data->nb_all_eaten == philo->data->nb_philo)
	{
		pthread_mutex_unlock(&philo->data->mu_eat);
		pthread_mutex_lock(&philo->data->mu_dead);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->mu_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mu_eat);
	return (0);
}

void think(t_philo *philo, size_t nb_time_waiting)
{
	print_logs(philo, THINKING);
	ft_usleep(nb_time_waiting);
}

void eat(t_philo *philo)
{
	if (philo->data->nb_eat != -1)
		philo->nb_eaten++;
	if (philo->nb_eaten == philo->data->nb_eat)
	{
		pthread_mutex_lock(&philo->data->mu_eat);
		philo->data->nb_all_eaten++;
		pthread_mutex_unlock(&philo->data->mu_eat);
	}
	print_logs(philo, EAT);
	philo->timer_to_die = get_current_time();
	ft_usleep(philo->data->time_eat);
}

void ft_sleep(t_philo *philo)
{
	int max_time;

	max_time = get_current_time() + philo->data->time_sleep;
	while ((int)get_current_time() < max_time)
	{
		ft_usleep(5);
		if (all_philo_alive(philo) != 0)
			return ;
	}
}
