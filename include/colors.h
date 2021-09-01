/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 13:29:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/01 16:27:19 by ngerrets      ########   odam.nl         */
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

int	colormap_get_trgb(int i);
int	color_from_iterations(int i, int max_iterations, t_program *program);

#endif
