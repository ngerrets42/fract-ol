/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 13:29:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/07 12:46:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "program.h"

# define HUE_START 0.5
# define C_BLACK 0x00000000

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

t_rgb	colormap_3_get(int i);
t_rgb	colormap_16_get(int i);
int		colormap_get_trgb(t_rgb(*colormap)(int), int i);
int		color_from_iterations(int i, int max_iterations, t_program *program);

#endif
