/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/08 13:12:34 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	vue_x_y(t_image *image)
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
	// if (image->angle >= 0 && image->angle < 180)
	// 	image->vy *= 1;
	// if (image->angle >= 180)
	// 	image->vy *= -1;
	// if ((image->angle >= 0 && image->angle <= 90) || image->angle >= 270)
	// 	image->vx *= 1;
	// else
	// 	image->vx *= -1;
}

void	draw(t_image *image, int i)
{
	float	distance_h;
	float	distance_v;

	if (image->ray_angle < 0)
		image->ray_angle += 360;
	if (image->ray_angle > 360)
		image->ray_angle -= 360;
	if (image->angle < 0)
		image->angle += 360;
	if (image->angle > 360)
		image->angle -= 360;
	vue_x_y(image);
	find_distance_verticale(image);
	find_distance_horizontal(image);
	distance_h = sqrt(pow((image->xhorizontal - image->xposition_p), 2)
			+ pow((image->yhorizontal - image->yposition_p), 2));
	distance_v = sqrt(pow((image->xverticale - image->xposition_p), 2)
			+ pow((image->yverticale - image->yposition_p), 2));
	if (distance_h > distance_v)
	{
		DDA(image->xposition_p, image->yposition_p, image->xverticale,
			image->yverticale, image);
		image->rays[i++] = distance_v;
	}
	else
	{
		DDA(image->xposition_p, image->yposition_p, image->xhorizontal,
			image->yhorizontal, image);
		image->rays[i++] = distance_v;
	}
	// i = 0;
	// while (image->rays[i])
	// {
	// 	printf("%d\n", image->rays[i]);
	// 	i++;
	// }
	
}

void	draw_pixel(unsigned int color, t_image *image, int xx, int yy)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 20)
	{
		y = 0;
		while (y <= 20)
		{
			mlx_put_pixel(image->img, (x + xx), (y + yy), color);
			y++;
		}
		x++;
	}
}

void	draw_pixel_player(unsigned int color, t_image *image)
{
	int	x;
	int	y;

	x = 6;
	while (x < 14)
	{
		y = 6;
		while (y < 14)
		{
			mlx_put_pixel(image->img, (image->xposition_p - 10) + x,
				(image->yposition_p - 10) + y, color);
			y++;
		}
		x++;
	}
	int d = 0;
	image->ray_angle = image->angle - 30;
	while (d < 600)
	{	
		draw(image, d);
		image->ray_angle += (float)30 / 600;
		d++;
	}
}

void	drow_image(void *img)
{
	t_image	*image;
	int		i;
	int		j;

	i = -1;
	image = (t_image *)img;
	while (image->map[++i])
	{
		j = 0;
		while (image->map[i][j])
		{
			if (image->map[i][j] == '1')
				draw_pixel(0xFF0000FF, image, (j * 20), (i * 20));
			else if (!ft_strchr("1 ", image->map[i][j]))
				draw_pixel(0x696ca5, image, j * 20, i * 20);
			if (ft_strchr("ESNW", image->map[i][j]) && image->hasEntered == 0)
			{
				image->xposition_p = (j * 20) + 10;
				image->yposition_p = (i * 20) + 10;
				image->hasEntered = 1;
			}
			j++;
		}
	}
	draw_pixel_player(0xe6e6f0, image);
	draw_3D(image);
}
