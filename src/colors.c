/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 15:51:22 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/30 15:51:33 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static t_rgb	rgb(int r, int g, int b)
{
	return ((t_rgb){r, g, b});
}

int	hue(double value)
{
	t_rgb	c;
	int		normal;
	int		x;

	if (value > 1.0)
		value = value - (int)value;
	normal = value * 256 * 6;
	x = normal % 256;
	normal = normal / 256;
	if (normal == 0)
		c = rgb(255, x, 0);
	else if (normal == 1)
		c = rgb(255 - x, 255, 0);
	else if (normal == 2)
		c = rgb(0, 255, x);
	else if (normal == 3)
		c = rgb(0, 255 - x, 255);
	else if (normal == 4)
		c = rgb(x, 0, 255);
	else if (normal == 5)
		c = rgb(255, 0, 255 - x);
	return (0 << 24 | c.r << 16 | c.g << 8 | c.b);
}
