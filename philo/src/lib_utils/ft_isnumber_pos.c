/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:48:28 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 16:33:36 by tfournie         ###   ########.fr       */
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
		return (1);
	if (str[i] == '+')
		i++;
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
