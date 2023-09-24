/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:02:23 by esalim            #+#    #+#             */
/*   Updated: 2023/09/18 15:12:54 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	// static	int i;

	dest = (char *)malloc(count * size);
	if (!dest)
	{
		ft_putendl_fd("Error : Malloc Faild !!", 2);
		exit(1);
	}
	// printf("%d   ==> [%p]\n", i++, dest);
	ft_bzero(dest, count * size);
	return (dest);
}
