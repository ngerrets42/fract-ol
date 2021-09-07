/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 11:43:18 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 14:44:05 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <stdio.h>

t_complex	complex_coordinates(int x, int y, t_program *program)
{
	long double	len;
	t_complex	c;

	len = 2.0 * program->zoom;
	c.re = ((long double)x / (long double)program->window_w - 0.5)
		* len + program->cx;
	c.im = ((long double)y / (long double)program->window_h - 0.5)
		* len + program->cy;
	return (c);
}

static int	fractal_pixel(int x, int y, t_program *program)
{
	if (program->fractal == FRACTAL_MANDELBROT)
		return (mandelbrot_pixel(x, y, program));
	if (program->fractal == FRACTAL_JULIA)
		return (julia_pixel(x, y, program));
	if (program->fractal == FRACTAL_NEWTON)
		return (newton_pixel(x, y, program));
	return (1);
}

int	fractal(t_program *program)
{
	int			x;
	int			y;
	int			c;

	y = 0;
	while (y < program->window_h)
	{
		x = 0;
		while (x < program->window_w)
		{
			c = fractal_pixel(x, y, program);
			img_set_pixel(program->screen_buf, x, y, c);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(program->mlx, program->window,
		program->screen_buf->img, 0, 0);
	printf("Fractal Coordinates: (%.18Lf, %.18Lf)\n", program->cx, program->cy);
	printf("Magnification: %lld\n\n", (long long)(2.0 / program->zoom));
	return (0);
}
