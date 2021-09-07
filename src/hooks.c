/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 10:59:09 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 14:44:15 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "keycodes.h"
#include "fractals.h"

/*
**	Key pressed hook. Used to exit the program (esc) or move/zoom
*/
int	hook_key_pressed(int key, t_program *program)
{
	if (key == KEY_ESC)
		program_quit(program);
	if (key == KEY_A)
		program->cx -= 0.5 * program->zoom;
	if (key == KEY_D)
		program->cx += 0.5 * program->zoom;
	if (key == KEY_W)
		program->cy -= 0.5 * program->zoom;
	if (key == KEY_S)
		program->cy += 0.5 * program->zoom;
	if (key == KEY_Z)
		program->iterations *= 2;
	if (key == KEY_X)
		program->iterations *= 0.5;
	if (key == KEY_Q)
		(program->colormode)++;
	if (key == KEY_SPACE)
		program->zoom *= 0.5;
	if (program->colormode == COLORMODE_COUNT)
		program->colormode = 0;
	fractal(program);
	return (0);
}

/*
**	Sets the programs complex-plane coordinates according to x, y and zoom
*/
static void	set_center(int x, int y, t_program *program)
{
	program->cx += ((long double)x / \
		(long double)program->window_w - 0.5) * 2.0 * program->zoom;
	program->cy += ((long double)y / \
		(long double)program->window_w - 0.5) * 2.0 * program->zoom;
}

/*
**	Sets the programs complex-plane coordinates in order to zoom smoothly to
**	the mouse position.
*/
static void	set_cpos(int x, int y, t_program *program)
{
	long double	c[2];
	long double	t1[2];
	long double	t2[2];

	t1[RE] = program->cx + ((long double)x / \
		(long double)program->window_w - 0.5) * program->zoom;
	t1[IM] = program->cy + ((long double)y / \
		(long double)program->window_w - 0.5) * program->zoom;
	t2[RE] = program->cx + ((long double)x / \
		(long double)program->window_w - 0.5) * (program->zoom * ZOOM_FACTOR);
	t2[IM] = program->cy + ((long double)y / \
		(long double)program->window_w - 0.5) * (program->zoom * ZOOM_FACTOR);
	c[RE] = program->cx + (t1[RE] - t2[RE]) * 2.0;
	c[IM] = program->cy + (t1[IM] - t2[IM]) * 2.0;
	program->cx = c[RE];
	program->cy = c[IM];
}

/*
**	Mouse buttons window X hook. Used to zoom.
*/
int	hook_mouse(int key, int x, int y, t_program *program)
{
	if (key == KEY_MB_SCROLLDOWN)
	{
		y = program->window_h - y;
		program->zoom /= (long double)ZOOM_FACTOR;
	}
	if (key == KEY_MB_SCROLLUP)
	{
		y = program->window_h - y;
		set_cpos(x, y, program);
		program->zoom *= (long double)ZOOM_FACTOR;
	}
	if (key == KEY_MB_LEFT)
		set_center(x, y, program);
	fractal(program);
	return (0);
}

/*
**	Press the window X hook. Used to exit the program.
*/
int	hook_press_x(t_program *program)
{
	program_quit(program);
	return (0);
}
