/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_fork.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/21 13:41:02 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mu_fork_l);
	philo->fork_l = true;
	pthread_mutex_unlock(&philo->data->mu_fork_l);
	philo->have_fork_l = false;
	pthread_mutex_lock(&philo->data->mu_fork_l);
	*(philo->fork_r) = true;
	pthread_mutex_unlock(&philo->data->mu_fork_l);
	philo->have_fork_r = false;
}

static int	take_fork_l(t_philo *philo)
{
	if (philo->have_fork_l == true)
		return (1);
	pthread_mutex_lock(&philo->data->mu_fork_l);
	if (philo->fork_l == true)
	{
		philo->fork_l = false;
		pthread_mutex_unlock(&philo->data->mu_fork_l);
		philo->have_fork_l = true;
		print_logs(philo, FORK);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mu_fork_l);
	return (0);
}

static int	take_fork_r(t_philo *philo)
{
	if (philo->have_fork_r == true)
		return (1);
	pthread_mutex_lock(&philo->data->mu_fork_r);
	if (*(philo->fork_r) == true)
	{
		*(philo->fork_r) = false;
		pthread_mutex_unlock(&philo->data->mu_fork_r);
		philo->have_fork_r = true;
		print_logs(philo, FORK);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mu_fork_r);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (take_fork_l(philo) == 0)
		return (0);
	if (take_fork_r(philo) == 0)
		return (0);
	if (philo->have_fork_l == true && philo->have_fork_r == true)
		return (1);
	return (0);
}
