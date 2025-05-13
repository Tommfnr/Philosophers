/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:52:56 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 13:14:35 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

# include <limits.h>

# define Error 1
# define Valid 0

long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isnumber(const char *str);

#endif