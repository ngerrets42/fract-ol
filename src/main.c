/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:55:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 13:03:30 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include <stdio.h>

static void	print_fractals(void)
{
	printf("Available fractals are:\n");
	printf("	mandelbrot (void)\n	julia (double, double)\n");
}

static void	parse_julia(int argc, char **argv, t_program *program)
{
	program->fractal = FRACTAL_JULIA;
	if (argc != 4)
	{
		printf("Error\n- julia fractal needs a max of 2 addition arguments\n");
		program_quit(program);
	}
	program->arg1 = str_to_double(argv[2]);
	program->arg2 = str_to_double(argv[3]);
}

static int	parse(int argc, char **argv, t_program *program)
{
	if (argc < 2)
	{
		printf("Error\n- Need at least an argument to specify the fractal.\n");
		print_fractals();
		return (1);
	}
	if (str_is_str("mandelbrot", argv[1]))
	{
		program->fractal = FRACTAL_MANDLEBROT;
		if (argc != 2)
		{
			printf("Error\n- Mandelbrot requires no additional arguments!\n");
			program_quit(program);
		}
	}
	else if (str_is_str("julia", argv[1]))
		parse_julia(argc, argv, program);
	else
	{
		printf("Error\n- Not a valid fractal!\n");
		print_fractals();
		return (1);
	}
	return (0);
}

/*
**	Apply all the hooks.
*/
static void	apply_hooks(t_program *program)
{
	mlx_loop_hook(program->mlx, program_loop, program);
	mlx_hook(program->window, 2, (1L << 0), hook_key_pressed, program);
	mlx_hook(program->window, 17, (1L << 17), hook_press_x, program);
}

int	main(int argc, char **argv)
{
	t_program	*program;

	program = program_initialize_mlx();
	if (parse(argc, argv, program) == 1)
		program_quit(program);
	apply_hooks(program);
	fractal(program);
	mlx_loop(program->mlx);
	return (0);
}
