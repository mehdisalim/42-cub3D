/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:35:28 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/25 10:29:56 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		image->angle -= image->angle_speed;
	if (mlx_is_key_down(image->mlx, MLX_KEY_RIGHT))
		image->angle += image->angle_speed;
}
