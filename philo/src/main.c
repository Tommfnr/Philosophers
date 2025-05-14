/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 17:25:54 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"

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
		ft_usleep(1);
		pthread_mutex_lock(&data.mu_dead);
		if (data.dead == 1)
		{
			printf("dead in main\n\n");
			pthread_mutex_unlock(&data.mu_dead);
			return (0);
			break;
		}
		pthread_mutex_unlock(&data.mu_dead);	
	}
	destroy_and_free(philo);
	return (0);
}
