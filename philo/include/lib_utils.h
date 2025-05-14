/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:52:56 by tfournie          #+#    #+#             */
/*   Updated: 2025/05/14 12:10:21 by tfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_UTILS_H
# define LIB_UTILS_H

# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

long	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isnumber_pos(const char *str);
size_t	get_current_time(void);
void	ft_usleep(size_t ms);

#endif