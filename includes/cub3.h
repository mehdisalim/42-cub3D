/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:44:35 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/18 13:53:07 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
#define CUB3_H

#define WIDTH 2400
#define HEIGHT 1200
#define TILESIZE	60
#define MINIMAPSIZE	20
#define ENABLE	1
#define DISABLE	0




#include "../mlx/include/MLX42/MLX42.h"
#include "cub.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include<math.h>

// typedef

typedef struct s_mapInfo
{
	t_texture		*north;
	t_texture		*west;
	t_texture		*south;
	t_texture		*east;
	unsigned long	ceilingColor;
	unsigned long	floorColor;
}	t_mapInfo;

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t*	img;
	mlx_image_t*	screen_img;
	t_elements*		elements;
	// mlx_image_t*	imgMiniMap;
	int				window_with;
	int				window_height;
	char			**map;
	float			xposition_p;
	float			yposition_p;
	float			px;
	float			py;
	int 			hasEntered;
	float			angle;
	float			ray_angle;
	float			xverticale;
	float			yverticale;
	float			xhorizontal;
	float			yhorizontal;
	int				vx;
	int				vy;
	float			angle_right;
	float			angle_left;
	int 			verticalLength;
	int				playerSpeed;
	int				angleSpeed;
	char			displayMiniMap;
	t_mapInfo		mapInfo;
	float			xMap;
	float			yMap;
	float			xDDA;
	float			yDDA;
}	t_image;

int		check_draw_pixel_player(t_image *image, int n);
void	key_hook(mlx_key_data_t keydata, void *para);
void	find_distance_verticale(t_image * image);
void	find_distance_horizontal(t_image * image);
void	DDA(int X0, int Y0, int X1, int Y1, t_image  *image);
void	draw_pixel_player(t_image *image);
void	draw_pixel(unsigned int color, t_image *image, int xx, int yy);
void	drow_image(void *img);

//	====================================================================
//	display_3D.c
//	====================================================================
void	draw_3D(t_image *image, float ray, int i, int pixelXPos, const t_texture* const texture);
void *getDataFromElements(t_elements *elements, char *data);
t_texture	*getTexture(const char *str);

//	====================================================================
//	load_image.c
//	====================================================================

unsigned char	**convertTextureTo2DArray(unsigned char *srcArray, int height, int width);
unsigned char	***convert2DArrayTo3DArray(mlx_texture_t *texture, unsigned char **_2DArray);
t_color	**convert3DArrayToPixelsColor(mlx_texture_t *texture, unsigned char ***_3DArray);
void	printPixelsColor(t_color **pixelsColor);
unsigned long	getColor(t_color color);

//	====================================================================
//	drawMiniMap.c
//	====================================================================
void	drawMiniMap(t_image *img);

//	====================================================================
//	src/utils/destroy.c
//	====================================================================

void	destroyProgram(t_image *image);

#endif