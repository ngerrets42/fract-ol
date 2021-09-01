/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:12:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/01 16:24:16 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	mandelbrot_pixel(int x, int y, t_program *program)
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
		z[RE] = z[RE] * z[RE] + -1.0 * (z[IM] * z[IM]) + c[RE];
		z[IM] = 2.0 * z_old * z[IM] + c[IM];
		i++;
	}
	return (color_from_iterations(i, program->iterations, program));
}
