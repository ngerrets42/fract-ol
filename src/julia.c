/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 14:54:38 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/01 16:22:21 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	julia_pixel(int x, int y, t_program *program)
{
	long double	c[2];
	long double	z[2];
	long double	len;
	long double	z_old[2];
	int			i;

	c[RE] = (long double)program->arg1;
	c[IM] = (long double)program->arg2;
	len = 2.0 * program->zoom;
	z[RE] = program->cx + ((long double)x / \
			(long double)program->window_w - 0.5) * len;
	z[IM] = program->cy + ((long double)y / \
			(long double)program->window_w - 0.5) * len;
	i = 0;
	while (i < program->iterations)
	{
		z_old[RE] = z[RE];
		z_old[IM] = z[IM];
		z[RE] = z_old[RE] * z_old[RE] - z_old[IM] * z_old[IM] + c[RE];
		z[IM] = 2 * z_old[RE] * z_old[IM] + c[IM];
		if (z[RE] * z[RE] + z[IM] * z[IM] > 4)
			break ;
		i++;
	}
	return (color_from_iterations(i, program->iterations, program));
}
