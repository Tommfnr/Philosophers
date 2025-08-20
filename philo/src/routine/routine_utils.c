/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:48:15 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/19 13:43:33 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

int	all_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mu_dead);
	if (philo->data->dead > 0)
	{
		pthread_mutex_unlock(&philo->data->mu_dead);
		return (1);
	}
	if (get_current_time() > philo->timer_to_die + philo->data->time_die)
	{
		philo->data->dead = philo->id;
		pthread_mutex_unlock(&philo->data->mu_dead);
		print_logs(philo, DIE);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mu_dead);
	return (0);
}

int	finished_eating(t_philo *philo)
{
	if (philo->data->nb_eat == -1)
		return (0);
	pthread_mutex_lock(&philo->data->mu_eat);
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

void	think(t_philo *philo, size_t nb_time_waiting)
{
	if (all_philo_alive(philo) != 0)
		return ;
	print_logs(philo, THINKING);
	ft_usleep(nb_time_waiting);
}

void	eat(t_philo *philo)
{
	if (philo->data->nb_eat != -1)
		philo->nb_eaten++;
	if (philo->nb_eaten == philo->data->nb_eat && !philo->done)
	{
		pthread_mutex_lock(&philo->data->mu_eat);
		philo->data->nb_all_eaten++;
		pthread_mutex_unlock(&philo->data->mu_eat);
		philo->done = true;
	}
	if (all_philo_alive(philo) != 0)
		return ;
	print_logs(philo, EAT);
	philo->timer_to_die = get_current_time();
	ft_usleep(philo->data->time_eat);
}

void	ft_sleep(t_philo *philo)
{
	size_t	max_time;

	max_time = get_current_time() + philo->data->time_sleep;
	if (all_philo_alive(philo) != 0)
		return ;
	print_logs(philo, SLEEP);
	while (get_current_time() < max_time)
	{
		ft_usleep(5);
		if (all_philo_alive(philo) != 0)
			return ;
	}
}
