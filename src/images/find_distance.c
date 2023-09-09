/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:56:54 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/08 11:52:37 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	find_distance_verticale(t_image *image)
{
	if ((image->ray_angle >= 0 && image->ray_angle <= 90) || image->ray_angle >= 270)
		image->xverticale = (((int)image->xposition_p / 20)) * 20 + 20;
	else
		image->xverticale = ((int)image->xposition_p / 20) * 20;
	image->yverticale = image->yposition_p
		+ (image->xverticale - image->xposition_p)
		* tan(image->ray_angle * (M_PI / 180));
	while (1)
	{
		if ((image->yverticale / 20) < 0 || (image->yverticale / 20) > 4)
			break ;
		if ((image->ray_angle >= 90 && image->ray_angle <= 270)
			&& image->map[(int)image->yverticale / 20]
			[(int)(image->xverticale - 20) / 20] == '1')
			break ;
		else if (image->map[(int)image->yverticale / 20]
			[(int)(image->xverticale) / 20] == '1')
			break ;
		image->xverticale += 20 * image->vx;
		image->yverticale = image->yposition_p
			+ (image->xverticale - image->xposition_p)
			* tan(image->ray_angle * (M_PI / 180));
	}
	// if ((image->angle >= 0 && image->angle <= 90) || image->angle >= 270)
	// 	image->xverticale = (((int)image->xposition_p / 60)) * 60 + 60;
	// else
	// 	image->xverticale = ((int)image->xposition_p / 60) * 60;
	// image->yverticale = image->yposition_p
	// 	+ (image->xverticale - image->xposition_p)
	// 	* tan(image->angle * (M_PI / 180));
	// while (1)
	// {
	// 	if ((image->yverticale / 60) < 0 || (image->yverticale / 60) > 4)
	// 		break ;
	// 	if ((image->angle >= 90 && image->angle <= 270)
	// 		&& image->map[(int)image->yverticale / 60]
	// 		[(int)(image->xverticale - 60) / 60] == '1')
	// 		break ;
	// 	else if (image->map[(int)image->yverticale / 60]
	// 		[(int)(image->xverticale) / 60] == '1')
	// 		break ;
	// 	image->xverticale += 60 * image->vx;
	// 	image->yverticale = image->yposition_p
	// 		+ (image->xverticale - image->xposition_p)
	// 		* tan(image->angle * (M_PI / 180));
	// }
	return ;
}

void	find_distance_horizontal(t_image *image)
{
	if (image->ray_angle >= 0 && image->ray_angle < 180)
		image->yhorizontal = ((int)image->yposition_p / 20) * 20 + 20;
	else
		image->yhorizontal = ((int)image->yposition_p / 20) * 20;
	image->xhorizontal = image->xposition_p
		+ (image->yhorizontal - image->yposition_p)
		/ tan(image->ray_angle * (M_PI / 180));
	while (1)
	{
		if ((image->xhorizontal / 20 < 0) || (image->xhorizontal / 20 > 10))
			break ;
		if (image->ray_angle > 180 
			&& image->map[((int)image->yhorizontal + (20 * image->vy)) / 20]
			[(int)image->xhorizontal / 20] == '1')
			break ;
		else if (image->map[(int)image->yhorizontal / 20]
			[(int)image->xhorizontal / 20] == '1')
			break ;
		image->yhorizontal += 20 * image->vy;
		image->xhorizontal = image->xposition_p 
			+(image->yhorizontal - image->yposition_p)
			/ tan(image->ray_angle * (M_PI / 180));
	}
	// if (image->angle >= 0 && image->angle < 180)
	// 	image->yhorizontal = ((int)image->yposition_p / 60) * 60 + 60;
	// else
	// 	image->yhorizontal = ((int)image->yposition_p / 60) * 60;
	// image->xhorizontal = image->xposition_p
	// 	+ (image->yhorizontal - image->yposition_p)
	// 	/ tan(image->angle * (M_PI / 180));
	// while (1)
	// {
	// 	if ((image->xhorizontal / 60 < 0) || (image->xhorizontal / 60 > 10))
	// 		break ;
	// 	if (image->angle > 180 
	// 		&& image->map[((int)image->yhorizontal + (60 * image->vy)) / 60]
	// 		[(int)image->xhorizontal / 60] == '1')
	// 		break ;
	// 	else if (image->map[(int)image->yhorizontal / 60]
	// 		[(int)image->xhorizontal / 60] == '1')
	// 		break ;
	// 	image->yhorizontal += 60 * image->vy;
	// 	image->xhorizontal = image->xposition_p 
	// 		+(image->yhorizontal - image->yposition_p)
	// 		/ tan(image->angle * (M_PI / 180));
	// }
	return ;
}
