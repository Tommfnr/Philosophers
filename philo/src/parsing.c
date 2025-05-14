/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:32 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 11:47:02 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "philo.h"

void	p_error_usage(void)
{
	printf("ERROR with usage:\n./philo \n");
	printf("| (int > 1) <number_of_philosophers>\n| (int) <time_to_die>\n");
	printf("| (int) <time_to_eat>\n| (int) <time_to_sleep>\n");
	printf("| (optional: (int) <number_of_times_each_philosopher_must_eat>)\n");
}

int	parsing(t_data data)
{
	int	i;

	i = 1;
	if (data.argc < 5 || data.argc > 6)
	{
		p_error_usage();
		return (ERROR);
	}
	while (i < data.argc)
	{
		if (ft_isnumber_pos(data.argv[i]) == ERROR)
		{
			p_error_usage();
			return (ERROR);
		}
		i++;
	}
	if (ft_atoi(data.argv[1]) < 1)
	{
		p_error_usage();
		return (ERROR);
	}
	return (VALID);
}
