/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/08/26 18:20:59 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../includes/cub3.h"

void	drow_pixel(unsigned int color, t_image *image, int xx, int yy)
{
	int x;
	int y;
	int ly;
	
	x = 0;
	while (x < 60)
	{
		y = 0;
		while (y < 60)
		{
			mlx_put_pixel(image->img,(x + xx) , (y + yy), color);
			if (y == 0)
				mlx_put_pixel(image->img,(x + xx) , (y + yy), 0xffffff);
			y++;
		}
		x++;
	}

	
	y = 0;
	ly = 0;
	while (ly < 600)
	{
		x = 0;
		while (x <= 600)
		{
			y = 0;
			while (y < 60)
			{
				mlx_put_pixel(image->img,(x) , ly + y, 0xffffff);
				y++;
			}
			x += 60;
		}
		ly += 60;
	}
}
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
			mlx_put_pixel(image->img, image->xposition_p + x, image->yposition_p + y, color);
			y++;
		}
		x++;
	}
	image->xposition_p += 30;
	image->yposition_p += 30;
	y = 0;
	int i = 0;
	x = 0;
	while (y < 0)
	{
		i = 0;
		while (i < 2)
		{
			mlx_put_pixel(image->img, image->xposition_p - x , image->yposition_p + y, 0x000000);
			i++;
			y++;
		}
		x += 1;
	}
	
}

void	drow_image(void *img)
{
	int i;
	int j;
	int yy;
	int xx;

	i = 0;
	j = 0;
	xx = 0;
	yy = 0;
	t_image *image;

	image = (t_image *)img;
	while (i < 10)
	{
		j = 0;
		xx = 0;
		while (j < 10)
		{
			if (image->map[i][j] == '1')
				drow_pixel(0xFF0000FF, image, xx, yy);
			else if (image->map[i][j] == '0' || image->map[i][j] == 'N')
				drow_pixel(0x696ca5, image, xx, yy);
			j++;
			xx += 60;
		}
		yy += 60;
		i++;
	}

	i = 0;
	j = 0;
	xx = 0;
	yy = 0;
	while (i < 10)
	{
		j = 0;
		xx = 0;
		while (j < 10)
		{
			if (image->map[i][j] != '1' && image->map[i][j] != '0')
			{
				image->xposition_p = xx + image->move_x;
				image->yposition_p = yy + image->move_y;
				drow_pixel_player(0xe6e6f0, image);
			}
			j++;
			xx += 60;
		}
		yy += 60;
		i++;
	}
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
	else if (keydata.key == 263)
	{
		if (check_draw_pixel_player(image, 1) != 0)
			image->move_x -= 5;
	}
	else if (keydata.key == 262)
	{
		if (check_draw_pixel_player(image, 2) != 0)
			image->move_x += 5;
	}
	else if (keydata.key == 265)
	{
		if (check_draw_pixel_player(image, 3) != 0)
			image->move_y -= 5;
	}
	else if (keydata.key == 264)
	{
		if (check_draw_pixel_player(image, 4) != 0)
			image->move_y += 5;
	}
	else if (keydata.key == 65)
	{
	}
	else if (keydata.key == 68)
	{
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
	image.mlx =  mlx_init(WIDTH, HEIGHT , "cub3D", image.mlx);
	image.img = mlx_new_image(image.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(image.mlx, image.img, 0, 0);
	mlx_loop_hook(image.mlx, drow_image, &image);
	mlx_key_hook(image.mlx, &key_hook, &image);
	mlx_loop(image.mlx);
	mlx_terminate(image.mlx);

}

int main()
{
	char **map;

	map = malloc(sizeof(char) * 10);
	map[0] = "1111111111";
	map[1] = "1001100101";
	map[2] = "1000000001";
	map[3] = "1010000011";
	map[4] = "1000111001";
	map[5] = "1N01100111";
	map[6] = "1000000001";
	map[7] = "1010101001";
	map[8] = "1001000001";
	map[9] = "1111111111";
	// printf("|||%c\n", map[0][0]);
	create_window(map);

}
