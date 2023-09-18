/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:56:54 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/18 10:17:18 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	find_distance_verticale(t_image *image)
{
	unsigned int xPos;
	unsigned int yPos;

	if ((image->ray_angle >= 0 && image->ray_angle <= 90) || image->ray_angle >= 270)
		image->xverticale = (((int)image->xposition_p / SIZE)) * SIZE + SIZE;
	else
		image->xverticale = ((int)image->xposition_p / SIZE) * SIZE;
	image->yverticale = image->yposition_p + (image->xverticale - image->xposition_p) * tan(image->ray_angle * (M_PI / 180));
	while (1)
	{
		yPos = image->yverticale / SIZE;
		xPos = image->xverticale / SIZE;
		if (image->yverticale < 1 || yPos >= (unsigned int)image->verticalLength)
			break ;
		if ((image->xverticale < 1 || xPos >= (unsigned int)ft_strlen(image->map[yPos])))
			break ;
		if ((image->ray_angle >= 90 && image->ray_angle <= 270) && image->map[yPos][xPos - 1] == '1')
			break ;
		else if (image->map[yPos][xPos] == '1')
			break ;
		image->xverticale += SIZE * image->vx;
		image->yverticale = image->yposition_p + (image->xverticale - image->xposition_p) * tan(image->ray_angle * (M_PI / 180));
	}
	return ;
}

void	find_distance_horizontal(t_image *image)
{
	unsigned int xPos;
	unsigned int yPos;
	
	if (image->ray_angle >= 0 && image->ray_angle < 180)
		image->yhorizontal = ((int)image->yposition_p / SIZE) * SIZE + SIZE;
	else
		image->yhorizontal = ((int)image->yposition_p / SIZE) * SIZE;
	image->xhorizontal = image->xposition_p + (image->yhorizontal - image->yposition_p) / tan(image->ray_angle * (M_PI / 180));
	while (1)
	{
		yPos = image->yhorizontal / SIZE;
		xPos = image->xhorizontal / SIZE;
		if ((image->yhorizontal < 1 || yPos >= (unsigned int)image->verticalLength))
			break ;
		if ((image->xhorizontal < 1 || xPos >= (unsigned int)ft_strlen(image->map[yPos])))
			break ;
		if (image->map[yPos][xPos] == '1')
			break ;
		if (image->ray_angle > 180 && image->map[((int)image->yhorizontal + (SIZE * image->vy)) / SIZE][xPos] == '1')
			break ;
		image->yhorizontal += SIZE * image->vy;
		image->xhorizontal = image->xposition_p + (image->yhorizontal - image->yposition_p) / tan(image->ray_angle * (M_PI / 180));
	}
	return ;
}
