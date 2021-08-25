/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:12:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 13:42:34 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"
#include "colors.h"

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
	double	c_r;
	double	c_x;
	double	z_r;
	double	z_r_old;
	double	z_x;
	int		i;

	//x = -program->window_w * 0.5 + x + program->shiftx - program->zoom * 0.5;
	//y = -program->window_h * 0.5 + y + program->shifty - program->zoom * 0.5;
	//x0 = cx + (i/width - 0.5)*lx;
	int w = program->window_w;
	double lx = 2.0 * program->zoom;
	c_r = program->cx + ( (double)x / (double)w - 0.5) * lx;
	c_x = program->cy + ( (double)y / (double)w - 0.5) * lx;
	z_x = 0;
	z_r = 0;
	z_r_old = 0;
	i = 0;
	while (i < program->iterations && z_r < 2.0)
	{
		z_r_old = z_r;
		z_r = z_r * z_r + (double)-1 * (z_x * z_x) + c_r;
		z_x = 2.0 * z_r_old * z_x + c_x;
		i++;
	}
	//if (z_r > 2.0)
		//return (C_WHITE);
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
	printf("Mandelbrot Coordinates: (%.13lf, %.13lf)\nZoom Factor: %.13lf\n", program->cx, program->cy, program->zoom);
	return (0);
}
