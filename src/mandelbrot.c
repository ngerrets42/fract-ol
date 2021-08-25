/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:12:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 14:43:27 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"
#include "colors.h"
#include <math.h>

#define C_WHITE 0x00ffffff
#define C_BLACK 0x00000000

static int mandelbrot_greyscale(int i)
{
	float	factor;
	int	r;
	int	g;
	int	b;
	int	base;
	
	if (i >= ITERATION_MAX)
		return (C_WHITE);
	base = 128;
	factor = (float)i / ITERATION_MAX;
	r = base * factor;
	g = base * factor;
	b = base * factor;
	return (0 << 24 | r << 16 | g << 8 | b);
	//return (0x00FF0000);
}

static int	mandelbrot_color(int i, int max_iterations)
{
	if (i >= max_iterations)
		return (C_BLACK);
	return (colormap_get_trgb(i));
}

static int	mandelbrot_pixel(int x, int y, t_program *program)
{
	long double	c[2];
	long double	z[2];
	long double	z_old;
	long double	len;
	int			i;

	len = 2.0 * program->zoom;
	c[0] = program->cx + ((long double)x /
		(long double)program->window_w - 0.5) * len;
	c[1] = program->cy + ((long double)y /
		(long double)program->window_w - 0.5) * len;
	z[0] = 0;
	z[1] = 0;
	z_old = 0;
	i = 0;
	while (i < program->iterations && z[0] < 2.0)
	{
		z_old = z[0];
		z[0] = z[0] * z[0] + -1.0 * (z[1] * z[1]) + c[0];
		z[1] = 2.0 * z_old * z[1] + c[1];
		i++;
	}
	return (mandelbrot_color(i, program->iterations));
}

int	mandelbrot(t_program *program)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	while (y < program->window_h)
	{
		x = 0;
		while (x < program->window_w)
		{
			c = mandelbrot_pixel(x, y, program);
			img_set_pixel(program->screen_buf, x, y, c);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(program->mlx, program->window,
		program->screen_buf->img, 0, 0);
	long long magni = pow(2, program->zoomi);
	printf("Mandelbrot Coordinates: (%.18Lf, %.18Lf)\n", program->cx, program->cy);
	printf("Zoom Factor: %.18Lf\nMagnification: %lld\n", program->zoom, magni);
	return (0);
}
