/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 12:27:12 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"


// void	print_logs(t_philo *philo)
// {
	
// }

void	*routine(void *arg)
{
	t_philo	*philo;
	size_t begin_timer;

	philo = (t_philo *)arg;
	begin_timer = get_current_time();
	printf("Philosophe %d commence la routine.\n", philo->id);
	usleep(philo->data.time_eat * 1000);
	printf("Philosophe %d a fini de manger.\n", philo->id);
	pthread_exit(NULL);
}
