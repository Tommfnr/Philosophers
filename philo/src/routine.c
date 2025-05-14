/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 12:58:26 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	print_logs(t_philo *philo, t_logs log)
{
	size_t	current_time;

	current_time = get_current_time() - philo->data.timer;
	if (log == FORK)
		printf("%d %d has taken a fork\n", current_time, philo->id);
	if (log == EAT)
		printf("%d %d is eating\n", current_time, philo->id);
	if (log == SLEEP)
		printf("%d %d is sleeping\n", current_time, philo->id);
	if (log == THINKING)
		printf("%d %d is thinking\n", current_time, philo->id);
	if (log == DIE)
		printf("%d %d died\n", current_time, philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->timer_to_die = get_current_time();
	pthread_exit(NULL);
}
