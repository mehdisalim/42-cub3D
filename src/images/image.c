/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/08/28 10:50:33 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/cub3.h"
#include<math.h>

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }
 
void DDA(int X0, int Y0, int X1, int Y1, t_image  *image)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
    {
		mlx_put_pixel(image->img, X, Y, 0x000000);
	}
        X += Xinc;
        Y += Yinc; 
    }
}

void	drow_pixel(unsigned int color, t_image *image, int xx, int yy)
{
	int x;
	int y;
	
	x = 0;
	while (x < 60)
	{
		y = 0;
		while (y < 60)
		{
			mlx_put_pixel(image->img,(x + xx) , (y + yy), color);
			y++;
		}
		x++;
	}
}

// void	drow_arrow(t_image *image)
// {

// }

void	drow_pixel_player(unsigned int color, t_image *image)
{
	int x;
	int y;

	x = 25;
	while (x < 35)
	{
		y = 25;
		while (y < 35)
		{
			mlx_put_pixel(image->img, image->xposition_p + x, image->yposition_p + y , color);
			y++;
		}
		x++;
	}
	image->xposition_p += 30;
	image->yposition_p += 30;
	int px;
	int py;
	
	
	px = image->xposition_p + 50 * cos(image->x * (M_PI/180));
	py = image->yposition_p + 50 * sin(image->x * (M_PI/180));

	DDA(image->xposition_p, image->yposition_p, px , py, image);
	
}


void	drow_image(void *img)
{
	int i;
	int j;

	i = 0;
	j = 0;
	t_image *image;
	image = (t_image *)img;
	while (image->map[i])
	{
		j = 0;
		while (image->map[i][j])
		{
			if (image->map[i][j] == '1')
				drow_pixel(0xFF0000FF, image, (j * 60), (i * 60));
			else if (!ft_strchr("1 ", image->map[i][j]))
				drow_pixel(0x696ca5, image, j * 60, i * 60);
			if (ft_strchr("ESNW", image->map[i][j]))
			{
				image->xposition_p = (j * 60) + image->move_x;
	 			image->yposition_p = (i * 60) + image->move_y;
			}
			j++;
		}
		i++;
	}
	drow_pixel_player(0xe6e6f0, image);
}

int		check_draw_pixel_player(t_image *image, int n)
{
	int x = -5;
	int y = -5;
	while (x < 5)
	{	
		if ((image->map[((image->yposition_p - 10) / 60)][((image->xposition_p  + x) / 60)] == '1') && n == 3)
			return (0);
		if (image->map[((image->yposition_p + 10) / 60)][((image->xposition_p  + x) / 60)] == '1' && n == 4)
			return (0);
		x++;
	}
	while (y < 5)
	{	
		if (image->map[((image->yposition_p + y) / 60)][((image->xposition_p - 10) / 60)] == '1' && n == 1)
			return (0);
		if (image->map[((image->yposition_p + y) / 60)][((image->xposition_p + 10) / 60)] == '1' && n == 2)
			return (0);
		y++;
	}
	return (1);
}

void	key_hook(mlx_key_data_t keydata, void *para)
{
	t_image *image;

	image = (t_image *)para;
	printf("%u\n", keydata.key);

	if (keydata.key == 256)
	{
		mlx_delete_image(image->mlx, image->img);
		exit(0);
	}
	else if (keydata.key == 65)
	{
		if (check_draw_pixel_player(image, 1) != 0)
			image->move_x -= 5;
	}
	else if (keydata.key == 68)
	{
		if (check_draw_pixel_player(image, 2) != 0)
			image->move_x += 5;
	}
	else if (keydata.key == 87)
	{
		if (check_draw_pixel_player(image, 3) != 0)
			image->move_y -= 5;
	}
	else if (keydata.key == 83)
	{
		if (check_draw_pixel_player(image, 4) != 0)
			image->move_y += 5;
	}
	else if (keydata.key == 263)
	{
		image->x -= 5;
	}
	else if (keydata.key == 262)
	{
		image->x += 5;
	}
}

void	create_window(char **map)
{
	t_image image;

	image.map = map;
	image.move_x = 0;
	image.move_y = 0;
	image.xposition_p = 0;
	image.yposition_p = 0;
	image.x = 0;
	image.mlx =  mlx_init(WIDTH, HEIGHT , "cub3D", image.mlx);
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
	{
		free_double_pointer(map);
		return (1);
	}
	// printf("|||%c\n", map[0][0]);
	create_window(map);

}
