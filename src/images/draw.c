/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/13 11:31:11 by esalim           ###   ########.fr       */
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
		draw_3D(image, distance_v, 0xe6e6f0, i);
		DDA(image->xposition_p, image->yposition_p, image->xverticale,
			image->yverticale, image);
		//=====================================//=====================================
		(void)i;
		//=====================================//=====================================
	}
	else
	{
		draw_3D(image, distance_h, 0xA4A4A4, i);
		DDA(image->xposition_p, image->yposition_p, image->xhorizontal,
			image->yhorizontal, image);
		//=====================================//=====================================
		//=====================================//=====================================
	}
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
	(void)color;
	int d = 0;
	float angle;


	if (image->angle < 0)
		image->angle += 360;
	if (image->angle > 360)
		image->angle -= 360;
	angle = (float)60 / WIDTH;
	image->ray_angle = image->angle - 30;
	// ESALIM HERE
	while (d < WIDTH/**/)
	{	
		draw(image, d);
		// DDA(image->xposition_p, image->yposition_p, image->xhorizontal, image->yhorizontal, image);
		image->ray_angle += angle;
		d++;
	}
}

void	drawMiniMap(t_image *img)
{
	int i;
	// int iBegin;
	// int iEnd;
	// int jBegin;
	// int jEnd;
	int j;

	// iBegin = (img->yposition_p - (SIZE / 2)) / SIZE;
	// jBegin = (img->xposition_p - (SIZE / 2)) / SIZE;
	// i = iBegin - 2;
	// if (i < 0)
	// 	i = 0;
	// iEnd = iBegin + 2;
	// jEnd = jBegin + 2;
	// while (i < iEnd && img->map[i])
	// {
	// 	j = jBegin - 2;
	// 	if (j < 0)
	// 		j = 0;
	// 	while (j < jEnd && img->map[i][j])
	// 	{
	// 		if (img->map[i][j] == '1')
	// 			draw_pixel(0xFF0000FF, img, (j * SIZE), (i * SIZE));
	// 		else if (!ft_strchr("1 ", img->map[i][j]))
	// 			draw_pixel(0x696ca5, img, j * SIZE, i * SIZE);
	// 		j++;
	// 	}
	// 	i++;
	// }
	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == '1')
				draw_pixel(0xFF0000FF, img, (j * SIZE), (i * SIZE));
			else if (!ft_strchr("1 ", img->map[i][j]))
				draw_pixel(0x696ca5, img, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}

	int x = -4;
    int y;
    int err;

	while (x <= 4)
    {
        y = -4;
        while (y <= 4)
        {
            err = x * x + y * y - 4 * 4;
            if (err <= 0)
                mlx_put_pixel(img->img,  img->xposition_p + x, img->yposition_p + y , 0x000000);
            y++;
        }
        x++;
    }
	// DDA(img->xposition_p, img->yposition_p, img->xposition_p, img->yposition_p * sin(img->angle * (M_PI / 180)), img);
	
}

void	drow_image(void *img)
{
	t_image	*image;
	int		i;
	int		j;

	i = 0;
	image = (t_image *)img;
	while (image->map[i])
	{
		j = 0;
		while (image->map[i][j])
		{
			if (ft_strchr("ESNW", image->map[i][j]) && image->hasEntered == 0)
			{
				image->xposition_p = (j * SIZE) + (SIZE / 2);
				image->yposition_p = (i * SIZE) + (SIZE / 2);
				image->hasEntered = 1;
			}
			j++;
		}
		i++;
	}

	draw_pixel_player(0xe6e6f0, image);
	drawMiniMap(image);

}
