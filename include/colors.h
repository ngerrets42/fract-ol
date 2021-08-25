/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 13:29:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 13:35:42 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

int	colormap_get_trgb(int i);

#endif
