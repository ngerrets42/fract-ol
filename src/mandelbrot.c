/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:12:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 12:06:30 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

/*static int mandelbrot_greyscale(int i)
{
	float	factor;
	int	r;
	int	g;
	int	b;
	int	base;
	
	if (i >= program->iterations)
		return (0);
	base = 128;
	factor = (float)i / ITERATION_MAX;
	r = base * factor;
	g = base * factor;
	b = base * factor;
	return (0 << 24 | r << 16 | g << 8 | b);
}*/

static int	mandelbrot_color(int i, int max_iterations)
{
	if (i >= max_iterations)
		return (C_BLACK);
	//return (colormap_get_trgb(i));
	return (hue((double)i / 256 + HUE_START));
}

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
	return (mandelbrot_color(i, program->iterations));
}
