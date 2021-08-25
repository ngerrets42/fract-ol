/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:55:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 13:08:14 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

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
	apply_hooks(program);
	mandelbrot(program);
	mlx_loop(program->mlx);
	return (0);
}
