/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:32:33 by esalim            #+#    #+#             */
/*   Updated: 2023/08/23 15:22:18 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *lstr, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!lstr)
		return (gnl_strdup(buff));
	if (!lstr || !buff)
		return (NULL);
	str = malloc(ft_strlen(lstr) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (lstr[++i])
		str[i] = lstr[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = 0;
	free(lstr);
	return (str);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	slen;
	int		i;

	i = -1;
	if (!s || !*s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	d = (char *)malloc(len + 1);
	if (!d)
		return (0);
	if (start < ft_strlen(s))
	{
		while (s[++i] && len--)
			d[i] = s[i];
		d[i] = 0;
	}
	return (d);
}

char	*gnl_strdup(char *s1)
{
	char	*dest;
	size_t	len;
	int		i;

	i = -1;
	len = ft_strlen((char *)s1) + 1;
	dest = (char *)malloc(len);
	if (!dest)
		return (0);
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = 0;
	return (dest);
}
