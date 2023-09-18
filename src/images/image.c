/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/18 13:18:23 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/cub3.h"

int	check(t_image *image, int move, float angle)
{
	int xx;
	int yy;

	yy = (image->yMap + move * sin(angle * (M_PI / 180)));
	xx = (image->xMap  + move * cos(angle * (M_PI / 180)));
	if ((image->map[(yy + 2) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1'
	|| image->map[(yy - 2) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1'
	|| image->map[yy / MINIMAPSIZE][(xx + 2) / MINIMAPSIZE] == '1'
	|| image->map[yy / MINIMAPSIZE][(xx - 2) / MINIMAPSIZE] == '1'))
		return (0);
	return (1);
}


int		check_draw_pixel_player(t_image *image, int n)
{

	if (n == 3 && check(image, 5, image->angle) == 0)
		return (0);
	if (n == 4 && check(image, -5, image->angle) == 0)
		return (0);
	if (n == 1 && check(image, 5, image->angle_right) == 0)
		return (0);
	if (n == 2 && check(image, 5, image->angle_left) == 0)
		return (0);
	return (1);
}

void	create_window(t_elements *elements, char **map)
{
	t_image image;
    t_color *floorOrCeilingColor;

	image.elements = elements;
	image.map = map;
	image.xhorizontal = 0;
	image.yhorizontal = 0;
	image.xverticale = 0;
	image.yverticale = 0;
	image.xposition_p = 0;
	image.yposition_p = 0;
	image.angle = 0;
	image.angle_right = 0;
	image.angle_left = 0;
	image.hasEntered = 0;
	image.playerSpeed = 5;
	image.angleSpeed = 5;
	image.displayMiniMap = ENABLE;
	image.verticalLength = map_size(map);
	// Cardinal Directions
    image.mapInfo.north = getTexture("assets/frame1.png");
    image.mapInfo.south = getTexture("assets/60pixels.png");
    image.mapInfo.east = getTexture("assets/frame1.png");
    image.mapInfo.west = getTexture("assets/frame1.png");
	floorOrCeilingColor = getDataFromElements(elements, "C");
    image.mapInfo.ceilingColor = getColor(*floorOrCeilingColor);
	free(floorOrCeilingColor);
	floorOrCeilingColor = getDataFromElements(elements, "F");
    image.mapInfo.floorColor = getColor(*floorOrCeilingColor);
	free(floorOrCeilingColor);
	// ===========================
	image.mlx =  mlx_init(WIDTH, HEIGHT , "cub3D", 0);
	image.img = mlx_new_image(image.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(image.mlx, image.img, 0, 0);	
	mlx_key_hook(image.mlx, &key_hook, &image);
	mlx_loop_hook(image.mlx, drow_image, &image);
	mlx_loop(image.mlx);
	mlx_terminate(image.mlx);
	destroyProgram(&image);
}

int		main(int ac, char **av)
{
	char	**map_elements;
	char	**map;
	char	checker = 0;

	if (ac < 2)
		return (ft_putstr_fd("bad args\n", 2), 1);
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
		return (ft_putstr_fd("File Name Error\n", 2), 0);
	
	if (!check_map(av[1], &map_elements, &map, &checker))
	{
		if (checker)
			return (ft_putstr_fd("File not found !!\n", 2), 1);
		free_double_pointer(map_elements);
		free_double_pointer(map);
		return (1);
	}
	t_elements *elements = parsing_elements(map_elements);
	free_double_pointer(map_elements);
	if (!elements)
		return (free_double_pointer(map), 1);
	create_window(elements, map);
	// system("leaks -q cub3D");
}
