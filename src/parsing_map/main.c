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
		content[i++] = str;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (content);
}

char	**check_map(char	*map_name)
{
	char	**map_content;
	int		i;

	if (!map_name)
		return (NULL);
	map_content = get_map_content(map_name);
	if (!map_content)
		return (NULL);
	i = -1;
	while (map_content[++i])
		printf("%s", map_content[++i]);
	return (map_content);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("bad args\n", 2);
		return (1);
	}
	check_map(av[1]);
	return (0);    
}