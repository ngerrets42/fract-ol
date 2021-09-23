/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 14:54:38 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/23 10:55:51 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

/*
**	Pixel calculations for the julia-fractal.
*/
int	julia_pixel(int x, int y, t_program *program)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = _complex((long double)program->arg1, (long double)program->arg2);
	z = complex_coordinates(x, y, program);
	i = 0;
	while (i < program->iterations)
	{
		z = complex_pow(z, 2);
		z.re += c.re;
		z.im += c.im;
		if (z.re * z.re + z.im * z.im > 4.0)
			break ;
		i++;
	}
	return (color_from_iterations(i, program->iterations, program));
}
