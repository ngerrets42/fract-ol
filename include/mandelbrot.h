/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 10:54:14 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/25 13:12:36 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "program.h"

# define ITERATION_MAX 1000
# define ZOOM_FACTOR 120

int	mandelbrot(t_program *program);

#endif