/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:07:08 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 20:47:47 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		length;

	if (!src || !dst)
		return (0);
	i = 0;
	length = ft_strlen(src);
	if (n == 0)
		return (length);
	while (src[i] && --n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (length);
}
