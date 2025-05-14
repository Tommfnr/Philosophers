/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 14:55:13 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	print_logs(t_philo *philo, t_logs log)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->mu_time);
	current_time = get_current_time() - philo->data.timer;
	pthread_mutex_unlock(&philo->mu_time);
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
		ft_usleep(philo->data.time_eat / 2);
	print_logs(philo, EAT);
	pthread_exit(NULL);
}
