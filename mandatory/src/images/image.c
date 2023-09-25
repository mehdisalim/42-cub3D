/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/25 10:32:38 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief 
 * 
 * @param image 
 * @param move 
 * @param angle 
 * @return int 
 */
int	check(t_image *image, int move, float angle)
{
	int	xx;
	int	yy;

	yy = (image->y_map + move * sin(angle * (M_PI / 180)));
	xx = (image->x_map + move * cos(angle * (M_PI / 180)));
	if ((image->map[(yy + 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1'
		|| image->map[(yy - 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1') \
		&& (image->map[yy / MINIMAPSIZE][(xx + 4) / MINIMAPSIZE] == '1'
		|| image->map[yy / MINIMAPSIZE][(xx - 4) / MINIMAPSIZE] == '1'))
		return (0);
	if ((image->map[(yy + 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1'
		|| image->map[(yy - 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1') \
		&& (image->map[yy / MINIMAPSIZE][(xx + 4) / MINIMAPSIZE] != '1'
		|| image->map[yy / MINIMAPSIZE][(xx - 4) / MINIMAPSIZE] != '1'))
		return (4);
	if ((image->map[(yy + 4) / MINIMAPSIZE][xx / MINIMAPSIZE] != '1'
		|| image->map[(yy - 4) / MINIMAPSIZE][xx / MINIMAPSIZE] != '1') \
		&& (image->map[yy / MINIMAPSIZE][(xx + 4) / MINIMAPSIZE] == '1'
		|| image->map[yy / MINIMAPSIZE][(xx - 4) / MINIMAPSIZE] == '1'))
		return (5);
	return (1);
}

void	get_player_position_2(t_image *image)
{
	char	*player;
	int		hasentered;

	hasentered = 0;
	while (image->map[image->vx][++image->vy])
	{
		player = ft_strchr("ESNW", image->map[image->vx][image->vy]);
		if (player && hasentered == 0)
		{
			image->xposition_p = (image->vy * TILESIZE) + (TILESIZE / 2);
			image->yposition_p = (image->vx * TILESIZE) + (TILESIZE / 2);
			image->x_map = (image->vy * MINIMAPSIZE) + (MINIMAPSIZE / 2);
			image->y_map = (image->vx * MINIMAPSIZE) + (MINIMAPSIZE / 2);
			if (*player == 'N')
				image->angle = 270;
			else if (*player == 'E')
				image->angle = 0;
			else if (*player == 'S')
				image->angle = 180;
			else if (*player == 'W')
				image->angle = 90;
			hasentered = 1;
		}
	}
}
/**
 * @brief Get the Player Position im map and set Angle of Player
 * 
 * @param image global struct
 */

void	get_player_position(t_image *image)
{
	int		hasentered;

	image->vx = -1;
	hasentered = 0;
	while (image->map[++(image->vx)])
	{
		image->vy = -1;
		get_player_position_2(image);
	}
}

/**
 * @brief Create a window object and setuping mlx ghraphical user interface
 * 
 * @param elements struct of element that already parsing in main2
 * @param map 		double pointer that contains map characters
 * @return none
 */
void	create_window(t_elements *elements, char **map)
{
	t_image	*image;

	image = init_struct(elements, map);
	image->elements = elements;
	image->map = map;
	if (!check_textures(image))
	{
		destroy_program(image);
		return ;
	}
	image->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	get_player_position(image); 
	mlx_image_to_window(image->mlx, image->img, 0, 0);
	mlx_loop_hook(image->mlx, draw_image, image);
	mlx_loop(image->mlx);
	mlx_delete_image(image->mlx, image->img); 
	mlx_terminate(image->mlx);
	destroy_program(image);
}
