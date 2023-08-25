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



char	**get_map_content(char *map_name)
{
	char	**content;
	char	*str;
	int		fd;
	int		i;

	content = ft_calloc(get_map_size(map_name) + 1, sizeof(*content));
	if (!content)
	{
		ft_putstr_fd("calloc failed in get_map_content() function\n", 2);
		return (NULL);
	}
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
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

int		get_newline_pos(char *str)
{
	int	i = -1;
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

void	print_map(char **map_content)
{
	int	i = 0;

	while (map_content[i])
		printf("%s\n", map_content[i++]);
}

void	separate_map(char **map_content, char ***elements_part, char ***map_part)
{
	int	i;
	int	i_elem;
	int	i_map;

	i = -1;
	i_elem = 0;
	i_map = 0;
	while (map_content[++i])
	{
		if (!ft_strnstr(map_content[i], "NO ", 3) \
			|| !ft_strnstr(map_content[i], "SO ", 3) \
			|| !ft_strnstr(map_content[i], "WE ", 3) \
			|| !ft_strnstr(map_content[i], "EA ", 3) \
			|| !ft_strnstr(map_content[i], "F ", 2) \
			|| !ft_strnstr(map_content[i], "C ", 2))
			i_elem++;
		else
			i_map++;
	}
	*elements_part = ft_calloc(i_elem + 1, sizeof(**elements_part));
	*map_part = ft_calloc(i_map + 1, sizeof(**map_part));
	if (!*elements_part || !*map_part)
	{
		ft_putstr_fd("calloc failed in separate_map() function\n", 2);
		return ;
	}
	i = -1;
	i_elem = 0;
	i_map = 0;
	while (map_content[++i])
	{
		int len = ft_strlen(map_content[i]);
		if (!ft_strnstr(map_content[i], "NO ", len) \
			|| !ft_strnstr(map_content[i], "SO ", len) \
			|| !ft_strnstr(map_content[i], "WE ", len) \
			|| !ft_strnstr(map_content[i], "EA ", len) \
			|| !ft_strnstr(map_content[i], "F ", 2) \
			|| !ft_strnstr(map_content[i], "C ", 2))
			elements_part[0][i_elem++] = ft_strdup(map_content[i]);
		else
			map_part[0][i_map++] = ft_strdup(map_content[i]);
		free(map_content[i]);
	}
	free(map_content);
}

int		map_size(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
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
	new_map = ft_calloc(map_size(old_map) - i + 1, sizeof(*new_map));
	if (!new_map)
	{
		ft_putstr_fd("calloc failed in get_new_map() function\n", 2);
		return (NULL);
	}
	len = 0;
	while (old_map[i])
		new_map[len++] = ft_strdup(old_map[i++]);
	free_double_pointer(old_map);
	return (new_map);
}

char	check_wall(char **map)
{
	int	x;
	int	y;
	int	xlen;
	int	ylen;

	x = 0;
	y = 0;
	xlen = ft_strlen(map[y]) - 1;
	ylen = map_size(map);
	while (x < xlen)
	{
		if (!ft_strchr("1 ", map[y][x]) || !ft_strchr("1 ", map[ylen - 1][x]))
			return (printf("Error: wall is incorrect !\n"), 0);
		x++;
	}
	y = -1;
	while (++y < ylen)
		if (!ft_strchr("1 ", map[y][0])
			|| (!ft_strchr("1 ", map[y][xlen]) && (y == ylen))
			|| (!ft_strchr("1 ", map[y][xlen - 1]) && (y + 1 == ylen)))
			return (printf("Error: wall is incorrect !\n"), 0);
	return (1);
}

void	checking(char i)
{
	if (i)
		printf("map is valid \n");
	else
		printf("map is invalid \n");
}

char	check_player(char **map)
{
	int i = 0;
	int j = 0;
	int p = 0;

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
	return (p == 1);
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
			if (ft_strchr("0NSEW", map[i][j]) && (map[i][j + 1] == ' ' \
				|| map[i][j - 1] == ' ' || map[i + 1][j] == ' ' \
				|| map[i - 1][j] == ' '))
					return (ft_putendl_fd("Error: Space in map", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**trim_elements(char **elements)
{
	char	*tmp;
	int		i;

	i = -1;
	while (elements[++i])
	{
		tmp = elements[i];
		elements[i] = ft_strtrim(elements[i], "  ");
		free(tmp);
	}
	return (elements);
}

char	check_map(char *map_name, char ***elements, char ***map)
{
	char	**map_content;

	if (!map_name)
		return (0);
	map_content = get_map_content(map_name);
	if (!map_content)
		return (0);
	
	// separate map to two parts (Elements part and map part)
	separate_map(map_content, elements, map);

	// remove all newlines in the end of strings
	remove_newlines(*elements);

	// ==============
	*elements = trim_elements(*elements);
	print_map(*elements);

	// create new map without newlines in the beginning
	*map = get_new_map(*map);
	remove_newlines(*map);

	if (!check_elements(*elements) || !check_wall(*map) \
			|| !check_space(*map) || !check_player(*map))
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	char	**elements;
	char	**map;

	if (ac < 2)
	{
		ft_putstr_fd("bad args\n", 2);
		return (1);
	}
	checking(check_map(av[1], &elements, &map));
	return (0);    
}