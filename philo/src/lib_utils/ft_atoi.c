/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:44:08 by tfournie          #+#    #+#             */
/*   Updated: 2025/08/20 08:31:12 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include "lib_utils.h" // si tu as tes propres utilitaires
#include <ctype.h>     // pour isdigit
#include <limits.h>

static int	ft_skip_whitespace_and_sign(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		else
			*sign = 1;
		i++;
	}
	else
		*sign = 1;
	return (i);
}

unsigned long long	ft_atoi(const char *nptr, int *error)
{
	unsigned long long	res;
	unsigned			digit;
	int					i;
	int					sign;
	
	i = ft_skip_whitespace_and_sign(nptr, &sign);
	res = 0;
	if (error)
		*error = 1;
	if (sign == -1)
		return (0);
	if (!isdigit(nptr[i]))
		return (0);
	while (nptr[i] && isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (res > (ULLONG_MAX - digit) / 10)
			return (0);
		res = res * 10 + digit;
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	if (error)
		*error = 0;
	return (res);
}
