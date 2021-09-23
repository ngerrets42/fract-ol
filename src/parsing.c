/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 14:22:08 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/23 10:58:32 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

static void	print_fractals(void)
{
	printf("Available fractals are:\n");
	printf("	mandelbrot\n	julia\n	newton\n");
}

static void	parse_newton(int argc, t_program *program)
{
	program->fractal = FRACTAL_NEWTON;
	if (argc != 2)
	{
		printf("Error\n- Newton requires no additional arguments!\n");
		printf("Format: fract-ol newton\n");
		exit(1);
	}
}

static void	parse_mandelbrot(int argc, t_program *program)
{
	program->fractal = FRACTAL_MANDELBROT;
	if (argc != 2)
	{
		printf("Error\n- Mandelbrot requires no additional arguments!\n");
		printf("Format: fract-ol mandelbrot\n");
		exit(1);
	}
}

static void	parse_julia(int argc, char **argv, t_program *program)
{
	program->fractal = FRACTAL_JULIA;
	if (argc != 4)
	{
		printf("Error\n- Not correct amount of arguments for Julia fractal\n");
		printf("Format: fract-ol julia <Cx> <Cy>\n");
		exit(1);
	}
	program->arg1 = str_to_double(argv[2]);
	program->arg2 = str_to_double(argv[3]);
}

/*
**	Basic parsing of argv
*/
int	parse(int argc, char **argv, t_program *program)
{
	if (argc < 2)
	{
		printf("Error\n- Need at least an argument to specify the fractal.\n");
		print_fractals();
		return (0);
	}
	if (str_is_str("mandelbrot", argv[1]))
		parse_mandelbrot(argc, program);
	else if (str_is_str("newton", argv[1]))
		parse_newton(argc, program);
	else if (str_is_str("julia", argv[1]))
		parse_julia(argc, argv, program);
	else
	{
		printf("Error\n- Not a valid fractal!\n");
		print_fractals();
		return (0);
	}
	return (1);
}
