/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:31:12 by esalim            #+#    #+#             */
/*   Updated: 2023/09/25 10:13:07 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief De-allocate struct t_elements
 * 
 * @param[in] elements the Elements struct to free
 */
void	free_elements(t_elements *elements)
{
	int	i;

	if (!elements)
		return ;
	i = 0;
	while (elements[i].name)
	{
		if (elements[i].name[0] != 'C' && elements[i].name[0] != 'F')
			free(elements[i].value.path);
		else
			free(elements[i].value.color);
		free(elements[i].name);
		i++;
	}
	free(elements);
}

void	free_double_pointer(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_texture(t_texture *texture)
{
	if (texture)
		free_double_pointer((char **)texture->pixels);
	free(texture);
}

void	destroy_program(t_image *image)
{
	free_texture(image->map_info.north);
	free_texture(image->map_info.west);
	free_texture(image->map_info.south);
	free_texture(image->map_info.east);
	free_elements(image->elements);
	free_double_pointer(image->map);
	free(image);
}
