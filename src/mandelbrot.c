/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:12:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/23 10:56:20 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

/*
**	Pixel calculations for the famous mandelbrot fractal
*/
int	mandelbrot_pixel(int x, int y, t_program *program)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = complex_coordinates(x, y, program);
	z = _complex(0.0, 0.0);
	i = 0;
	while (i < program->iterations && fabsl(z.re) < 2.0)
	{
		z = complex_pow(z, 2);
		z.re += c.re;
		z.im += c.im;
		i++;
	}
	return (color_from_iterations(i, program->iterations, program));
}
