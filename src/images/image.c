/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/07 13:31:35 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/cub3.h"

int		check_draw_pixel_player(t_image *image, int n)
{
	int xx;
	int yy;

	yy = (image->yposition_p + 15 * sin(image->angle * (M_PI / 180))) / 60;
	xx = (image->xposition_p  + 15 * cos(image->angle * (M_PI / 180))) / 60;
	if ((image->map[yy][xx] == '1') && n == 3)
		return (0);
	yy = (image->yposition_p - 15 * sin(image->angle * (M_PI / 180))) / 60;
	xx = (image->xposition_p - 15 * cos(image->angle * (M_PI / 180))) / 60;
	if (image->map[yy][xx] == '1' && n == 4)
		return (0);
	yy = (image->yposition_p + 15 * sin(image->angle_right * (M_PI / 180))) / 60;
	xx = (image->xposition_p  + 15 * cos(image->angle_right * (M_PI / 180))) / 60;
	if ((image->map[yy][xx] == '1') && n == 1)
		return (0);
	yy = (image->yposition_p + 15 * sin(image->angle_left * (M_PI / 180))) / 60;
	xx = (image->xposition_p + 15 * cos(image->angle_left * (M_PI / 180))) / 60;
	if (image->map[yy][xx] == '1' && n == 2)
		return (0);
	
	return (1);
}

void	create_window(char **map)
{
	t_image image;

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
	image.mlx =  mlx_init(WIDTH, HEIGHT , "cub3D", 0);
	image.img = mlx_new_image(image.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(image.mlx, image.img, 0, 0);
	mlx_loop_hook(image.mlx, drow_image, &image);
	mlx_key_hook(image.mlx, &key_hook, &image);
	mlx_loop(image.mlx);
	mlx_terminate(image.mlx);
}

int	main(int ac, char **av)
{
	char	**map_elements;
	char	**map;

	if (ac < 2)
	{
		ft_putstr_fd("bad args\n", 2);
		return (1);
	}
	if (!check_map(av[1], &map_elements, &map))
	{
		free_double_pointer(map_elements);
		free_double_pointer(map);
		return (1);
	}
	t_elements *elements = parsing_elements(map_elements);
	free_double_pointer(map_elements);
	if (!elements)
		return (free_double_pointer(map), 1);
	
	create_window(map);

}
