/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:48:15 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/19 18:17:58 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"

// 0 si aucun philo n'est mort, sinon le numero de celui qui est mort
int	all_philo_alive(t_philo *philo)
{
	if (philo->timer_to_die + (get_current_time() - philo->timer_to_die) > philo->timer_to_die + philo->data->time_die)
	{
		pthread_mutex_lock(&philo->data->mu_dead);
		philo->data->dead = philo->id;
		pthread_mutex_unlock(&philo->data->mu_dead);
	}
	pthread_mutex_lock(&philo->data->mu_dead);
	if (philo->data->dead > 0)
	{
		pthread_mutex_unlock(&philo->data->mu_dead);
		print_logs(philo, DIE);
		return (philo->id);
	}
	pthread_mutex_unlock(&philo->data->mu_dead);
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

// -1 si aucune, 0 si les deux ok, 1 si juste gauche, 2 si juste droite
int take_forks(t_philo *philo)
{
	int 	res;
	bool 	f_l;
	bool 	f_r;

	res = -1;
	f_l = false;
	f_r = false;
	pthread_mutex_lock(&philo->data->mu_fork_l);
	if (philo->fork_l == true)
	{
		philo->fork_l = false;
		print_logs(philo, FORK);
		f_l = true;
	}
	pthread_mutex_unlock(&philo->data->mu_fork_l);
	pthread_mutex_lock(&philo->data->mu_fork_l);
	if (philo->fork_r != NULL)
	{		
		if (*(philo->fork_r) == true)
		{
			*(philo->fork_r) = false;
			print_logs(philo, FORK);
			f_r = true;
		}
	}
	pthread_mutex_unlock(&philo->data->mu_fork_l);
	if (f_l == true && f_r == true)
		return (0);
	else if (f_l == true)
	{
		pthread_mutex_lock(&philo->data->mu_fork_l);
		philo->fork_l = true;
		pthread_mutex_unlock(&philo->data->mu_fork_l);
		return (1);
	}
	else if (f_r == true)
	{
		pthread_mutex_lock(&philo->data->mu_fork_r);
		*(philo->fork_r) = true;
		pthread_mutex_unlock(&philo->data->mu_fork_r);
		return (2);
	}
	return (-1);
}

void eat(t_philo *philo)
{
	print_logs(philo, EAT);
	ft_usleep(philo->data->time_eat);
	philo->timer_to_eat = 0;
}

void put_down_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mu_fork_l);
		philo->fork_l = true;
	pthread_mutex_unlock(&philo->data->mu_fork_l);
	pthread_mutex_lock(&philo->data->mu_fork_l);
		*(philo->fork_r) = true;
	pthread_mutex_unlock(&philo->data->mu_fork_l);
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
