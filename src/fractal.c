/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 11:43:18 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 13:16:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static int	fractal_pixel(int x, int y, t_program *program)
{
	if (program->fractal == FRACTAL_MANDLEBROT)
		return (mandelbrot_pixel(x, y, program));
	if (program->fractal == FRACTAL_JULIA)
		return (julia_pixel(x, y, program));
	return (1);
}

int	fractal(t_program *program)
{
	int			x;
	int			y;
	int			c;
	long long	magni;

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
	magni = pow(2, program->zoomi);
	printf("Fractal Coordinates: (%.18Lf, %.18Lf)\n", program->cx, program->cy);
	printf("Zoom Factor: %.18Lf\nMagnification: %lld\n", program->zoom, magni);
	if (program->fractal == FRACTAL_JULIA)
		printf("Julia arguments REAL: %.18Lf IMAGINARY: %.18Lf\n", program->arg1, program->arg2);
	return (0);
}
