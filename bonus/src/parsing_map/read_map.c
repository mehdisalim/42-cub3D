/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:49:21 by esalim            #+#    #+#             */
/*   Updated: 2023/09/25 10:19:29 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**get_map_content(char *map_name, char *checker)
{
	char	**content;
	char	*str;
	int		fd;
	int		i;

	content = ft_calloc(get_map_size(map_name) + 1, sizeof(*content));
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		*checker = 1;
		return (free(content), NULL);
	}
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		content[i++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (content);
}

char	**get_new_map(char **old_map)
{
	char	**new_map;
	int		i;
	int		len;

	i = -1;
	while (old_map[++i])
		if (ft_strlen(old_map[i]) > 1 && old_map[i][0] != '\n')
			break ;
	new_map = ft_calloc((size_t)(map_size(old_map) - i + 1), sizeof(*new_map));
	len = 0;
	while (old_map[i])
		new_map[len++] = ft_strdup(old_map[i++]);
	free_double_pointer(old_map);
	return (new_map);
}

void	print_map(char **map_content)
{
	int	i;

	i = 0;
	while (map_content[i])
		printf("|%s|\n", map_content[i++]);
}
