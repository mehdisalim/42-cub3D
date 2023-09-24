/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:47:43 by esalim            #+#    #+#             */
/*   Updated: 2023/09/21 14:53:14 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

unsigned char	**convert_texture_to_2d_array(
	unsigned char *srcArray, int height, int width)
{
	unsigned char	**_2d_array;
	int				i;
	int				j;
	int				x;

	j = 0;
	if (!srcArray)
		return (NULL);
	_2d_array = ft_calloc(height + 1, sizeof(unsigned char *));
	i = 0;
	x = 0;
	while (i < height)
	{
		j = 0;
		_2d_array[i] = ft_calloc(width + 1, sizeof(unsigned char));
		while (j < width)
			_2d_array[i][j++] = srcArray[x++];
		i++;
	}
	return (_2d_array);
}

unsigned char	***convert_2d_array_to_3d_array(
	mlx_texture_t *texture, unsigned char **_2DArray)
{
	unsigned char	***_3d_array;
	int				p;
	int				i;
	int				j;

	if (!_2DArray)
		return (NULL);
	p = 0;
	i = -1;
	j = 0;
	_3d_array = ft_calloc(texture->height + 1, sizeof(unsigned char **));
	while (++i < (int)texture->height)
	{
		j = 0;
		_3d_array[i] = ft_calloc(texture->width + 1, sizeof(unsigned char *));
		while (j < (int)texture->width * 4)
		{
			_3d_array[i][j / 4] = ft_calloc(5, sizeof(unsigned char));
			ft_memcpy(_3d_array[i][j / 4], _2DArray[i] + j, sizeof(char) * 4);
			j += 4;
		}
		p++;
	}
	return (_3d_array);
}

t_color	**convert_3d_array_to_pixels_color(
	mlx_texture_t *texture, unsigned char ***_3DArray)
{
	t_color	**pixels_colors;
	int		i;
	int		j;
	int		a;

	if (!_3DArray)
		return (NULL);
	pixels_colors = ft_calloc(texture->height + 1, sizeof(t_color *));
	i = -1;
	while (++i < (int)texture->height)
	{
		j = 0;
		pixels_colors[i] = ft_calloc(texture->width + 1, sizeof(t_color));
		while (j < (int)texture->width * 4)
		{
			a = j / 4;
			pixels_colors[i][a].red = _3DArray[i][a][0];
			pixels_colors[i][a].green = _3DArray[i][a][1];
			pixels_colors[i][a].blue = _3DArray[i][a][2];
			pixels_colors[i][a].alpha = _3DArray[i][a][3];
			pixels_colors[i][a].size = texture->width;
			j += 4;
		}
	}
	return (pixels_colors);
}
