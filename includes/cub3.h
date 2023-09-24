/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:44:35 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 17:04:24 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
#define CUB3_H

#define TILESIZE	60
#define WIDTH		1920
#define HEIGHT		1080
#define MINIMAPSIZE	20
#define ENABLE		1
#define DISABLE		0




#include "../mlx/include/MLX42/MLX42.h"
#include "structs.h"
#include "cub.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

void create_window(t_elements *elements, char **map);

int		check_draw_pixel_player(t_image *image, int n);
void	key_hook(mlx_key_data_t keydata, void *para);
void	find_distance_verticale(t_image * image);
void	find_distance_horizontal(t_image * image);
void	DDA(int X0, int Y0, int X1, int Y1, t_image  *image);
void	draw_pixel_player(t_image *image);
void	draw_image(void *img);

//	====================================================================
//	display_3D.c
//	====================================================================
void	draw_3D(t_image *image, float ray, int i, int pixelXPos, const t_texture* const texture);
void *getDataFromElements(t_elements *elements, char *data);

//	====================================================================
//	load_image.c
//	====================================================================

unsigned char	**convertTextureTo2DArray(unsigned char *srcArray, int height, int width);
unsigned char	***convert2DArrayTo3DArray(mlx_texture_t *texture, unsigned char **_2DArray);
t_color	**convert3DArrayToPixelsColor(mlx_texture_t *texture, unsigned char ***_3DArray);
void	printPixelsColor(t_color **pixelsColor);
unsigned long	get_color(t_color color);

//	====================================================================
//	drawMiniMap.c
//	====================================================================
// void	drawMiniMap(t_image *img);
void	drawDynamicMap(t_image *image);
void	draw_pixel(unsigned int color, t_image *image, int xx, int yy);

// void draw_3D(t_image *image, float ray, int i, int pixelXPos, const t_texture* const texture, int isReverse);

// void	drawMiniMap(t_image *img, float xStartMap, float yStartMap);
void    drawPlayer(t_image *image, double xPlayer, double yPlayer);

//	====================================================================
//	src/utils/destroy.c
//	====================================================================

void	destroy_program(t_image *image);

void    display_gun(t_image *image, t_list *lst);

// =======================================
void	press_w_key(t_image *image);
void	press_s_key(t_image *image);
void	press_a_key(t_image *image);
void	press_d_key(t_image *image);
void	vue_x_y(t_image *image);
void	angle(t_image *image);

// =======================================
#endif