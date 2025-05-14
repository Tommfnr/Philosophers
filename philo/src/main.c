/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 15:06:25 by tfournie         ###   ########.fr       */
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
	if (parsing(data) == ERROR)
		return (ERROR);
	philo = init_main(&data);
	if (philo == NULL)
		return (ERROR);
	data.timer = get_current_time();
	destroy_and_free(philo);
	return (0);
}
