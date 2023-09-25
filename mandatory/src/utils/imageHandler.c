/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imageHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:34:35 by esalim            #+#    #+#             */
/*   Updated: 2023/09/25 10:40:51 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_pixels_color(t_color **pixelsColor)
{
	int	i;
	int	j;
	int	size;

	if (!pixelsColor)
		return ;
	j = 0;
	size = 0;
	i = 0;
	if (*pixelsColor)
		size = pixelsColor[i][0].size;
	while (pixelsColor[i])
	{
		j = 0;
		while (j < size)
		{
			printf("pixels Color red ==> {%d}\t", pixelsColor[i][j].red);
			printf("pixels Color green ==> {%d}\t", pixelsColor[i][j].green);
			printf("pixels Color blue ==> {%d}\t", pixelsColor[i][j].blue);
			printf("pixels Color alpha ==> {%d}\n", pixelsColor[i][j].alpha);
			j++;
		}
		printf("\n========================={%d}=======================\n", i);
		i++;
	}
}

unsigned long	get_color(t_color color)
{
	return (
		((color.red & 0xff) << 24) 
		+ ((color.green & 0xff) << 16) 
		+ ((color.blue & 0xff) << 8) 
		+ (color.alpha & 0xff)
	);
}

t_texture	*get_texture(const char *path)
{
	mlx_texture_t	*texture_image;
	unsigned char	***_3d_array;
	unsigned char	**_2d_array;
	t_texture		*texture;
	int				i;

	texture_image = mlx_load_png(path);
	if (!texture_image)
		return (NULL);
	texture = ft_calloc(sizeof(t_texture), 1);
	_2d_array = convert_texture_to_2d_array(texture_image->pixels, \
				texture_image->height, texture_image->width * 4);
	_3d_array = convert_2d_array_to_3d_array(texture_image, _2d_array);
	free_double_pointer((void *)_2d_array);
	texture->pixels = convert_3d_array_to_pixels_color(texture_image, \
														_3d_array);
	texture->height = texture_image->height;
	texture->width = texture_image->width;
	i = -1;
	while (_3d_array[++i])
		free_double_pointer((void *)_3d_array[i]);
	return (free(_3d_array), mlx_delete_texture(texture_image), texture);
}
