#include "../../includes/cub.h"

t_elements	*parsing_elements(char **elements)
{
	char    **split_value;
	int i;
	int len;
	t_elements	*dest;

	if (!elements)
		return (NULL);
	dest = ft_calloc(map_size(elements) + 1, sizeof(t_elements));
	if (!dest)
	{
		ft_putendl_fd("calloc failed in parsing_elements() function", 2);
		return (NULL);
	}
	i = -1;
	len = 0;
	while (elements[++i])
	{
		split_value = ft_split(elements[i], ' ');
		if (!split_value)
			return (ft_free(dest), ft_putendl_fd("Error: ft_split error", 2), NULL);
		if (map_size(split_value) != 2)
		{
			free_double_pointer(split_value);
			ft_free(dest);
			return (ft_putendl_fd("Error: extra args for element", 2), NULL);
		}
		int split_len = ft_strlen(split_value[0]);
		if (split_value[0] && (!ft_strncmp(split_value[0], "NO", split_len) \
			|| !ft_strncmp(split_value[0], "SO", split_len) \
			|| !ft_strncmp(split_value[0], "WE", split_len) \
			|| !ft_strncmp(split_value[0], "EA", split_len) ))
		{
			dest[len].name = ft_strdup(split_value[0]);
			dest[len].value.path = ft_strdup(split_value[1]);
			len++;
		}
		else if (split_value[0] && (!ft_strncmp(split_value[0], "F", split_len)\
			|| !ft_strncmp(split_value[0], "C", split_len)))
		{
			dest[len].name = ft_strdup(split_value[0]);
			dest[len].value.color = parsing_colors(split_value[1]);
			if (!dest[len].value.color)
			{
				free_double_pointer(split_value);
				ft_free(dest);
				return (NULL);
			}
			len++;
		}
		free_double_pointer(split_value);
	}
	ft_bzero(&dest[len], sizeof(*dest));
	return (dest);
}

t_color		*parsing_colors(char	*str_color)
{
	char	**split_value;
	t_color	*color;

	color = ft_calloc(2, sizeof(*color));
	if (!color)
		return(NULL);
	split_value = ft_split(str_color, ',');
	if (map_size(split_value) != 3)
	{
		ft_putendl_fd("Error: color invalid", 2);
		free_double_pointer(split_value);
		ft_free(color);
		return (NULL);
	}
	color[0].red = ft_atoi(split_value[0]);
	if (color[0].red > 255 || color[0].red < 0)
	{
		ft_putendl_fd("Error: color invalid", 2);
		free_double_pointer(split_value);
		ft_free(color);
		return (NULL);
	}
	color[0].green = ft_atoi(split_value[1]);
	if (color[0].green > 255 || color[0].green < 0)
	{
		ft_putendl_fd("Error: color invalid", 2);
		free_double_pointer(split_value);
		ft_free(color);
		return (NULL);
	}
	color[0].blue = ft_atoi(split_value[2]);
	if (color[0].blue > 255 || color[0].blue < 0)
	{
		ft_putendl_fd("Error: color invalid", 2);
		free_double_pointer(split_value);
		ft_free(color);
		return (NULL);
	}
	free_double_pointer(split_value);
	ft_bzero(&color[1], sizeof(*color));
	return (color);
}
