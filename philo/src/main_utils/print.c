/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:15:40 by tfournie          #+#    #+#             */
/*   Updated: 2025/09/02 13:44:11 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"

void	p_error_usage(void)
{
	printf("ERROR with usage:\n./philo \n");
	printf("| (int >= 1) <number_of_philosophers>\n| (int) <time_to_die>\n");
	printf("| (int) <time_to_eat>\n| (int) <time_to_sleep>\n");
	printf("| (optional: (int) <number_of_times_each_philosopher_must_eat>)\n");
}

void	print_logs(t_philo *philo, t_logs log)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->data->mu_time);
	current_time = get_current_time() - philo->data->timer;
	if (log == FORK)
		printf("%zu %d has taken a fork\n", current_time, philo->id);
	else if (log == EAT)
		printf("%zu %d is eating\n", current_time, philo->id);
	else if (log == SLEEP)
		printf("%zu %d is sleeping\n", current_time, philo->id);
	else if (log == THINKING)
		printf("%zu %d is thinking\n", current_time, philo->id);
	else if (log == DIE)
		printf("%zu %d died\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->mu_time);
}

void	print_end(void)
{
	printf("All philosophers have finish eating.\n");
}
