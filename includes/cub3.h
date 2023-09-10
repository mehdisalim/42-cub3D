/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:44:35 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/10 21:15:55 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
#define CUB3_H

#define WIDTH 2000
#define HEIGHT 1000
#define SIZE	20



#include "../mlx/include/MLX42/MLX42.h"
#include "cub.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include<math.h>

// typedef

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t*	img;
	int				window_with;
	int				window_height;
	char			**map;
	float				xposition_p;
	float				yposition_p;
	float				px;
	float				py;
	int 				hasEntered;
	float				angle;
	float				ray_angle;
	float				xverticale;
	float				yverticale;
	float				xhorizontal;
	float				yhorizontal;
	int					vx;
	int					vy;
	float				*rays;
	float				angle_right;
	float				angle_left;
}	t_image;

int		check_draw_pixel_player(t_image *image, int n);
void	key_hook(mlx_key_data_t keydata, void *para);
void	find_distance_verticale(t_image * image);
void	find_distance_horizontal(t_image * image);
void	DDA(int X0, int Y0, int X1, int Y1, t_image  *image);
void	draw_pixel_player(unsigned int color, t_image *image);
void	draw_pixel(unsigned int color, t_image *image, int xx, int yy);
void	drow_image(void *img);
void	draw_3D(t_image *image);

#endif