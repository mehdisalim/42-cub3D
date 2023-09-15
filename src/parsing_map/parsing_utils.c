/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:36:00 by esalim            #+#    #+#             */
/*   Updated: 2023/09/14 10:46:52 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
