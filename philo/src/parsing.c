/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:32 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 13:20:36 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib_utils.h"

void error_usage_and_exit(int i)
{
	if (i == 1)
		printf("Error with usage:\n./philo \n| (int) <number_of_philosophers>\n| (int) <time_to_die>\n| (int) <time_to_eat>\n| (int) <time_to_sleep>\n| (optional: (int) <number_of_times_each_philosopher_must_eat>)\n");
	exit(Error);
}

void parsing(t_data data)
{
	int i;

	i = 1;
	if (data.argc < 5 || data.argc > 6)
		error_usage_and_exit(Error);
	while (i < data.argc)
	{
		if (ft_isnumber(data.argv[i]) == Error)
			error_usage_and_exit(Error);
		i++;
	}
}
