/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:48:28 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 15:36:05 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

int	ft_isnumber_pos(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	if (str[i] == '-')
		return (ERROR);
	if (str[i] == '+')
		i++;
	if (num < INT_MIN || num > INT_MAX)
		return (ERROR);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	return (VALID);
}
