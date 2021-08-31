/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 15:10:56 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 12:02:16 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "program.h"
# include <math.h>
# include "colors.h"

# define ITERATION_START 128
# define ITERATION_GROWTH 16
# define ZOOM_FACTOR 120
# define RE 0
# define IM 1

int	mandelbrot_pixel(int x, int y, t_program *program);
int	julia_pixel(int x, int y, t_program *program);
int	fractal(t_program *program);

#endif
