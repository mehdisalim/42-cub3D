/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:39:27 by esalim            #+#    #+#             */
/*   Updated: 2023/09/14 14:42:19 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	check_wall(char **map)
{
	int	x;
	int	q;

	if (!map || !*map)
		return (ft_putendl_fd("Error: Empty map", 2), 0);
	x = -1;
	while (map[0][++x])
		if (!ft_strchr("1 ", map[0][x]))
			return (ft_putendl_fd("Error: Wall invalid", 2), 0);
	q = map_size(map) - 1;
	x = -1;
	while (map[q][++x])
		if (!ft_strchr("1 ", map[q][x]))
			return (ft_putendl_fd("Error: Wall invalid", 2), 0);
	x = -1;
	while (map[++x])
		if (!ft_strchr("1 ", map[x][0]) \
			|| !ft_strchr("1 ", map[x][ft_strlen(map[x]) - 1]))
			return (ft_putendl_fd("Error: Wall invalid", 2), 0);
	return (1);
}

char	check_invalid_char(char	**map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10 NSWE", map[i][j]))
				return (ft_putendl_fd("Error: invalid character in map", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

char	check_player(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
				p++;
			j++;
		}
		i++;
	}
	if (p == 1)
		return (1);
	ft_putendl_fd("Error: Player Error", 2);
	return (0);
}

char	check_space(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("0NSEW", map[i][j]) \
				&& (ft_strchr(" \0", map[i][j + 1]) \
				|| ft_strchr(" \0", map[i][j - 1]) \
				|| ft_strchr(" \0", map[i + 1][j]) \
				|| ft_strchr(" \0", map[i - 1][j])))
				return (ft_putendl_fd("Error: Space in map", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

char	check_elements(char **map_content)
{
	int	i;
	int	data[6];

	i = -1;
	ft_bzero(data, 6 * sizeof(int));
	while (map_content[++i])
	{
		if (!ft_strncmp(map_content[i], "NO ", 3))
			data[0]++;
		if (!ft_strncmp(map_content[i], "SO ", 3))
			data[1]++;
		if (!ft_strncmp(map_content[i], "WE ", 3))
			data[2]++;
		if (!ft_strncmp(map_content[i], "EA ", 3))
			data[3]++;
		if (!ft_strncmp(map_content[i], "F ", 2))
			data[4]++;
		if (!ft_strncmp(map_content[i], "C ", 2))
			data[5]++;
	}
	if (data[0] != 1 || data[1] != 1 || data[2] != 1 \
			|| data[3] != 1 || data[4] != 1 || data[5] != 1)
		return (ft_putendl_fd("Error: elements error", 2), 0);
	return (1);
}
