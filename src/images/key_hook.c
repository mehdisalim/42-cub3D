/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:35:28 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/13 09:53:02 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3.h"

void	angle(t_image *image)
{
	image->angle_left = image->angle + 90;
	if (image->angle_left > 360)
		image->angle_left -= 360;
	else if (image->angle_left < 0)
		image->angle_left += 360;
	image->angle_right = image->angle - 90;
	if (image->angle_right > 360)
		image->angle_right -= 360;
	else if (image->angle_right< 0)
		image->angle_right += 360;
}

void	key_hook2(mlx_key_data_t keydata, t_image *image)
{
	angle(image);
	if (keydata.key == 68 && check_draw_pixel_player(image, 2) != 0)
	{
		image->xposition_p += image->playerSpeed * cos(image->angle_left * (M_PI/180));
		image->yposition_p += image->playerSpeed * sin(image->angle_left * (M_PI/180));
	}
	if (keydata.key == 65 && check_draw_pixel_player(image, 1) != 0)
	{
		image->xposition_p += image->playerSpeed * cos(image->angle_right * (M_PI/180));
		image->yposition_p += image->playerSpeed * sin(image->angle_right * (M_PI/180));
	}
	if (keydata.key == 263)
		image->angle -= image->angleSpeed;
	if (keydata.key == 262)
		image->angle += image->angleSpeed;
	mlx_delete_image(image->mlx, image->img);
	image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(image->mlx, image->img, 0, 0);
	mlx_delete_image(image->mlx, image->screen_img);
	image->screen_img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(image->mlx, image->screen_img, 0, 0);
}

void	key_hook(mlx_key_data_t keydata, void *para)
{
	t_image *image;

	image = (t_image *)para;
	// printf("[%d]\n", keydata.key);
	if (keydata.key == 256)
	{
		mlx_delete_image(image->mlx, image->img);
		exit(0);
	}
	// if (keydata.key == 73 && image->playerSpeed + 2 < 20)
	// 		image->playerSpeed += 2;
	// if (keydata.key == 79 && image->playerSpeed - 2 > 2)
	// 	image->playerSpeed -= 2;
	// if (keydata.key == 73)
	// 	image->playerSpeed += 2;
	// if (keydata.key == 73)
	// 	image->playerSpeed += 2;
	if (keydata.key == 83 && check_draw_pixel_player(image, 4) != 0)
	{
		image->xposition_p -= image->playerSpeed * cos(image->angle * (M_PI/180));
		image->yposition_p -= image->playerSpeed * sin(image->angle * (M_PI/180));
	}
	if (keydata.key == 87 && check_draw_pixel_player(image, 3) != 0)
	{
		image->xposition_p += image->playerSpeed * cos(image->angle * (M_PI/180));
		image->yposition_p += image->playerSpeed * sin(image->angle * (M_PI/180));
	}
	key_hook2(keydata, image);	
}