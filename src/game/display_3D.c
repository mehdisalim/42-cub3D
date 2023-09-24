/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:27:31 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 21:01:47 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	*get_data_from_elements(t_elements *elements, char *data)
{
	int	i;

	i = -1;
	while (elements[++i].name)
		if (!ft_strncmp(elements[i].name, data, ft_strlen(data)))
			return (elements[i].value.color);
	return (NULL);
}

void	draw_texture(t_image *image, t_texture *texture, int arr[2], float pj)
{
	float	offset_y;
	float	start;
	float	y_pos;
	int		y;

	start = (HEIGHT / 2) - (pj / 2);
	if (start < 0)
		start = 0;
	y = 0;
	offset_y = texture->height / pj;
	y_pos = offset_y * (pj / 2 - HEIGHT / 2);
	if (y_pos < 0)
		y_pos = 0;
	while (y < pj && y < HEIGHT)
	{
		mlx_put_pixel(image->img, arr[0], y + start, \
							get_color(texture->pixels[(int)y_pos][arr[1]]));
		y_pos += offset_y;
		if (y_pos >= texture->height)
			y_pos = 0;
		y++;
	}
}

void	draw_3d(t_image *image, float ray, int arr[2], t_texture *texture)
{
	float	start;
	float	pj;
	int		y;

	pj = (HEIGHT * TILESIZE) / (ray * cos((image->ray_angle - image->angle) \
											* (M_PI / 180))) * 1.5;
	start = (HEIGHT / 2) - (pj / 2);
	if (start < 0)
		start = 0;
	y = 0;
	while (y < start)
		mlx_put_pixel(image->img, arr[0], y++, image->map_info.ceiling_color);
	y = pj + start;
	while (y < HEIGHT)
		mlx_put_pixel(image->img, arr[0], y++, image->map_info.floor_color);
	draw_texture(image, texture, arr, pj);
}
