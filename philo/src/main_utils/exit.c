/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:00:25 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 15:45:25 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error_usage(void)
{
	printf("ERROR with usage:\n./philo \n");
	printf("| (int > 1) <number_of_philosophers>\n| (int) <time_to_die>\n");
	printf("| (int) <time_to_eat>\n| (int) <time_to_sleep>\n");
	printf("| (optional: (int) <number_of_times_each_philosopher_must_eat>)\n");
}

void	destroy_and_free(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->data->mu_dead));
	if (philo != NULL)
		free(philo);
}
