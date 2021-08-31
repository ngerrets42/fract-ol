/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 11:00:49 by ngerrets      #+#    #+#                 */
/*   Updated: 2021/08/31 13:07:04 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

/*
**	Allocates an img-struct with width/height and registers it with MLX.
*/
t_img	*img_create(t_program *program, int w, int h)
{
	t_img	*new_img;

	new_img = malloc(sizeof(t_img));
	if (new_img == NULL)
		return (NULL);
	new_img->width = w;
	new_img->height = h;
	new_img->img = mlx_new_image(program->mlx, w, h);
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bipp,
			&new_img->line_len, &new_img->endian);
	new_img->bypp = new_img->bipp / 8;
	return (new_img);
}

/*
**	Removes img-struct from MLX and frees the struct.
*/
void	img_destroy(t_program *program, t_img *img)
{
	mlx_destroy_image(program->mlx, img->img);
	free(img);
}

/*
**	Set the pixel at x/y of given img to given trgb value.
*/
void	img_set_pixel(t_img *img, int x, int y, int trgb)
{
	char	*addr;

	addr = img->addr + (y * img->line_len) + x * (img->bypp);
	*(int *)addr = trgb;
}
