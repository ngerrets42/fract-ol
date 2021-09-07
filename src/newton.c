/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newton.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:30:25 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 12:51:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

#define ROOT_THREE 1.73205080757
#define TOLERANCE 0.001

static t_complex	*roots(void)
{
	static t_complex	roots[] =
	{
		{1, 0},
		{-0.5, ROOT_THREE * 0.5},
		{-0.5, -ROOT_THREE * 0.5}
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
	z = complex_pow(z, 2);
	z.re *= 3;
	z.im *= 3;
	return (z);
}

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

/*
int	newton_pixel(int x, int y, t_program *program)
{
	t_complex	z;
	t_complex	z2;
	int			i;
	int			root;

	z = complex_coordinates(x, y, program);
	i = 0;
	while (i < 50)
	{
		z2 = complex_div(func(z), derivative(z));
		if (fabsl(z2.re) < TOLERANCE && fabsl(z2.im) < TOLERANCE)
			break ;
		z.re -= z2.re;
		z.im -= z2.im;
		i++;
	}
	root = closest_root
(z);
	if (root == 0)
		return (C_BLACK);
	return (color_from_iterations(root, 16, program));
}*/
