/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:32 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 15:31:51 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	p_error_usage(void)
{
	printf("Error with usage:\n./philo \n| (int) <number_of_philosophers>\n| (int) <time_to_die>\n| (int) <time_to_eat>\n| (int) <time_to_sleep>\n| (optional: (int) <number_of_times_each_philosopher_must_eat>)\n");
}

int	parsing(t_data data)
{
	int	i;

	i = 1;
	if (data.argc < 5 || data.argc > 6)
	{
		p_error_usage();
		return (Error);
	}
	while (i < data.argc)
	{
		if (ft_isnumber_pos(data.argv[i]) == Error)
		{
			p_error_usage();
			return (Error);
		}
		i++;
	}
	return (Valid);
}
