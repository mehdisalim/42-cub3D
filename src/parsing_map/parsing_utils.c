/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:36:00 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 16:48:48 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/**
 * @brief Get the elements and map length.
 * 
 * @param map map contains.
 * @param i_elem index of elements.
 * @param i_map  index of map.
 */
void	get_elements_and_map_len(char **map, int *i_elem, int *i_map)
{
	char	*tmp;
	int		i;

	*i_elem = 0;
	*i_map = 0;
	i = -1;
	while (map[++i])
	{
		tmp = ft_strtrim(map[i], "  ");
		if (tmp && (!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "SO ", 3) \
			|| !ft_strncmp(tmp, "WE ", 3) || !ft_strncmp(tmp, "EA ", 3) \
			|| !ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "C ", 2)))
			(*i_elem)++;
		else
			(*i_map)++;
		free(tmp);
	}
}

size_t	get_map_size(char *map_name)
{
	char	*line;
	int		fd;
	size_t	length;

	if (!map_name)
		return (0);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	length = 0;
	while (line)
	{
		free(line);
		length++;
		line = get_next_line(fd);
	}
	close(fd);
	return (length);
}

char	is_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	map_size(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}
