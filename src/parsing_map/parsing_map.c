/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:04:29 by esalim            #+#    #+#             */
/*   Updated: 2023/09/23 21:03:46 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/**
 * @brief Parsing char ** into struct of elements.
 * 
 * @param elements 	2d array of elements
 * @return t_elements* if success the return is a pointer pointing to the first element, else will be return NULL.
 */
t_elements	*parsing_elements(char **elements)
{
	t_elements	*dest;
	int			i;
	int			len;
	int			split_len;
	char		**split_value;

	if (!elements)
		return (NULL);
	dest = ft_calloc(map_size(elements) + 1, sizeof(t_elements));
	if (!dest)
		return (NULL);
	i = -1;
	len = 0;
	while (elements[++i])
	{
		split_value = ft_split(elements[i], ' ');
		if (!split_value)
			return (free(dest), ft_putendl_fd("Error: ft_split err", 2), NULL);
		
		if (map_size(split_value) != 2)
		{
			free_double_pointer(split_value);
			free_elements(dest);
			return (ft_putendl_fd("Error: extra args for element", 2), NULL);
		}
		split_len = ft_strlen(split_value[0]);
		if (split_value[0] && (!ft_strncmp(split_value[0], "NO", split_len) \
			|| !ft_strncmp(split_value[0], "SO", split_len) \
			|| !ft_strncmp(split_value[0], "WE", split_len) \
			|| !ft_strncmp(split_value[0], "EA", split_len)))
		{
			dest[len].name = ft_strdup(split_value[0]);
			dest[len].value.path = ft_strdup(split_value[1]);
			len++;
		}
		else if (split_value[0] && (!ft_strncmp(split_value[0], "F", split_len)
				|| !ft_strncmp(split_value[0], "C", split_len)))
		{
			dest[len].name = ft_strdup(split_value[0]);
			dest[len].value.color = parsing_colors(split_value[1]);
			if (!dest[len].value.color)
			{
				free_double_pointer(split_value);
				free_elements(dest);
				return (NULL);
			}
			len++;
		}
		free_double_pointer(split_value);
	}
	ft_bzero(&dest[len], sizeof(*dest));
	return (dest);
}

/**
 * @brief	Counting number of time c char repeat in the string str.
 * 
 * @param str 	String to search in.
 * @param c		Char looking for.
 * @return unsigned int Number of repeating.
 */
unsigned int	get_char_len(char *str, char c)
{
	unsigned int len = 0;
	int i = -1;

	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			len++;
	return (len);
}

/**
 * @brief parsing colors into t_color* that will be store all informations about colors.
 * 
 * @param str_color	The string will be parsing.
 * @return t_color* Pointer to The first color that parsing in this function.
 */
t_color	*parsing_colors(char *str_color)
{
	char	**split_value;
	t_color	*col;

	if (get_char_len(str_color, ',') > 3)
		return (ft_putendl_fd("Error: color invalid", 2), NULL);
	col = ft_calloc(2, sizeof(t_color));
	if (!col)
		return (NULL);
	split_value = ft_split(str_color, ',');
	if (map_size(split_value) != 3)
		return (ft_putendl_fd("Error: color invalid", 2), \
			free_double_pointer(split_value), free(col), NULL);
	col[0].red = ft_atoi(split_value[0]);
	if (!is_number(split_value[0]) || (col[0].red > 255 || col[0].red < 0))
		return (ft_putendl_fd("Error: color invalid", 2), \
			free_double_pointer(split_value), free(col), NULL);
	col[0].green = ft_atoi(split_value[1]);
	if (!is_number(split_value[1]) || (col[0].green > 255 || col[0].green < 0))
		return (ft_putendl_fd("Error: color invalid", 2), \
			free_double_pointer(split_value), free(col), NULL);
	col[0].blue = ft_atoi(split_value[2]);
	if (!is_number(split_value[2]) || (col[0].blue > 255 || col[0].blue < 0))
		return (ft_putendl_fd("Error: color invalid", 2), \
			free_double_pointer(split_value), free(col), NULL);
	col[0].alpha	= 255;
	ft_bzero(&col[1], sizeof(t_color));
	return (free_double_pointer(split_value), col);
}
