/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:24:42 by esalim            #+#    #+#             */
/*   Updated: 2022/11/03 14:32:27 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *str)
{
	char	*newline;

	newline = ft_strchr(str, '\n');
	if (!str[0])
		return (NULL);
	if (!newline)
		return (ft_strdup(str));
	return (ft_substr(str, 0, newline - str + 1));
}

char	*ft_getbuffer(char *line)
{
	char	*buff;
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (!newline)
		return (free(line), NULL);
	if (*(++newline))
	{
		buff = ft_strdup(newline);
		free(line);
		return (buff);
	}
	return (free(line), ft_strdup(""));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			n;

	n = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			n = 0;
		buff[n] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	line = ft_getline(str);
	str = ft_getbuffer(str);
	return (line);
}
