/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomm <tomm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:00:25 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/10 09:23:34 by tomm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_and_free(t_philo *philo)
{
    int		i;
    t_data	*data;

    if (!philo)
        return;
    data = philo->data;

    // Détruire les mutex des philosophes (fourchettes individuelles)
    for (i = 0; i < data->nb_philo; i++)
        pthread_mutex_destroy(&philo[i].mu_fork_l);

    // Détruire les mutex globaux
    pthread_mutex_destroy(&data->mu_dead);
    pthread_mutex_destroy(&data->mu_eat);
    pthread_mutex_destroy(&data->mu_time);
    pthread_mutex_destroy(&data->mu_init);
    pthread_mutex_destroy(&data->mu_eaten);

    // Libérer le tableau de philosophes
	free(philo);
}
