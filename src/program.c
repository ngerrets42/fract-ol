/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:03:46 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 12:09:03 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

/*
**	Create the window and the image for the window buffer.
*/
static void	program_initialize_window(t_program *program)
{
	program->window_w = 640;
	program->window_h = 640;
	program->window = mlx_new_window(program->mlx, program->window_w,
			program-> window_h, "fract-ol");
	if (program->window == NULL)
	{
		free(program);
		program = NULL;
		return ;
	}
	program->screen_buf = img_create(program, program->window_w, program->window_h);
	if (program->screen_buf == NULL)
		program = NULL;
}

/*
**	Allocate the program struct and initialize mlx.
*/
t_program	*program_initialize_mlx(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (program != NULL)
	{
		program->mlx = mlx_init();
		if (program->mlx == NULL)
		{
			free(program);
			program = NULL;
		}
		else
			program_initialize_window(program);
	}
	if (program == NULL)
		put("Error\n- Couldn't initialize the program!", NULL);
	program->cx = 0.0;
	program->cy = 0.0;
	program->zoom = DEFAULT_ZOOM;
	program->iterations = DEFAULT_ITERATIONS;
	program->zoomi = 0;
	return (program);
}


/*
**	Free and exit.
*/
void	program_quit(t_program *program)
{
	if (program != NULL)
	{
		mlx_destroy_window(program->mlx, program->window);
		img_destroy(program, program->screen_buf);
		free(program);
	}
	exit(0);
}

/*
**	Main program loop. Update animations, positions and draw the screen if necessary.
*/
int	program_loop(t_program *program)
{
	return (0);
}
