/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:33:14 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 22:35:19 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../mlx/include/MLX42/MLX42.h"
# include "../libft/libft.h"

/**
 * @brief Struct of 5 elements, one for the size (or len) 
 * 			of the pointer if exists, the rest elements for storing 
 * 			color number. => struct {red, green, blue, alpha, size}.
 * @param red 
 * @param green
 * @param
 * @param 
 */
typedef struct s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	alpha;
	int				size;
}	t_color;

/**
 * @brief Union of 2 elements path (for file path value) 
 * 			and color (for the color value).
 */
typedef union u_value
{
	char	*path;
	t_color	*color;
}	t_value;

/**
 * @brief Struct of 2 elements name(Key) and value
 * 
 */
typedef struct s_elements
{
	char	*name;
	t_value	value;
}	t_elements;

typedef struct s_texture
{
	t_color	**pixels;
	int		height;	
	int		width;	
}	t_texture;

typedef struct s_minimap
{
	float			ystartmap;
	float			yendmap;
	float			xendmap;
	float			xstart;
	float			ystart;
	unsigned int	i;
	unsigned int	j;
	float			xstartmap;
	float			xtmp;
	float			ytmp;
}	t_minimap;

typedef struct s_dda
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	int		i;
}	t_dda;

typedef struct s_cerclemap
{
	int	circleray;
	int	border;
	int	x;
	int	y;
	int	err;
	int	t;
}	t_cerclemap;

typedef struct s_map_info
{
	t_texture		*north;
	t_texture		*west;
	t_texture		*south;
	t_texture		*east;
	unsigned long	ceiling_color;
	unsigned long	floor_color;
}	t_map_info;

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*map_screen;
	t_elements		*elements;
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
	int				vertical_length;
	int				player_speed;
	int				angle_speed;
	char			display_mini_map;
	char			allowed_cursor;
	t_map_info		map_info;
	float			x_map;
	float			y_map;
	float			position;
}	t_image;

#endif
