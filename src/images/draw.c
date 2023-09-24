/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 17:05:19 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	check_distance(t_image *image, int i, float distance_h,
		float distance_v)
{
	if (distance_h > distance_v)
	{
		image->position = image->yverticale
			- (int)((int)((int)image->yverticale / TILESIZE) *TILESIZE);
		if (image->vx == -1)
			draw_3D(image, distance_v, i, image->mapInfo.west->width
				- (image->position * (image->mapInfo.west->width / TILESIZE))
				- 1, image->mapInfo.west);
		else
			draw_3D(image, distance_v, i, image->position
				* (image->mapInfo.east->width / TILESIZE), image->mapInfo.east);
	}
	else
	{
		image->position = image->xhorizontal
			- ((int)((int)image->xhorizontal / TILESIZE) *TILESIZE);
		if (image->vy == -1)
			draw_3D(image, distance_h, i, image->position
				* (image->mapInfo.north->width / TILESIZE),
				image->mapInfo.north);
		else
			draw_3D(image, distance_h, i, image->mapInfo.south->width
				- (image->position * (image->mapInfo.south->width / TILESIZE))
				- 1, image->mapInfo.south);
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
	check_distance(image, i, distance_h, distance_v);
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

void	check_key(t_image *image)
{
	if (mlx_is_key_down(image->mlx, MLX_KEY_W))
		press_w_key(image);
	if (mlx_is_key_down(image->mlx, MLX_KEY_S))
		press_s_key(image);
	if (mlx_is_key_down(image->mlx, MLX_KEY_D))
		press_a_key(image);
	if (mlx_is_key_down(image->mlx, MLX_KEY_A))
		press_d_key(image);
	if (mlx_is_key_down(image->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(image->mlx);
	if (mlx_is_key_down(image->mlx, MLX_KEY_LEFT))
		image->angle -= image->angleSpeed;
	if (mlx_is_key_down(image->mlx, MLX_KEY_RIGHT))
		image->angle += image->angleSpeed;
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
	if (oldxplayer != image->xMap || oldyplayer != image->yMap
		|| oldangle != image->angle)
	{
		draw_pixel_player(image);
		if (image->displayMiniMap == ENABLE)
			drawDynamicMap(image);
		oldxplayer = image->xMap;
		oldyplayer = image->yMap;
		oldangle = image->angle;
	}
}
