/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawDynamicMap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:50:53 by esekouni          #+#    #+#             */
/*   Updated: 2023/09/24 20:23:53 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

void	draw_mini_map_2(t_image *image, t_minimap *map,
		unsigned long south_color, unsigned long west_color)
{
	while (map->ystartmap < map->yendmap)
	{
		map->i = (map->ystartmap - (MINIMAPSIZE / 2)) / MINIMAPSIZE;
		map->xstartmap = map->xstart;
		while (map->xstartmap < map->xendmap)
		{
			map->xtmp = map->xstartmap - map->xstart;
			map->ytmp = map->ystartmap - map->ystart;
			map->j = (map->xstartmap - (MINIMAPSIZE / 2)) / MINIMAPSIZE;
			if (map->i < (unsigned int)image->vertical_length
				&& map->j < (unsigned int)ft_strlen(image->map[map->i]))
			{
				if (image->map[map->i][map->j] == '1')
					draw_pixel(west_color, image, map->xtmp, map->ytmp);
				else if (!ft_strchr("1 ", image->map[map->i][map->j]))
					draw_pixel(south_color, image, map->xtmp, map->ytmp);
				else
					draw_pixel(0, image, map->xtmp, map->ytmp);
			}
			else
				draw_pixel(0, image, map->xtmp, map->ytmp);
			map->xstartmap++;
		}
		map->ystartmap++;
	}
}

void	draw_mini_map(t_image *image, unsigned long south_color,
		unsigned long west_color)
{
	t_minimap	map;

	map.ystartmap = image->y_map - 100;
	map.yendmap = image->y_map + 100;
	map.xendmap = image->x_map + 100;
	map.xstart = image->x_map - 100;
	map.ystart = map.ystartmap;
	draw_mini_map_2(image, &map, south_color, west_color);
}

void	draw_cercle_map_2(t_image *image, t_cerclemap *cmap)
{
	while (++(cmap->x) < cmap->circleray)
	{
		cmap->y = -cmap->circleray - 1;
		while (++(cmap->y) < cmap->circleray)
		{
			cmap->err = cmap->x * cmap->x + cmap->y * cmap->y
				- cmap->circleray * cmap->circleray;
			if (cmap->err > 0)
				mlx_put_pixel(image->map_screen, cmap->circleray + cmap->x
					+ cmap->border, cmap->circleray
					+ cmap->y + cmap->border, 0);
			else if (cmap->err > -200 && cmap->err <= 0)
				mlx_put_pixel(image->map_screen, cmap->circleray + cmap->x
					+ cmap->border, cmap->circleray
					+ cmap->y + cmap->border, 0xffffff);
		}
		if (cmap->t < 210)
		{
			draw_pixel(0, image, 0, cmap->t);
			draw_pixel(0, image, cmap->t, 0);
			draw_pixel(0, image, 200, cmap->t);
			draw_pixel(0, image, cmap->t, 200);
			cmap->t += 20;
		}
	}
}

void	draw_cercle_map(t_image *image)
{
	t_cerclemap	cerclemap;

	cerclemap.circleray = 90;
	cerclemap.border = 110 - cerclemap.circleray;
	cerclemap.x = -cerclemap.circleray - 1;
	cerclemap.t = 0;
	draw_cercle_map_2(image, &cerclemap);
}

void	draw_dynamic_map(t_image *image)
{
	unsigned long	south_color;
	unsigned long	west_color;

	if (image->map_info.south->height / 2 - 1 < 0
		|| image->map_info.north->height / 2 - 1 < 0)
	{
		south_color = 0xff0ff0;
		west_color = 0xAAABBB;
	}
	else
	{
		south_color = get_color(image->map_info.south->pixels
			[image->map_info.south->height / 2 - 1]
			[image->map_info.south->width / 2 - 1]);
		west_color = get_color(image->map_info.west->pixels
			[image->map_info.north->height / 2 - 1]
			[image->map_info.west->width / 2 - 1]);
		if (west_color == south_color)
			west_color += 1000;
	}
	draw_mini_map(image, south_color, west_color);
	draw_player(image, 110, 110);
	draw_cercle_map(image);
}
