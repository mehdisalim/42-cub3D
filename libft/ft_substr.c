/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:19:21 by esalim            #+#    #+#             */
/*   Updated: 2023/08/27 11:54:06 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	d = (char *)ft_calloc(len + 1, sizeof(char));
	if (!d || start > ft_strlen(s))
		return (0);
	ft_strlcpy(d, &s[start], len + 1);
	return (d);
}
