/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:26:24 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/18 11:27:19 by esalim           ###   ########.fr       */
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
	distance_h = sqrt(pow((image->xhorizontal - image->xposition_p), 2) + pow((image->yhorizontal - image->yposition_p), 2));
	distance_v = sqrt(pow((image->xverticale - image->xposition_p), 2) + pow((image->yverticale - image->yposition_p), 2));
	if (distance_h > distance_v)
	{
		// DDA(image->xposition_p, image->yposition_p, image->xverticale, image->yverticale, image);
		//=====================================//=====================================
		draw_3D(image, distance_v, i, (int)image->yverticale % image->mapInfo.north->width, image->mapInfo.north);
		//=====================================//=====================================
	}
	else
	{
		// DDA(image->xposition_p, image->yposition_p, image->xhorizontal, image->yhorizontal, image);
		//=====================================//=====================================
		draw_3D(image, distance_h, i, (int)image->xhorizontal % image->mapInfo.south->width, image->mapInfo.south);
		//=====================================//=====================================
	}
}

void	draw_pixel_player(t_image *image)
{
	int d = 0;
	float angle;


	if (image->angle < 0)
		image->angle += 360;
	if (image->angle > 360)
		image->angle -= 360;
	angle = (float)60 / WIDTH;
	image->ray_angle = image->angle - 30;
	// ESALIM HERE
	while (d < WIDTH)
	{	
		draw(image, d);
		image->ray_angle += angle;
		d++;
	}
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
				image->xposition_p = (j * MINIMAPSIZE) + (MINIMAPSIZE / 2);
				image->yposition_p = (i * MINIMAPSIZE) + (MINIMAPSIZE / 2);
				image->hasEntered = 1;
			}
			j++;
		}
		i++;
	}
	draw_pixel_player(image);
	// getNewMap(image);
	drawMiniMap(image);

}



/**
 *  void	getNewMap(t_image *image)
 * {
 * 	int		i = (image->yposition_p - (SIZE / 2)) / SIZE;
 * 	int		j = (image->xposition_p - (SIZE / 2)) / SIZE;
 *
 * 	int		counter = -1;
 *	
 * 	while (++counter < 9)
 * 		ft_memset(image->newMap[counter], ' ', 9);
 * 	int		x = 0;
 * 	int		y = 0;
 * 	int		iEnd = i + 4;
 * 	int		jEnd = j + 4;
 * 	y = i - 5;
 * 	if (y < -1)
 * 		y = -1;
 * 	j -= 4;
 * 	if (j < 0)
 * 		j = 0;
 * 	if (iEnd > image->verticalLength)
 * 		iEnd = image->verticalLength - 1;
 * 	while (++y < iEnd)
 * 	{
 * 		int a = 0;
 * 		int jLen = ft_strlen(image->map[y]) - 1;
 * 		if (jEnd > jLen)
 * 			jEnd = jLen;
 * 		jLen = j;
 * 		while (j < jEnd)
 * 			image->newMap[x][a++] = image->map[y][j++];
 * 		j = jLen;
 * 		x++;
 * 	}
 * }
 **/