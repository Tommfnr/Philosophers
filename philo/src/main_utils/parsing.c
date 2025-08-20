/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:32 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/20 08:48:53 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

int	parsing(t_data data)
{
	int	i;

	i = 1;
	if (data.argc < 5 || data.argc > 6)
	{
		printf("1. Wrong number of arguments.\n");
		p_error_usage();
		return (EXIT_FAILURE);
	}
	// while (i < data.argc)
	// {
	// 	if (ft_isnumber_pos(data.argv[i]) == EXIT_FAILURE)
	// 	{
	// 		printf("2. Argument %d is not a positive number.\n", i);
	// 		p_error_usage();
	// 		return (EXIT_FAILURE);
	// 	}
	// 	i++;
	// }
	if (ft_atoi(data.argv[1], NULL) < 1)
	{
		printf("3. Number of philosophers must be at least 1.\n");
		p_error_usage();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
