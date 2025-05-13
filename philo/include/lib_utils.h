/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:52:56 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/13 15:21:01 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

# include <limits.h>
# include <stdbool.h>

# define Error 1
# define Valid 0

long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isnumber_pos(const char *str);

#endif