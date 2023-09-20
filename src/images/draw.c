/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/20 22:53:53 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void vue_x_y(t_image *image)
{
	image->vx = 1;
	image->vy = 1;
	if (image->ray_angle >= 0 && image->ray_angle < 180)
		image->vy *= 1;
	if (image->ray_angle >= 180)
		image->vy *= -1;
	if ((image->ray_angle >= 0 && image->ray_angle <= 90) || image->ray_angle >= 270)
		image->vx *= 1;
	else
		image->vx *= -1;
}

void draw(t_image *image, int i)
{
	float distance_h;
	float distance_v;

	if (image->ray_angle < 0)
		image->ray_angle += 360;
	if (image->ray_angle > 360)
		image->ray_angle -= 360;
	vue_x_y(image);
	find_distance_verticale(image);
	find_distance_horizontal(image);
	distance_h = sqrt(pow((image->xhorizontal - image->xposition_p), 2) + pow((image->yhorizontal - image->yposition_p), 2));
	distance_v = sqrt(pow((image->xverticale - image->xposition_p), 2) + pow((image->yverticale - image->yposition_p), 2));
    if (distance_h > distance_v)
	{
		// if (image->angle > 180)
			draw_3D(image, distance_v, i, (int)image->yverticale % image->mapInfo.east->width, image->mapInfo.east);
	}
    else
	{
		// if (image->angle > 270)
		// 	draw_3D(image, distance_h, i, image->mapInfo.south->width - ((int)image->xhorizontal % image->mapInfo.south->width) - 1, image->mapInfo.south);
		// else
			draw_3D(image, distance_h, i, (int)image->xhorizontal % image->mapInfo.south->width, image->mapInfo.south);
		
	}
}

void draw_pixel_player(t_image *image)
{
	int d = 0;
	float angle;

	if (image->angle < 0)
		image->angle += 360;
	if (image->angle > 360)
		image->angle -= 360;
	angle = (float)60 / WIDTH;
	image->ray_angle = image->angle - 30;
	// ESALIM HERE
	while (d < WIDTH)
	{
		draw(image, d);
		image->ray_angle += angle;
		d++;
	}
}

void angle(t_image *image)
{
	image->angle_left = image->angle + 90;
	if (image->angle_left > 360)
		image->angle_left -= 360;
	if (image->angle_left < 0)
		image->angle_left += 360;
	image->angle_right = image->angle - 90;
	if (image->angle_right > 360)
		image->angle_right -= 360;
	if (image->angle_right < 0)
		image->angle_right += 360;
}

void drow_image(void *img)
{
	t_image *image;
	static float oldXPlayer;
	static float oldYPlayer;
	static float oldAngle;

	image = (t_image *)img;
//	================== KEY HOOKS ============================================
	{
		angle(image);
		if (mlx_is_key_down(image->mlx, MLX_KEY_W) && check_draw_pixel_player(image, 3) != 0)
		{
			image->xposition_p += ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * cos(image->angle * (M_PI / 180));
			image->yposition_p += ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * sin(image->angle * (M_PI / 180));
			image->xMap += image->playerSpeed * cos(image->angle * (M_PI / 180));
			image->yMap += image->playerSpeed * sin(image->angle * (M_PI / 180));
		}
		if (mlx_is_key_down(image->mlx, MLX_KEY_S) && check_draw_pixel_player(image, 4) != 0)
		{
			image->xposition_p -= ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * cos(image->angle * (M_PI / 180));
			image->yposition_p -= ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * sin(image->angle * (M_PI / 180));
			image->xMap -= image->playerSpeed * cos(image->angle * (M_PI / 180));
			image->yMap -= image->playerSpeed * sin(image->angle * (M_PI / 180));
		}
	
		if (mlx_is_key_down(image->mlx, MLX_KEY_D) && check_draw_pixel_player(image, 2) != 0)
		{
			image->xposition_p += ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * cos(image->angle_left * (M_PI / 180));
			image->yposition_p += ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * sin(image->angle_left * (M_PI / 180));
			image->xMap += image->playerSpeed * cos(image->angle_left * (M_PI / 180));
			image->yMap += image->playerSpeed * sin(image->angle_left * (M_PI / 180));
		}
		if (mlx_is_key_down(image->mlx, MLX_KEY_A) && check_draw_pixel_player(image, 1) != 0)
		{
			image->xposition_p += ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * cos(image->angle_right * (M_PI / 180));
			image->yposition_p += ((float)image->playerSpeed * (float)(TILESIZE / MINIMAPSIZE)) * sin(image->angle_right * (M_PI / 180));
			image->xMap += image->playerSpeed * cos(image->angle_right * (M_PI / 180));
			image->yMap += image->playerSpeed * sin(image->angle_right * (M_PI / 180));
		}
		if (mlx_is_key_down(image->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(image->mlx);
		if (mlx_is_key_down(image->mlx, MLX_KEY_LEFT))
			image->angle -= image->angleSpeed;
		if (mlx_is_key_down(image->mlx, MLX_KEY_RIGHT))
			image->angle += image->angleSpeed;
	}
//	========================================================================================================================

	if (oldXPlayer != image->xMap || oldYPlayer != image->yMap || oldAngle != image->angle)
	{
		draw_pixel_player(image);
		if (image->displayMiniMap == ENABLE)
			drawDynamicMap(image);
		oldXPlayer = image->xMap;
		oldYPlayer = image->yMap;
		oldAngle = image->angle;
		// exit(0);
	}
	// else if (oldAngle != image->angle)
	// {
	// 	draw_pixel(0, image, 110, 110);
	// 	drawPlayer(image, 110, 110);
	// }
	
}
