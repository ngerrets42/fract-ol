/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/30 15:10:56 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/30 15:13:24 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "program.h"

# define ITERATION_MAX 64
# define ZOOM_FACTOR 120

int	mandelbrot(t_program *program);
int	julia(t_program *program);

#endif
