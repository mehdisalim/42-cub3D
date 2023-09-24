/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:56:54 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 20:07:29 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	check_ray_angel_verticale(t_image *image)
{
	if ((image->ray_angle >= 0 && image->ray_angle <= 90)
		|| image->ray_angle >= 270)
		image->xverticale = (((int)image->xposition_p / TILESIZE))
			* TILESIZE + TILESIZE;
	else
		image->xverticale = ((int)image->xposition_p / TILESIZE) * TILESIZE;
	image->yverticale = image->yposition_p + (image->xverticale
			- image->xposition_p) * tan(image->ray_angle * (M_PI / 180));
}

void	find_distance_verticale(t_image *image)
{
	unsigned int	xpos;
	unsigned int	ypos;

	check_ray_angel_verticale(image);
	while (1)
	{
		ypos = image->yverticale / TILESIZE;
		xpos = image->xverticale / TILESIZE;
		if (image->yverticale < 1
			|| ypos >= (unsigned int)image->vertical_length)
			break ;
		if ((image->xverticale < 1
				|| xpos >= (unsigned int)ft_strlen(image->map[ypos])))
			break ;
		if ((image->ray_angle >= 90 && image->ray_angle <= 270)
			&& image->map[ypos][xpos - 1] == '1')
			break ;
		else if (image->map[ypos][xpos] == '1')
			break ;
		image->xverticale += TILESIZE * image->vx;
		image->yverticale = image->yposition_p + (image->xverticale
				- image->xposition_p) * tan(image->ray_angle * (M_PI / 180));
	}
	return ;
}

void	check_ray_angle_horizontal(t_image *image)
{
	if (image->ray_angle >= 0 && image->ray_angle < 180)
		image->yhorizontal = ((int)image->yposition_p
				/ TILESIZE) * TILESIZE + TILESIZE;
	else
		image->yhorizontal = ((int)image->yposition_p
				/ TILESIZE) * TILESIZE;
	image->xhorizontal = image->xposition_p + (image->yhorizontal
			- image->yposition_p) / tan(image->ray_angle * (M_PI / 180));
}

void	find_distance_horizontal(t_image *image)
{
	unsigned int	xpos;
	unsigned int	ypos;

	check_ray_angle_horizontal(image);
	while (1)
	{
		ypos = image->yhorizontal / TILESIZE;
		xpos = image->xhorizontal / TILESIZE;
		if ((image->yhorizontal < 1
				|| ypos >= (unsigned int)image->vertical_length))
			break ;
		if ((image->xhorizontal < 1
				|| xpos >= (unsigned int)ft_strlen(image->map[ypos])))
			break ;
		if (image->map[ypos][xpos] == '1')
			break ;
		if (image->ray_angle > 180 && image->map[((int)image->yhorizontal
					+ (TILESIZE * image->vy)) / TILESIZE][xpos] == '1')
			break ;
		image->yhorizontal += TILESIZE * image->vy;
		image->xhorizontal = image->xposition_p + (image->yhorizontal
				- image->yposition_p) / tan(image->ray_angle * (M_PI / 180));
	}
	return ;
}
