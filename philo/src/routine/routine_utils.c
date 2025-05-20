/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:48:15 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/20 18:03:46 by tfournie         ###   ########.fr       */
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

// 1/true s'il n'y a pas de nb_eat, 0/false s'il n'a pas fini, 1/true s'il a fini
int	finished_eating(t_philo *philo)
{
	static int	i = 0;

	if (philo->data->nb_eat == -1)
		return (true);
	else if (i == philo->data->nb_eat)
		return (true);
	i++;
	return (false);
}

void think(t_philo *philo, size_t nb_time_waiting)
{
	print_logs(philo, THINKING);
	ft_usleep(nb_time_waiting);
}

void eat(t_philo *philo)
{
	print_logs(philo, EAT);
	philo->timer_to_die = get_current_time();
	ft_usleep(philo->data->time_eat);
	// put_down_fork(philo);
	// philo->timer_to_eat = 0;
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
