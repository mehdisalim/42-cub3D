/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:57:12 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 20:44:16 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

int	abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	dda(int x0, int y0, int arr[2], t_image *image)
{
	t_dda	dda;

	dda.dx = arr[0] - x0;
	dda.dy = arr[1] - y0;
	if (abs(dda.dx) > abs(dda.dy))
		dda.steps = abs(dda.dx);
	else
		dda.steps = abs(dda.dy);
	dda.xinc = dda.dx / (float)dda.steps;
	dda.yinc = dda.dy / (float)dda.steps;
	dda.x = x0;
	dda.y = y0;
	dda.i = 0;
	while (dda.i <= dda.steps)
	{
		if (dda.x < 0 || dda.x >= WIDTH || dda.y < 0 || dda.y >= HEIGHT)
			break ;
		mlx_put_pixel(image->map_screen, dda.x, dda.y, 0xFF0000FF);
		dda.x += dda.xinc;
		dda.y += dda.yinc;
		dda.i++; 
	}
}
