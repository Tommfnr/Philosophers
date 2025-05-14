/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 17:40:43 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	print_logs(t_philo *philo, t_logs log)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->data->mu_time);
	current_time = get_current_time() - philo->data->timer;
	pthread_mutex_unlock(&philo->data->mu_time);
	if (log == FORK)
		printf("%zu %d has taken a fork\n", current_time, philo->id);
	if (log == EAT)
		printf("%zu %d is eating\n", current_time, philo->id);
	if (log == SLEEP)
		printf("%zu %d is sleeping\n", current_time, philo->id);
	if (log == THINKING)
		printf("%zu %d is thinking\n", current_time, philo->id);
	if (log == DIE)
		printf("%zu %d died\n", current_time, philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat / 2);
	philo->timer_to_die = get_current_time();
	while (1)
	{
		pthread_mutex_lock(&philo->data->mu_fork_l);
		if (philo->fork_l == true && *philo->fork_r == true)
		{
			print_logs(philo, FORK);
			print_logs(philo, FORK);
			print_logs(philo, EAT);
			usleep(philo->data->time_eat);
			philo->timer_to_die = get_current_time();
			philo->fork_l = false;
			*philo->fork_r = false;
		}
		// printf("timer: %zu,    time_die: %d\n", philo->timer_to_die, philo->data->time_die);
		pthread_mutex_unlock(&philo->data->mu_fork_l);
		if (get_current_time() - philo->timer_to_die >= (size_t)philo->data->time_die)
		{
			pthread_mutex_lock(&philo->data->mu_dead);
			philo->data->dead = 1;
			print_logs(philo, DIE);
			pthread_mutex_unlock(&philo->data->mu_dead);
		}
		pthread_mutex_lock(&philo->data->mu_dead);
		if (philo->data->dead == 1)
		{
			pthread_mutex_unlock(&philo->data->mu_dead);
			return NULL;
			
		}
		pthread_mutex_unlock(&philo->data->mu_dead);
	}
	pthread_exit(NULL);
}

/* void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat / 2);
	philo->timer_to_die = get_current_time();
	// print_logs(philo, EAT);
	while (1)
	{
		pthread_mutex_lock(&philo->data->mu_fork_l);
		if (philo->fork_l == true && *philo->fork_r == true)
		{
			print_logs(philo, FORK);
			print_logs(philo, FORK);
			print_logs(philo, EAT);
			usleep(philo->data->time_eat);
			philo->timer_to_die = get_current_time();
			philo->fork_l = false;
			*philo->fork_r = false;
		}
		// printf("timer: %zu,    time_die: %d\n", philo->timer_to_die, philo->data->time_die);
		pthread_mutex_unlock(&philo->data->mu_fork_l);
		if (get_current_time() - philo->timer_to_die >= (size_t)philo->data->time_die)
		{
			pthread_mutex_lock(&philo->data->mu_dead);
			philo->data->dead = 1;
			print_logs(philo, DIE);
			pthread_mutex_unlock(&philo->data->mu_dead);
		}
		pthread_mutex_lock(&philo->data->mu_dead);
		if (philo->data->dead == 1)
		{
			pthread_mutex_unlock(&philo->data->mu_dead);
			return NULL;
			
		}
		pthread_mutex_unlock(&philo->data->mu_dead);
	}
	pthread_exit(NULL);
} */
