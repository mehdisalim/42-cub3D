/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:24:42 by esalim            #+#    #+#             */
/*   Updated: 2023/08/23 15:23:01 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getline(char *str)
{
	char	*newline;

	newline = gnl_strchr(str, '\n');
	if (!str[0])
		return (NULL);
	if (!newline)
		return (gnl_strdup(str));
	return (ft_substr(str, 0, newline - str + 1));
}

char	*ft_getbuffer(char *line)
{
	char	*buff;
	char	*newline;

	newline = gnl_strchr(line, '\n');
	if (!newline)
		return (free(line), NULL);
	if (*(++newline))
	{
		buff = gnl_strdup(newline);
		free(line);
		return (buff);
	}
	return (free(line), gnl_strdup(""));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	char		buff[2];
	int			n;

	n = 1;
	if (fd < 0)
		return (0);
	while (n > 0)
	{
		n = read(fd, buff, 1);
		if (n == -1)
			n = 0;
		buff[n] = '\0';
		str = gnl_strjoin(str, buff);
		if (gnl_strchr(buff, '\n'))
			break ;
	}
	line = ft_getline(str);
	str = ft_getbuffer(str);
	return (line);
}
