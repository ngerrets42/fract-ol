/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:55:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 14:39:39 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

/*
**	Apply all the hooks.
*/
static void	apply_hooks(t_program *program)
{
	mlx_hook(program->window, 2, (1L << 0), hook_key_pressed, program);
	mlx_hook(program->window, 17, (1L << 17), hook_press_x, program);
	mlx_hook(program->window, 4, (1L << 4), hook_mouse, program);
}

int	main(int argc, char **argv)
{
	t_program	*program;

	program = program_init();
	if (program == NULL)
		return (1);
	if (parse(argc, argv, program) == 0)
	{
		free(program);
		return (1);
	}
	if (program_initialize_mlx(program) == 0)
		return (1);
	apply_hooks(program);
	fractal(program);
	mlx_loop(program->mlx);
	return (0);
}
