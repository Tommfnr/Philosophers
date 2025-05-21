/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/21 13:09:09 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	data.argc = argc;
	data.argv = argv;
	if (parsing(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo = init_main(&data);
	if (philo == NULL)
		return (EXIT_FAILURE);
	while (1)
	{
		ft_usleep(10);
		pthread_mutex_lock(&data.mu_dead);
		if (data.dead > 0)
		{
			pthread_mutex_unlock(&data.mu_dead);
			break ;
		}
		pthread_mutex_unlock(&data.mu_dead);
	}
	destroy_and_free(philo);
	return (0);
}
