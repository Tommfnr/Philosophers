/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:32 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/20 10:13:00 by tfournie         ###   ########.fr       */
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
		p_error_usage();
		return (EXIT_FAILURE);
	}
	while (i < data.argc)
	{
		if (ft_isnumber_pos(data.argv[i]) == EXIT_FAILURE)
		{
			p_error_usage();
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (ft_atoi(data.argv[1]) > 250)
	{
		p_error_usage();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
