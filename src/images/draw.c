/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 21:45:48 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	draw_vertical(t_image *image, float distance_v, int i)
{
	int	arr[2];

	arr[0] = i;
	image->position = image->yverticale
		- (int)((int)((int)image->yverticale / TILESIZE) *TILESIZE);
	if (image->vx == -1)
	{
		arr[1] = image->map_info.west->width - (image->position \
						* (image->map_info.west->width / TILESIZE)) - 1;
		draw_3d(image, distance_v, arr, image->map_info.west);
	}
	else
	{
		arr[1] = image->position * (image->map_info.east->width / TILESIZE);
		draw_3d(image, distance_v, arr, image->map_info.east);
	}
}

void	draw_horizontal(t_image *image, float distance_h, int i)
{
	int	arr[2];

	arr[0] = i;
	image->position = image->xhorizontal
		- ((int)((int)image->xhorizontal / TILESIZE) *TILESIZE);
	if (image->vy == -1)
	{
		arr[1] = image->position * (image->map_info.north->width / TILESIZE);
		draw_3d(image, distance_h, arr, image->map_info.north);
	}
	else
	{
		arr[1] = image->map_info.south->width - (image->position \
						* (image->map_info.south->width / TILESIZE)) - 1;
		draw_3d(image, distance_h, arr, image->map_info.south);
	}
}

void	draw(t_image *image, int i)
{
	float	distance_h;
	float	distance_v;

	if (image->ray_angle < 0)
		image->ray_angle += 360;
	if (image->ray_angle > 360)
		image->ray_angle -= 360;
	vue_x_y(image);
	find_distance_verticale(image);
	find_distance_horizontal(image);
	distance_h = sqrt(pow((image->xhorizontal - image->xposition_p), 2)
			+ pow((image->yhorizontal - image->yposition_p), 2));
	distance_v = sqrt(pow((image->xverticale - image->xposition_p), 2)
			+ pow((image->yverticale - image->yposition_p), 2));
	if (distance_h > distance_v)
		draw_vertical(image, distance_v, i);
	else
		draw_horizontal(image, distance_h, i);
}

void	draw_pixel_player(t_image *image)
{
	int		d;
	float	angle;

	d = 0;
	if (image->angle < 0)
		image->angle += 360;
	if (image->angle > 360)
		image->angle -= 360;
	angle = (float)60 / WIDTH;
	image->ray_angle = image->angle - 30;
	while (d < WIDTH)
	{
		draw(image, d);
		image->ray_angle += angle;
		d++;
	}
}

void	draw_image(void *img)
{
	t_image			*image;
	static float	oldxplayer;
	static float	oldyplayer;
	static float	oldangle;

	image = (t_image *)img;
	angle(image);
	check_key(image);
	if (oldxplayer != image->x_map || oldyplayer != image->y_map
		|| oldangle != image->angle)
	{
		draw_pixel_player(image);
		if (image->display_mini_map == ENABLE)
			draw_dynamic_map(image);
		oldxplayer = image->x_map;
		oldyplayer = image->y_map;
		oldangle = image->angle;
	}
}
