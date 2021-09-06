/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:43:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/06 15:43:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "complex_numbers.h"

t_complex	_complex(long double real, long double imaginair)
{
	return ((t_complex){real, imaginair});
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

	a = (n2.re * n2.re + n2.im * n2.im);
	r.re = (n1.re * n2.re + n1.im * n2.im) / a;
	r.im = (n1.im * n2.re - n1.re * n2.im) / a;
	return (r);
}

t_complex	complex_pow(t_complex n, unsigned int power)
{
	unsigned int	i;

	i = 1;
	while (i < power)
	{
		n = complex_mul(n, n);
		i++;
	}
	return (n);
}
