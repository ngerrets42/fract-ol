/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 15:10:56 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/09/06 15:21:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "program.h"
# include <math.h>
# include "colors.h"
# include "complex_numbers.h"

# define ITERATION_START 128
# define ZOOM_FACTOR 0.75
# define RE 0
# define IM 1

t_complex	complex_coordinates(int x, int y, t_program *program);
int	mandelbrot_pixel(int x, int y, t_program *program);
int	julia_pixel(int x, int y, t_program *program);
int	newton_pixel(int x, int y, t_program *program);
int	fractal(t_program *program);

#endif
