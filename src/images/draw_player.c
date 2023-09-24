/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:59:29 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 20:43:27 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	draw_pixel(unsigned int color, t_image *image, int xx, int yy)
{
	int	x;
	int	y;

	x = 0;
	while (x <= MINIMAPSIZE)
	{
		y = 0;
		while (y <= MINIMAPSIZE)
		{
			mlx_put_pixel(image->map_screen, (x + xx), (y + yy), color);
			y++;
		}
		x++;
	}
}

void	draw_player(t_image *image, double xPlayer, double yPlayer)
{
	int		circle_ray;
	float	x;
	float	y;
	int		err;
	int		arr[2];

	circle_ray = 4;
	x = -circle_ray;
	while (x <= circle_ray)
	{
		y = -circle_ray;
		while (y <= circle_ray)
		{
			err = x * x + y * y - circle_ray * circle_ray;
			if (err <= 0)
				mlx_put_pixel(image->map_screen, xPlayer + x,
					yPlayer + y, 0xffffff);
			y++;
		}
		x++;
	}
	arr[0] = xPlayer + (15 * cos(image->angle * (M_PI / 180)));
	arr[1] = yPlayer + (15 * sin(image->angle * (M_PI / 180)));
	dda(xPlayer, yPlayer, arr, image);
}
