/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:44:35 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 22:17:37 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include "../mlx/include/MLX42/MLX42.h"
# include "structs.h"
# include "cub.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define TILESIZE		60
# define WIDTH			1920
# define HEIGHT			1080
# define MINIMAPSIZE	20
# define ENABLE			1
# define DISABLE		0

void			create_window(t_elements *elements, char **map);

int				check_draw_pixel_player(t_image *image, int n);
void			key_hook(mlx_key_data_t keydata, void *para);
void			find_distance_verticale(t_image	*image);
void			find_distance_horizontal(t_image *image);
void			dda(int x0, int y0, int arr[2], t_image *image);
void			draw_pixel_player(t_image *image);
void			draw_image(void *img);

//	====================================================================
//	display_3D.c
//	====================================================================

void			draw_3d(t_image *image, float ray, \
							int arr[2], t_texture *texture);
void			*get_data_from_elements(t_elements *elements, char *data);

//	====================================================================
//	load_image.c
//	====================================================================

unsigned long	get_color(t_color color);

//	====================================================================
//	drawMiniMap.c
//	====================================================================
// void	drawMiniMap(t_image *img);
void			draw_dynamic_map(t_image *image);
void			draw_pixel(unsigned int color, t_image *image, int xx, int yy);

void			draw_player(t_image *image, double xPlayer, double yPlayer);
void			check_key(t_image *image);

//	====================================================================
//	src/utils/destroy.c
//	====================================================================

void			destroy_program(t_image *image);

// =======================================
void			press_w_key(t_image *image);
void			press_s_key(t_image *image);
void			press_a_key(t_image *image);
void			press_d_key(t_image *image);
void			vue_x_y(t_image *image);
void			angle(t_image *image);
int				check(t_image *image, int move, float angle);
t_image			*init_struct(t_elements *elements, char **map);
// =======================================
#endif