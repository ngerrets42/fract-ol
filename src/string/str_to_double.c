/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_to_double.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 12:46:29 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 13:17:38 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_neg(char *str)
{
	if (str[0] == '-')
		return (-1);
	return (1);
}

double	str_to_double(char *str)
{
	double	r;
	double	dot_number;
	int		i;

	r = 0.0;
	i = 0;
	if (is_neg(str) == -1)
		i++;
	while (is_digit(str[i]))
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	if (str[i] != '.')
		return (r * is_neg(str));
	i++;
	dot_number = 1;
	while (is_digit(str[i]))
	{
		dot_number *= 10;
		r += (str[i] - '0') / dot_number;
		i++;
	}
	return (r * is_neg(str));
}
