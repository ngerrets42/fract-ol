/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newton.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:30:25 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/06 16:03:04 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

#define ROOT_THREE 1.73205080757
#define TOLERANCE 0.000001

static t_complex	*roots(void)
{
	static t_complex	roots[3] =
	{
		{1.0, 0},
		{-0.5, ROOT_THREE / 2.0},
		{-0.5, -ROOT_THREE / 2.0}
	};

	return (roots);
}

static t_complex	func(t_complex z)
{
	z = complex_pow(z, 3);
	z.re -= 1.0;
	return (z);
}

static t_complex	derivative(t_complex z)
{
	z = complex_mul(z, z);
	z.re *= 3;
	z.im *= 3;
	return (z);
}

static int	check_roots(t_complex z)
{
	int			i;
	t_complex	diff;
	t_complex	*rts;

	rts = roots();
	i = 0;
	while (i < 3)
	{
		diff.re = z.re - rts[i].re;
		diff.im = z.im - rts[i].im;
		if (fabsl(diff.re) < TOLERANCE && fabsl(diff.im) < TOLERANCE)
			return (i + 1);
		i++;
	}
	return (0);
}

int	newton_pixel(int x, int y, t_program *program)
{
	t_complex	z;
	t_complex	z2;
	int			i;
	int			root;

	z = complex_coordinates(x, y, program);
	i = 0;
	while (i < 16)
	{
		z2 = complex_div(func(z), derivative(z));
		z.re -= z2.re;
		z.im -= z2.im;
		root = check_roots(z);
		if (root > 0)
			break;
		i++;
	}
	return (color_from_iterations(root, 16, program));
}
