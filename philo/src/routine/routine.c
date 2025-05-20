/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/20 17:38:06 by tfournie         ###   ########.fr       */
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
	while(1)
	{
		ft_usleep(1);
		pthread_mutex_lock(&philo->data->mu_time);
		if (philo->data->nb_philo_init != 0)
		{
			pthread_mutex_unlock(&philo->data->mu_time);
			break;
		}
		pthread_mutex_unlock(&philo->data->mu_time);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat / 2);
	philo->timer_to_die = get_current_time();
	while (all_philo_alive(philo) == 0 && finished_eating(philo) > 0)
	{
		think(philo, 1);
		while (take_forks(philo) != 1 && all_philo_alive(philo) == 0)
		{
			ft_usleep(1);
		}
		// printf("%d f_l: %d f_r: %d == %d\n", philo->id, philo->have_fork_l, philo->have_fork_r, *(philo->fork_r));
		if (philo->have_fork_l == true && philo->have_fork_r == true)
		{
			eat(philo);
			put_down_fork(philo);
		}
		ft_sleep(philo);
	}
	pthread_exit(NULL);
}
