/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:48:28 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 13:14:31 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

int	ft_isnumber(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (num < INT_MIN || num > INT_MAX)
		return (Error);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (Error);
		i++;
	}
	return (Valid);
}
