/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 17:19:14 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/02 17:21:12 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	morefractal_pixel(int x, int y, t_program *program)
{
	long double	c[2];
	long double	z[2];
	long double	z_old;
	long double	len;
	int			i;

	len = 2.0 * program->zoom;
	c[RE] = program->cx + ((long double)x /
		(long double)program->window_w - 0.5) * len;
	c[IM] = program->cy + ((long double)y /
		(long double)program->window_w - 0.5) * len;
	z[RE] = 0;
	z[IM] = 0;
	z_old = 0;
	i = 0;
	while (i < program->iterations && fabsl(z[RE]) < 2.0)
	{
		z_old = z[RE];
		z[RE] = powl(z[RE], z[RE] * c[RE]) + -1.0 * powl(z[IM], z[IM] * c[IM]);
		z[IM] = 2.0 * powl(z_old, z[IM] * c[IM]);
		i++;
	}
	return (color_from_iterations(i, program->iterations, program));
}

