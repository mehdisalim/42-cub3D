/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:35:28 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/19 16:40:34 by esalim           ###   ########.fr       */
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
		image->displayMiniMap = !image->displayMiniMap;
	if (keydata.key == MLX_KEY_C && a % 2)
		image->allowedCursor = !image->allowedCursor;

}