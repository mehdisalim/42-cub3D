/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:44:35 by esekouni          #+#    #+#             */
/*   Updated: 2023/08/27 14:51:43 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
#define CUB3_H

#define WIDTH 2000
#define HEIGHT 1000




#include "../mlx/include/MLX42/MLX42.h"
#include "cub.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t*	img;
	char			**map;
	int				move_x;
	int				move_y;
	int				xposition_p;
	int				yposition_p;
	int				x;
	int				y;
}	t_image;

void	create_image(t_image *image);


#endif