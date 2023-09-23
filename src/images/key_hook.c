/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:35:28 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/23 15:49:23 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void key_hook(mlx_key_data_t keydata, void *para)
{
	t_image *image;
	static unsigned int a;

	image = (t_image *)para;
	a++;
	if (keydata.key == MLX_KEY_M && a % 2)
	{
		if (image->displayMiniMap == ENABLE)
		{
			mlx_delete_image(image->mlx, image->mapScreen);
			image->mapScreen = mlx_new_image(image->mlx, 220, 220);
			mlx_image_to_window(image->mlx, image->mapScreen, 0, HEIGHT - 220);
		}
		else
			drawDynamicMap(image);
		image->displayMiniMap = !image->displayMiniMap;
	}
	if (keydata.key == MLX_KEY_C && a % 2)
		image->allowedCursor = !image->allowedCursor;
	if (keydata.key == 61 && a % 2 && image->playerSpeed < 10)
		++image->playerSpeed;
	if (keydata.key == 45 && a % 2 && image->playerSpeed > 3)
		--image->playerSpeed;
	if (keydata.key == MLX_KEY_G && a % 2)
		display_gun(image, image->guns);
	// if (keydata.key == MLX_KEY_G && a % 2)
	// {
	// 	t_list *guns = image->guns;
	// 	while (guns)
	// 	{
	// 		int y = 0;
	// 		int x = 0;
	// 		t_texture *tex = (t_texture *)guns->content;
	// 		while (y < tex->height)
	// 		{
	// 			x = 0;
	// 			while (x < tex->width)
	// 			{
	// 				mlx_put_pixel(image->gunScreen, y, x, get_color(tex->pixels[y][x]));
	// 				x++;
	// 			}
	// 			y++;
	// 		}
	// 		guns = guns->next;
	// 	}
	// }
}