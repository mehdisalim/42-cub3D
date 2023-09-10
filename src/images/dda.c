/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:57:12 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/07 12:58:28 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

int abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
 
void	DDA(int X0, int Y0, int X1, int Y1, t_image  *image)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = X0;
    float Y = Y0;
	int i = 0;
	while (i <= steps)
	{
		if (X < 0 || X >= WIDTH || Y < 0 || Y >= HEIGHT)
			break;
		mlx_put_pixel(image->img, X, Y, 0x000000);
        X += Xinc;
        Y += Yinc;
		i++; 
	}
}