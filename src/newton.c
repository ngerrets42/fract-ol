/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newton.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:30:25 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/23 10:58:08 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

#define ROOT_THREE 1.73205080757
#define TOLERANCE 0.001

/*
**	The base function for the newton fractal
*/
static t_complex	func(t_complex z)
{
	z = complex_pow(z, 3);
	z.re -= 1.0;
	return (z);
}

/*
**	Derivative of the base function
*/
static t_complex	derivative(t_complex z)
{
	z = complex_pow(z, 2);
	z.re *= 3;
	z.im *= 3;
	return (z);
}

/*
**	The roots to check in the newton fractal.
*/
static int	check_roots(t_complex z)
{
	int					i;
	t_complex			diff;
	static t_complex	rts[] =
	{
		{1, 0},
		{-0.5, ROOT_THREE * 0.5},
		{-0.5, -ROOT_THREE * 0.5}
	};

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

/*
**	The root that's closest to complex number z
*/
static int	closest_root(t_complex z)
{
	int					i;
	int					index;
	long double			dist;
	long double			cd;
	static t_complex	rts[] =
	{
		{1, 0},
		{-0.5, ROOT_THREE * 0.5},
		{-0.5, -ROOT_THREE * 0.5}
	};

	dist = 10.0;
	i = 0;
	index = 0;
	while (i < 3)
	{
		cd = complex_dist(z, rts[i]);
		if (cd < dist)
		{
			index = i + 1;
			dist = cd;
		}
		i++;
	}
	return (index);
}

/*
**	Pixel calculations for the newton fractal. newton fractal requires more
**	complex calculations.
*/
int	newton_pixel(int x, int y, t_program *program)
{
	t_complex	z;
	t_complex	z2;
	int			i;
	int			root;

	z = complex_coordinates(x, y, program);
	i = 0;
	while (i < program->iterations)
	{
		root = check_roots(z);
		if (root > 0)
			break ;
		z2 = complex_div(func(z), derivative(z));
		z.re -= z2.re;
		z.im -= z2.im;
		i++;
	}
	if (root == 0)
		root = closest_root(z);
	if (root == 0)
		return (C_BLACK);
	if (program->colormode == COLORMODE_NEWTON)
		return (color_from_iterations(root, 4, program));
	return (color_from_iterations(i, program->iterations, program));
}
