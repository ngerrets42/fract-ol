/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbulb.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 16:42:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/01 18:20:15 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

#define MANDELBULB_BAILOUT 2.0
#define MANDELBULB_POWER 2

/*int	mandelbrot_pixel(int x, int y, t_program *program)
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
}*/

#define THETA_ADD 0.098
#define PHI_ADD 0.18

int	mandelbulb_pixel(int x, int y, t_program *program)
{
	long double z[3];
	long double r;
	int			i;
	long double c[2];

	c[RE] = program->cx + ((long double)x / (long double)program->window_w - 0.5) * 2.0 * program->zoom;
	c[IM] = program->cy + ((long double)y / (long double)program->window_h - 0.5) * 2.0 * program->zoom;
	z[0] = c[RE];
	z[1] = c[IM];
	z[2] = z[1] * 3.6;
	i = 0;
	r = 0;
	while (i < program->iterations && fabsl(r) < 3.7 * (c[RE] * c[RE] + c[IM] * c[IM]))
	{
		r = sqrtl(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
		long double theta = atanl(z[2] / sqrt(z[0] * z[0] + z[1] * z[1])) + THETA_ADD;
		long double phi = atanl(z[1] / z[0]) + PHI_ADD;
		z[0] = powl(r, MANDELBULB_POWER)
			* cosl(MANDELBULB_POWER * phi) * cosl(MANDELBULB_POWER * theta);
		z[1] = powl(r, MANDELBULB_POWER)
			* sinl(MANDELBULB_POWER * phi) * cosl(MANDELBULB_POWER * theta);
		z[2] = powl(r, MANDELBULB_POWER)
			* sinl(MANDELBULB_POWER * theta);
		z[0] += i * 0.002;
		z[1] += i * 0.002;
		i++;
	}
	return (color_from_iterations(i * r, program->iterations, program));
}
