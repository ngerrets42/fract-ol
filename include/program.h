/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:58:59 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 13:41:55 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "../lib/mlx_mac/mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include "str.h"

# define DEFAULT_ZOOM 1.0
# define DEFAULT_ITERATIONS 64

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
	void	*mlx;
	void	*window;
	int		window_w;
	int		window_h;
	double	cx;
	double	cy;
	double	zoom;
	int		iterations;
	t_img	*screen_buf;
}	t_program;

t_img	*img_create(t_program *program, int w, int h);
void	img_destroy(t_program *program, t_img *img);
void	img_set_pixel(t_img *img, int x, int y, int trgb);

t_program	*program_initialize_mlx(void);
void	program_quit(t_program *program);
int	program_loop(t_program *program);

int	hook_key_pressed(int key, t_program *program);
int	hook_press_x(t_program *program);

#endif
