/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:35:59 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/25 10:13:07 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	vue_x_y(t_image *image)
{
	image->vx = 1;
	image->vy = 1;
	if (image->ray_angle >= 0 && image->ray_angle < 180)
		image->vy *= 1;
	if (image->ray_angle >= 180)
		image->vy *= -1;
	if ((image->ray_angle >= 0 && image->ray_angle <= 90)
		|| image->ray_angle >= 270)
		image->vx *= 1;
	else
		image->vx *= -1;
}

void	press_w_key(t_image *image)
{
	if (check_draw_pixel_player(image, 3) == 1)
	{
		image->xposition_p += ((float)image->player_speed
				* (float)(TILESIZE / MINIMAPSIZE))
			* cos(image->angle * (M_PI / 180));
		image->yposition_p += ((float)image->player_speed
				* (float)(TILESIZE / MINIMAPSIZE))
			* sin(image->angle * (M_PI / 180));
		image->x_map += image->player_speed * cos(image->angle * (M_PI / 180));
		image->y_map += image->player_speed * sin(image->angle * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 3) == 4)
	{
		image->xposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle * (M_PI / 180));
		image->x_map += image->player_speed * cos(image->angle * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 3) == 5)
	{
		image->yposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle * (M_PI / 180));
		image->y_map += image->player_speed * sin(image->angle * (M_PI / 180));
	}
}

void	press_s_key(t_image *image)
{
	if (check_draw_pixel_player(image, 4) == 1)
	{
		image->xposition_p -= ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle * (M_PI / 180));
		image->yposition_p -= ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle * (M_PI / 180));
		image->x_map -= image->player_speed * cos(image->angle * (M_PI / 180));
		image->y_map -= image->player_speed * sin(image->angle * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 4) == 4)
	{
		image->xposition_p -= ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle * (M_PI / 180));
		image->x_map -= image->player_speed * cos(image->angle * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 4) == 5)
	{
		image->yposition_p -= ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle * (M_PI / 180));
		image->y_map -= image->player_speed * sin(image->angle * (M_PI / 180));
	}
}

void	press_a_key(t_image *image)
{
	if (check_draw_pixel_player(image, 2) == 1)
	{
		image->xposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle_left * (M_PI / 180));
		image->yposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle_left * (M_PI / 180));
		image->x_map += image->player_speed
			* cos(image->angle_left * (M_PI / 180));
		image->y_map += image->player_speed
			* sin(image->angle_left * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 2) == 4)
	{
		image->xposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle_left * (M_PI / 180));
		image->x_map += image->player_speed
			* cos(image->angle_left * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 2) == 5)
	{
		image->yposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle_left * (M_PI / 180));
		image->y_map += image->player_speed
			* sin(image->angle_left * (M_PI / 180));
	}
}

void	press_d_key(t_image *image)
{
	if (check_draw_pixel_player(image, 1) == 1)
	{
		image->xposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle_right * (M_PI / 180));
		image->yposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle_right * (M_PI / 180));
		image->x_map += image->player_speed
			* cos(image->angle_right * (M_PI / 180));
		image->y_map += image->player_speed
			* sin(image->angle_right * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 1) == 4)
	{
		image->xposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * cos(image->angle_right * (M_PI / 180));
		image->x_map += image->player_speed
			* cos(image->angle_right * (M_PI / 180));
	}
	else if (check_draw_pixel_player(image, 1) == 5)
	{
		image->yposition_p += ((float)image->player_speed * (float)(TILESIZE
					/ MINIMAPSIZE)) * sin(image->angle_right * (M_PI / 180));
		image->y_map += image->player_speed
			* sin(image->angle_right * (M_PI / 180));
	}
}
