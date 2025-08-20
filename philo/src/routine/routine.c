/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:02 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/19 13:11:13 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

static void	wait_for_start(t_philo *philo)
{
	while (1)
	{
		ft_usleep(1);
		pthread_mutex_lock(&philo->data->mu_init);
		if (philo->data->nb_philo_init > 0)
		{
			pthread_mutex_unlock(&philo->data->mu_init);
			break ;
		}
		else if (philo->data->nb_philo_init == -1)
		{
			pthread_mutex_unlock(&philo->data->mu_init);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&philo->data->mu_init);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	wait_for_start(philo);
	philo->timer_to_die = get_current_time();
	i = 0;
	while (all_philo_alive(philo) == 0 && finished_eating(philo) == 0)
	{
		think(philo, 1);
		if (philo->id % 2 == 0 && i == 0)
			ft_usleep(philo->data->time_eat / 2);
		while (take_forks(philo) != 1 && all_philo_alive(philo) == 0)
			ft_usleep(1);
		if (philo->have_fork_l == true && philo->have_fork_r == true)
		{
			eat(philo);
			put_down_fork(philo);
		}
		ft_sleep(philo);
		i++;
	}
	pthread_exit(NULL);
}
