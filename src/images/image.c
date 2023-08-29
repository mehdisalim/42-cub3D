/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/08/29 17:42:10 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/cub3.h"
#include<math.h>

// float abs(float n) { return ((n > 0) ? n : (n * (-1))); }
 

float	*saves;
int	counter;
void	DDA(float Px, float Py, float X1, float Y1, t_image  *image)
{
	
	float dx = X1 - Px;
	float dy = Y1 - Py;
	float steps = fabsf(dx) > fabsf(dy) ? fabsf(dx) : fabsf(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	float X = Px;
	float Y = Py;
	for (int i = 0; i <= steps; i++)
	{
		// printf("X{%.2f} Y{%.2f}\n", X, Y);
		if (X < 0)
			X *= -1;
		if (Y < 0)
			Y *= -1;
		if ((int)Y % 60 == 0)
		{
			saves[i++] = Y;
			// break ;
		}
		// printf("SPACE ==> X\t[%f] | Y\t[%f]\n", X, Y);
		mlx_put_pixel(image->img, X, Y, 0xFFFFFF);
		X += Xinc;
		Y += Yinc; 
	}
}

void	print_intersactions( void )
{
	int	i = -1;
	while (++i < counter)
		printf("saves[%d] ==> %.2f\n", i, saves[i]);
}

void	drow_pixel(unsigned int color, t_image *image, int xx, int yy)
{
	int x;
	int y;
	
	x = 0;
	while (x < 59)
	{
		y = 0;
		while (y < 59)
		{
			mlx_put_pixel(image->img,(x + xx) , (y + yy), color);
			y++;
		}
		x++;
	}
	mlx_put_pixel(image->img,(x + xx) , (y + yy), 0x544545);
}

void	drow_pixel_player(unsigned int color, t_image *image)
{
	// int x;
	// int y;

	// x = 25;
	// while (x < 35)
	// {
	// 	y = 25;
	// 	while (y < 35)
	// 	{
			// printf("Player Position: X(%.2f)   Y(%.2f)\n", image->xposition_p, image->yposition_p);
			mlx_put_pixel(image->img, image->xposition_p, image->yposition_p, color);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// int x = -35;
    // int y;
    // int err;

    // while (x <= 35)
    // {
    //     y = -35;
    //     while (y <= 35)
    //     {
    //         err = x * x + y * y - 8 * 8;
    //         if (err <= 0)
    //             mlx_put_pixel(image->img,  image->xposition_p + 30 + x, image->yposition_p + 30 + y, color);
    //         y++;
    //     }
    //     x++;
    // }

	float px;
	float py;
	float	var = 0;
	// while (var <= 30)
	// {
		px = image->xposition_p + 60 * cos((image->x + var) * (M_PI/180));
		py = image->yposition_p + 60 * sin((image->x + var) * (M_PI/180));
		DDA(image->xposition_p, image->yposition_p, px , py, image);
	// 	var += 1;
	// }
	// image->xposition_p += 30;
	// image->yposition_p += 30;
	
}

void	drow_image(void *img)
{
	int	i;
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
				drow_pixel(0x696ca5, image, (j * 60), (i * 60));
			if (ft_strchr("ESNW", image->map[i][j]))
			{
				image->xposition_p = (j * 60) + image->move_x + 30;
	 			image->yposition_p = (i * 60) + image->move_y + 30;
			}
			j++;
		}
		i++;
	}
	printf("Player Position ==> X{%d}  Y{%d}\n", (int)(image->xposition_p - 60) % 60, (int)(image->yposition_p - 60) % 60);
	drow_pixel_player(0xe6e6f0, image);
}

int		check_draw_pixel_player(t_image *image, int n)
{
	int x = -5;
	while (x < 5)
	{
		// int a = (int)(image->yposition_p - 10) / 60;
		// int b = (int)(image->x + x) / 60;
		// printf("Y[%d]  X[%d]\n", a, b);
		if ((image->map[(int)((image->yposition_p - 10) / 60)][(int)((image->xposition_p  + x) / 60)] == '1') && n == 3)
			return (0);
		if (image->map[(int)((image->yposition_p + 10) / 60)][(int)((image->xposition_p  + x) / 60)] == '1' && n == 4)
			return (0);
		if (image->map[(int)((image->yposition_p + x) / 60)][((int)(image->xposition_p - 10) / 60)] == '1' && n == 1)
			return (0);
		if (image->map[(int)((image->yposition_p + x) / 60)][((int)(image->xposition_p + 10) / 60)] == '1' && n == 2)
			return (0);
		x++;
	}
	return (1);
}

void	key_hook(mlx_key_data_t keydata, void *para)
{
	t_image *image;

	image = (t_image *)para;

	if (keydata.key == 256)
	{
		mlx_delete_image(image->mlx, image->img);
		print_intersactions();
		exit(0);
	}
	if (keydata.key == 264)
	{
		if (check_draw_pixel_player(image, 3) != 0)
			image->move_x -=  2 * cos(image->x * (M_PI/180));
			image->move_y -=  2 * sin(image->x * (M_PI/180));
	}
	if (keydata.key == 265)
	{
		if (check_draw_pixel_player(image, 4) != 0)
			image->move_x +=  2 * cos(image->x * (M_PI/180));
			image->move_y +=  2 * sin(image->x * (M_PI/180));
	}
	if (keydata.key == 263)
	{
		image->x -= 0.5;
	}
	if (keydata.key == 262)
	{
		image->x += 0.5;
	}
}

void	create_window(char **map)
{
	t_image image;

	image.map = map;
	image.window_height = map_size(map) * 60;
	image.window_with = get_largest_line(map) * 60;
	image.move_x = 0;
	image.move_y = 0;
	image.xposition_p = 0;
	image.yposition_p = 0;
	image.x = 1;
	image.mlx =  mlx_init(image.window_with, image.window_height , "cub3D", 0);
	image.img = mlx_new_image(image.mlx, image.window_with, image.window_height);
	mlx_image_to_window(image.mlx, image.img, 0, 0);
	mlx_loop_hook(image.mlx, drow_image, &image);
	mlx_key_hook(image.mlx, &key_hook, &image);
	mlx_loop(image.mlx);
	mlx_terminate(image.mlx);

}

int		main(int ac, char **av)
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
	saves = malloc(1000 * sizeof(float));
	counter = 0;
	create_window(map);

}
