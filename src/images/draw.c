/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/10 21:19:07 by esalim           ###   ########.fr       */
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
		image->rays[i++] = distance_h;
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
	while (x <= SIZE)
	{
		y = 0;
		while (y <= SIZE)
		{
			mlx_put_pixel(image->img, (x + xx), (y + yy), color);
			y++;
		}
		x++;
	}
}

void	draw_pixel_player(unsigned int color, t_image *image)
{
	// int	x;
	// int	y;
	(void)color;

	// x = 20;
	// while (x < 40)
	// {
	// 	y = 20;
	// 	while (y < 40)
	// 	{
	// 		mlx_put_pixel(image->img, (image->xposition_p - 30) + x,
	// 			(image->yposition_p - 30) + y, color);
	// 		y++;
	// 	}
	// 	x++;
	// }
	int d = 0;

	if (image->angle < 0)
		image->angle += 360;
	if (image->angle > 360)
		image->angle -= 360;
	image->ray_angle = image->angle - 30;
	while (d < 600)
	{	
		draw(image, d);
		image->ray_angle += (float)0.1;
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
				draw_pixel(0xFF0000FF, image, (j * SIZE), (i * SIZE));
			else if (!ft_strchr("1 ", image->map[i][j]))
				draw_pixel(0x696ca5, image, j * SIZE, i * SIZE);
			if (ft_strchr("ESNW", image->map[i][j]) && image->hasEntered == 0)
			{
				image->xposition_p = (j * SIZE) + (SIZE / 2);
				image->yposition_p = (i * SIZE) + (SIZE / 2);
				image->hasEntered = 1;
			}
			j++;
		}
	}
	draw_pixel_player(0xe6e6f0, image);
	draw_3D(image);
}
