/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:43:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 12:28:48 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "complex_numbers.h"

t_complex	_complex(long double real, long double imaginair)
{
	t_complex	c;

	c.re = real;
	c.im = imaginair;
	return (c);
}

t_complex	complex_mul(t_complex n1, t_complex n2)
{
	t_complex	r;

	r.re = n1.re * n2.re - n1.im * n2.im;
	r.im = n1.re * n2.im + n2.re * n1.im;
	return (r);
}

t_complex	complex_div(t_complex n1, t_complex n2)
{
	t_complex	r;
	long double	a;
	long double	b;

	if (fabsl(n2.im) < fabsl(n2.re))
	{
		a = n2.im / n2.re;
		b = n2.re + n2.im * a;
		r.re = (n1.re + n1.im * a) / b;
		r.im = (n1.im - n1.re * a) / b;
	}
	else
	{
		a = n2.re / n2.im;
		b = n2.im + n2.re * a;
		r.re = (n1.im + n1.re * a) / b;
		r.im = (-n1.re + n1.im * a) / b;
	}
	return (r);
}

long double	complex_dist(t_complex z1, t_complex z2)
{
	long double	dr;
	long double	di;

	dr = z1.re - z2.re;
	di = z1.im - z2.im;
	return (dr * dr + di * di);
}

t_complex	complex_pow(t_complex n, unsigned int power)
{
	unsigned int	i;
	t_complex		r;

	i = 1;
	r = n;
	while (i < power)
	{
		r = complex_mul(r, n);
		i++;
	}
	return (r);
}
