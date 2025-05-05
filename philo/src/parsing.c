/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:32 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/05 18:04:00 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void error_and_exit(t_data data, int i)
{
	if (i == 1)
		printf("error with usage:\n./philo <nb_of_philo> <t_to_die> <t_to_eat> <t_to_sleep> (optional: <number_of_times_each_philosopher_must_eat>)\n");
	exit(0);
}

void parsing(t_data data)
{
	if (data.argc < 1 || data.argc > 5)
		error_and_exit(data, 1);
	
		
}
