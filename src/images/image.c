/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:31:51 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 12:19:23 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

/**
 * @brief 
 * 
 * @param image 
 * @param move 
 * @param angle 
 * @return int 
 */
int check(t_image *image, int move, float angle)
{
	int xx;
	int yy;

	yy = (image->yMap + move * sin(angle * (M_PI / 180)));
	xx = (image->xMap + move * cos(angle * (M_PI / 180)));
	if ((image->map[(yy + 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1' || image->map[(yy - 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1') \
		&& (image->map[yy / MINIMAPSIZE][(xx + 4) / MINIMAPSIZE] == '1' || image->map[yy / MINIMAPSIZE][(xx - 4) / MINIMAPSIZE] == '1'))
		return (0);
	if ((image->map[(yy + 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1' || image->map[(yy - 4) / MINIMAPSIZE][xx / MINIMAPSIZE] == '1') \
		&& (image->map[yy / MINIMAPSIZE][(xx + 4) / MINIMAPSIZE] != '1' || image->map[yy / MINIMAPSIZE][(xx - 4) / MINIMAPSIZE] != '1'))
		return (4);
	if ((image->map[(yy + 4) / MINIMAPSIZE][xx / MINIMAPSIZE] != '1' || image->map[(yy - 4) / MINIMAPSIZE][xx / MINIMAPSIZE] != '1') \
		&& (image->map[yy / MINIMAPSIZE][(xx + 4) / MINIMAPSIZE] == '1' || image->map[yy / MINIMAPSIZE][(xx - 4) / MINIMAPSIZE] == '1'))
		return (5);
	return (1);
}

/**
 * @brief 
 * 
 * @param image 
 * @param n 
 * @return int 
 */
int check_draw_pixel_player(t_image *image, int n)
{
	if (n == 3)
		return (check(image, image->playerSpeed, image->angle));
	if (n == 4)
		return (check(image, -image->playerSpeed, image->angle));
	if (n == 1)
		return (check(image, image->playerSpeed, image->angle_right));
	if (n == 2)
		return (check(image, image->playerSpeed, image->angle_left));
	return (1);
}

/**
 * @brief callBack function of mlx_cursor_hook 
 * 
 * @param xpos	x position on the window
 * @param ypos	y position on the window
 * @param param the parameter passed by mlx_cursor_hook
 */
void cursor_hook(double xpos, double ypos, void *param)
{
	static double constXPos;

	t_image *image = (t_image *)param;
	if (image->allowedCursor == DISABLE || ypos > HEIGHT || ypos < 0)
		return;
	if (xpos > 0 && xpos < constXPos)
		image->angle -= image->angleSpeed;
	else if (xpos > constXPos && xpos < WIDTH)
		image->angle += image->angleSpeed;
	constXPos = xpos;
}

/**
 * @brief allocate new image and initialize all variables inside struct
 * 
 * @param elements	struct of elements that already parsing in main
 * @param map 		2d array of map characters
 * @return t_image* new image 
 */
t_image *initStruct(t_elements *elements, char **map)
{
	t_image *image;

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
	image->playerSpeed = 5;
	image->angleSpeed = 3;
	image->displayMiniMap = ENABLE;
	image->allowedCursor = ENABLE;
	image->verticalLength = map_size(map);
	image->map_image = get_texture("./assets/Subtract1.png");
	image->mapInfo.north = get_texture((char *)getDataFromElements(elements, "NO"));
	image->mapInfo.south = get_texture((char *)getDataFromElements(elements, "SO"));
	image->mapInfo.east = get_texture((char *)getDataFromElements(elements, "EA"));
	image->mapInfo.west = get_texture((char *)getDataFromElements(elements, "WE"));
	image->mapInfo.ceilingColor = get_color(*(t_color *)getDataFromElements(elements, "C"));
	image->mapInfo.floorColor = get_color(*(t_color *)getDataFromElements(elements, "F"));
	return (image);
}

/**
 * @brief Get the Player Position im map and set Angle of Player
 * 
 * @param image global struct
 */
void	getPlayerPosition(t_image *image)
{
	char	*player;
	int		i;
	int		j;
	int		hasEntered;

	i = 0;
	hasEntered = 0;
	while (image->map[i])
	{
		j = 0;
		while (image->map[i][j])
		{
			player = ft_strchr("ESNW", image->map[i][j]);
			if (player && hasEntered == 0)
			{
				image->xposition_p = (j * TILESIZE) + (TILESIZE / 2);
				image->yposition_p = (i * TILESIZE) + (TILESIZE / 2);
				image->xMap = (j * MINIMAPSIZE) + (MINIMAPSIZE / 2);
				image->yMap = (i * MINIMAPSIZE) + (MINIMAPSIZE / 2);
				if (*player == 'N')
					image->angle = 270;
				else if (*player == 'E')
					image->angle = 0;
				else if (*player == 'S')
					image->angle = 180;
				else if (*player == 'W')
					image->angle = 90;	
				hasEntered = 1;
			}
			j++;
		}
		i++;
	}
}

t_list*	get_guns_textures( void )
{
	t_list *head = NULL;
	t_texture *texture;
	char *tmp;
	char *path;
	int i = 2;
	while (i <= 20)
	{
		char *number = ft_itoa(i);
		path = ft_strdup("assets/valorant2/");
		tmp = ft_strjoin(path, number);
		free(number);
		free(path);
		path = ft_strjoin(tmp, ".png");
		free(tmp);
		printf("|%s|\n", path);
		texture = get_texture(path);
		free(path);
		ft_lstadd_front(&head, ft_lstnew(texture));
		i++;
	}
	return (head);
}

/**
 * @brief Create a window object and setuping mlx ghraphical user interface
 * 
 * @param elements struct of element that already parsing in main2
 * @param map 		double pointer that contains map characters
 * @return none
 */
void create_window(t_elements *elements, char **map)
{
	t_image *image;

	image = initStruct(elements, map); // initialization global struct.
	image->elements = elements;
	image->map = map;
	// image->guns = get_guns_textures();
	image->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0); // Initializes a new MLX42 Instance.
	image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT); //Creates and allocates a new image buffer for the Game Screen.
	image->mapScreen = mlx_new_image(image->mlx, 220, 220); // Creates and allocates a new image buffer for the Mini Map.
	getPlayerPosition(image); 
	mlx_image_to_window(image->mlx, image->img, 0, 0); // Draws a new instance of an image, it will then share the same pixel buffer as the image.
	mlx_image_to_window(image->mlx, image->mapScreen, 0, HEIGHT - 220); // Draws a new instance of an image, it will then share the same pixel buffer as the image.
	// mlx_image_to_window(image->mlx, image->gunScreen, 0, 0); // Draws a new instance of an image, it will then share the same pixel buffer as the image.
	mlx_key_hook(image->mlx, &key_hook, image); // This function sets the key callback, which is called when a key is pressed on the keyboard. Useful for single keypress detection.
	mlx_cursor_hook(image->mlx, &cursor_hook, image); // This function sets the cursor callback, which is called when the mouse position changes. Position is relative to the window.
	mlx_loop_hook(image->mlx, drow_image, image); // Generic loop hook for any custom hooks to add to the main loop. Executes a function per frame, so be careful.
	mlx_loop(image->mlx); // Initializes the rendering of MLX, this function won't return until mlx_close_window is called, meaning it will loop until the user requests that the window should close.
	mlx_delete_image(image->mlx, image->mapScreen); // 
	mlx_delete_image(image->mlx, image->img); // 
	mlx_terminate(image->mlx); // 
	destroy_program(image); // 
}
