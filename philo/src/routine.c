/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 18:21:02 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Philosophe %d commence la routine.\n", philo->id);
	usleep(philo->data.time_eat * 1000);
	printf("Philosophe %d a fini de manger.\n", philo->id);
	pthread_exit(NULL);
}
