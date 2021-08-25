/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:55:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 11:09:06 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	program = program_initialize_mlx(); 
	mandelbrot(program);
	return (0);
}
