/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:21:59 by esalim            #+#    #+#             */
/*   Updated: 2023/09/09 08:54:21 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	get_newline_pos(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

void	remove_newlines(char **map_content)
{
	int	i;
	int	pos;

	if (!map_content)
		return ;
	i = -1;
	while (map_content[++i])
	{
		pos = get_newline_pos(map_content[i]);
		if (pos >= 0 && ft_strlen(map_content[i]) > 2)
			map_content[i][pos] = 0;
	}
}

void	separate_map(char **map, char ***elements_part, char ***map_part)
{
	int		i_elem;
	int		i_map;
	int		i;
	char	*tmp;

	i = -1;
	i_elem = 0;
	i_map = 0;
	while (map[++i])
	{
		tmp = ft_strtrim(map[i], "  ");
		if (tmp && (!ft_strncmp(tmp, "NO ", 3) \
			|| !ft_strncmp(tmp, "SO ", 3) \
			|| !ft_strncmp(tmp, "WE ", 3) \
			|| !ft_strncmp(tmp, "EA ", 3) \
			|| !ft_strncmp(tmp, "F ", 2) \
			|| !ft_strncmp(tmp, "C ", 2)))
			i_elem++;
		else
			i_map++;
		free(tmp);
	}
	*elements_part = ft_calloc(i_elem + 1, sizeof(char *));
	*map_part = ft_calloc(i_map + 1, sizeof(char *));
	if (!*elements_part || !*map_part)
	{
		ft_putstr_fd("calloc failed in separate_map() function\n", 2);
		return ;
	}
	i = -1;
	i_elem = 0;
	i_map = 0;
	while (map[++i])
	{
		tmp = ft_strtrim(map[i], "  ");
		if (tmp && (!ft_strncmp(tmp, "NO ", 3) \
			|| !ft_strncmp(tmp, "SO ", 3) \
			|| !ft_strncmp(tmp, "WE ", 3) \
			|| !ft_strncmp(tmp, "EA ", 3) \
			|| !ft_strncmp(tmp, "F ", 2) \
			|| !ft_strncmp(tmp, "C ", 2)))
			elements_part[0][i_elem++] = ft_strdup(map[i]);
		else
			map_part[0][i_map++] = ft_strdup(map[i]);
		free(tmp);
	}
	free_double_pointer(map);
}

char	**trim_elements(char **elements)
{
	char	*tmp;
	int		i;

	i = -1;
	while (elements[++i])
	{
		tmp = elements[i];
		elements[i] = ft_strtrim(elements[i], " ");
		free(tmp);
	}
	return (elements);
}

char	check_map(char *map_name, char ***elements, char ***map, char *checker)
{
	char	**map_content;

	if (!map_name)
		return (0);
	map_content = get_map_content(map_name, checker);
	if (!map_content || *checker)
		return (0);
	separate_map(map_content, elements, map);
	remove_newlines(*elements);
	*elements = trim_elements(*elements);
	*map = get_new_map(*map);
	remove_newlines(*map);
	return (!(!check_elements(*elements) || !check_wall(*map) \
			|| !check_invalid_char(*map) || !check_space(*map) \
			|| !check_player(*map)));
}
