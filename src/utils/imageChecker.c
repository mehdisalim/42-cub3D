/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imageChecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:56:01 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 22:57:55 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"

int	check_textures(t_image *image)
{
	if (!image->map_info.east || !image->map_info.west \
			|| !image->map_info.north || !image->map_info.south)
		return (0);
	return (1);
}
