/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 14:54:38 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 13:14:14 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

#define RE 0
#define IM 1
#define C_BLACK 0x00000000

static int	julia_color(int i, int max_iterations)
{
	if (i >= max_iterations)
		return (C_BLACK);
	//return (colormap_get_trgb(i));
	return (hue((double)i / 256 + HUE_START));
}

int	julia_pixel(int x, int y, t_program *program)
{
	long double	c[2];
	long double	z[2];
	long double	len;
	long double	z_old[2];
	int			i;

	c[RE] = (long double)program->arg1;
	c[IM] = (long double)program->arg2;
	len = 2.0 * program->zoom;
	z[RE] = program->cx + ((long double)x / \
			(long double)program->window_w - 0.5) * len;
	z[IM] = program->cy + ((long double)y / \
			(long double)program->window_w - 0.5) * len;
	i = 0;
	while (i < program->iterations)
	{
		z_old[RE] = z[RE];
		z_old[IM] = z[IM];
		z[RE] = z_old[RE] * z_old[RE] - z_old[IM] * z_old[IM] + c[RE];
		z[IM] = 2 * z_old[RE] * z_old[IM] + c[IM];
		if (z[RE] * z[RE] + z[IM] * z[IM] > 4)
			break ;
		i++;
	}
	return (julia_color(i, program->iterations));
}
