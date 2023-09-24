/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:57:12 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 17:32:33 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

int abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
 
void	DDA(int x0, int y0, int x1, int y1, t_image  *image)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	float x = x0;
	float y = y0;
	int i = 0;
	while (i <= steps)
	{
		if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
			break;
		mlx_put_pixel(image->map_screen, x, y, 0xFF0000FF);
		x += Xinc;
		y += Yinc;
		i++; 
	}
}