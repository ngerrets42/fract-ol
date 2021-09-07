/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colormap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 13:26:29 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 12:48:07 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_rgb	colormap_3_get(int i)
{
	static t_rgb	c[] =
	{
		{255, 10, 10},
		{10, 255, 10},
		{10, 10, 255}
	};

	return (c[i % 3]);
}

t_rgb	colormap_16_get(int i)
{
	static t_rgb	c[] =
	{
		{66, 30, 15},
		{25, 7, 26},
		{9, 1, 47},
		{4, 4, 73},
		{0, 7, 100},
		{12, 44, 138},
		{24, 82, 177},
		{57, 125, 209},
		{134, 181, 229},
		{211, 236, 248},
		{241, 233, 191},
		{248, 201, 95},
		{255, 170, 0},
		{204, 128, 0},
		{153, 87, 0},
		{106, 52, 3}
	};

	return (c[i % 16]);
}

int	colormap_get_trgb(t_rgb(*colormap)(int), int i)
{
	t_rgb	c;

	if (colormap == NULL)
		return (C_BLACK);
	c = colormap(i);
	return (0 << 24 | c.r << 16 | c.g << 8 | c.b);
}
