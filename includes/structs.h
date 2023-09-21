/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:33:14 by esalim            #+#    #+#             */
/*   Updated: 2023/09/21 13:18:02 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "../mlx/include/MLX42/MLX42.h"

/**
 * @brief Struct of 5 elements, one for the size (or len) of the pointer if exists,
 *          the rest elements for storing color number. => struct {red, green, blue, alpha, size}.
 * @param red 
 * @param green
 * @param
 * @param 
 */
typedef struct s_color
{
	unsigned char	red;    // storing number form 0 to 255
	unsigned char	green;  // storing number form 0 to 255
	unsigned char	blue;   // storing number form 0 to 255
	unsigned char	alpha;  // storing number form 0 to 255
	int				size;   // len of pointer, just for break loops.
}	t_color;


/**
 * @brief Union of 2 elements path (for file path value) and color (for the color value).
 */
typedef	union u_value
{
	char	*path;          //  pointer to textures path value.
	t_color	*color;         //  pointer to color value.
}	t_value;

/**
 * @brief Struct of 2 elements name(Key) and value
 * 
 */
typedef struct s_elements
{
	char    *name;          //  
	t_value	value;
}   t_elements;

typedef struct s_texture
{
	t_color	**pixels;
	int		height;	
	int		width;	
}	t_texture;


typedef struct s_mapInfo
{
	t_texture		*north;
	t_texture		*west;
	t_texture		*south;
	t_texture		*east;
	unsigned long	ceilingColor;
	unsigned long	floorColor;
}	t_mapInfo;

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t*	img;
	mlx_image_t*	mapScreen;
	t_elements*		elements;
	char			**map;
	float			xposition_p;
	float			yposition_p;
	float			px;
	float			py;
	float			angle;
	float			ray_angle;
	float			xverticale;
	float			yverticale;
	float			xhorizontal;
	float			yhorizontal;
	int				vx;
	int				vy;
	float			angle_right;
	float			angle_left;
	int 			verticalLength;
	int				playerSpeed;
	int				angleSpeed;
	char			displayMiniMap;
	char			allowedCursor;
	t_mapInfo		mapInfo;
	float			xMap;
	float			yMap;
}	t_image;

#endif