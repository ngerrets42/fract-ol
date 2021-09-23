/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/23 12:00:08 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/23 11:00:13 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <unistd.h>

int		ft_strlen(const char *str);
void	put(const char *str, const int *n);
int		str_is_str(const char *str1, const char *str2);
double	str_to_double(char *str);

#endif
