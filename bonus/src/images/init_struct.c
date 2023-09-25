/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:19:33 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/25 10:38:07 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief 
 * 
 * @param image 
 * @param n 
 * @return int 
 */
int	check_draw_pixel_player(t_image *image, int n)
{
	if (n == 3)
		return (check(image, image->player_speed, image->angle));
	if (n == 4)
		return (check(image, -image->player_speed, image->angle));
	if (n == 1)
		return (check(image, image->player_speed, image->angle_right));
	if (n == 2)
		return (check(image, image->player_speed, image->angle_left));
	return (1);
}

void	init_struct_2(t_image *image, t_elements *elements)
{
	image->map_info.north = get_texture((char *)
			get_data_from_elements(elements, "NO"));
	image->map_info.south = get_texture((char *)
			get_data_from_elements(elements, "SO"));
	image->map_info.east = get_texture((char *)
			get_data_from_elements(elements, "EA"));
	image->map_info.west = get_texture((char *)
			get_data_from_elements(elements, "WE"));
	image->map_info.ceiling_color = get_color(*(t_color *)
			get_data_from_elements(elements, "C"));
	image->map_info.floor_color = get_color(*(t_color *)
			get_data_from_elements(elements, "F"));
}

/**
 * @brief allocate new image and initialize all variables inside struct
 * 
 * @param elements	struct of elements that already parsing in main
 * @param map 		2d array of map characters
 * @return t_image* new image 
 */
t_image	*init_struct(t_elements *elements, char **map)
{
	t_image	*image;

	image = ft_calloc(1, sizeof(t_image));
	image->xhorizontal = 0;
	image->yhorizontal = 0;
	image->xverticale = 0;
	image->yverticale = 0;
	image->xposition_p = 0;
	image->yposition_p = 0;
	image->angle = 0;
	image->angle_right = 0;
	image->angle_left = 0;
	image->player_speed = 5;
	image->angle_speed = 3;
	image->display_mini_map = ENABLE;
	image->allowed_cursor = ENABLE;
	image->vertical_length = map_size(map);
	init_struct_2(image, elements);
	return (image);
}
