/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:35:28 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 19:06:54 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	angle(t_image *image)
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

void	key_hook(mlx_key_data_t keydata, void *para)
{
	t_image				*image;
	static unsigned int	a;

	image = (t_image *)para;
	a++;
	if (keydata.key == MLX_KEY_M && a % 2)
	{
		if (image->display_mini_map == ENABLE)
		{
			mlx_delete_image(image->mlx, image->map_screen);
			image->map_screen = mlx_new_image(image->mlx, 220, 220);
			mlx_image_to_window(image->mlx, image->map_screen, 0, HEIGHT - 220);
		}
		else
			draw_dynamic_map(image);
		image->display_mini_map = !image->display_mini_map;
	}
	if (keydata.key == MLX_KEY_C && a % 2)
		image->allowed_cursor = !image->allowed_cursor;
	if (keydata.key == 61 && a % 2 && image->player_speed < 10)
		++image->player_speed;
	if (keydata.key == 45 && a % 2 && image->player_speed > 3)
		--image->player_speed;
}

	// if (keydata.key == MLX_KEY_G && a % 2)
	// 	display_gun(image, image->guns);