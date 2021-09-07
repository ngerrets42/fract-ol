/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:58:59 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 14:37:05 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "../lib/mlx_mac/mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "str.h"

# define DEFAULT_ZOOM 2.0
# define DEFAULT_ITERATIONS 128

typedef enum e_fractal
{
	FRACTAL_MANDELBROT,
	FRACTAL_JULIA,
	FRACTAL_NEWTON
}	t_fractal;

typedef enum e_colormode
{
	COLORMODE_SIMPLE,
	COLORMODE_HUE,
	COLORMODE_GREYSCALE,
	COLORMODE_NEWTON,
	COLORMODE_COUNT
}	t_colormode;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bipp;
	int		bypp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_program
{
	void		*mlx;
	void		*window;
	int			window_w;
	int			window_h;
	long double	cx;
	long double	cy;
	long double	zoom;
	int			iterations;
	t_img		*screen_buf;
	t_fractal	fractal;
	t_colormode	colormode;
	long double	arg1;
	long double	arg2;
}	t_program;

int			parse(int argc, char **argv, t_program *program);

t_img		*img_create(t_program *program, int w, int h);
void		img_destroy(t_program *program, t_img *img);
void		img_set_pixel(t_img *img, int x, int y, int trgb);

t_program	*program_init(void);
int			program_initialize_mlx(t_program *program);
void		program_quit(t_program *program);

int			hook_key_pressed(int key, t_program *program);
int			hook_mouse(int key, int x, int y, t_program *program);
int			hook_press_x(t_program *program);

#endif
