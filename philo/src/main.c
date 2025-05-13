/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:05:54 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 16:13:08 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo *philo;

	data.argc = argc;
	data.argv = argv;
	if (parsing(data) == ERROR)
		return (ERROR);
	init_data(data);
	philo = NULL;
	if (init_philo(philo, data) == ERROR)
		return (ERROR);
	return (0);
}
