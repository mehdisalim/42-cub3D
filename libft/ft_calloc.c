/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:02:23 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 20:51:40 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;

	dest = (char *)malloc(count * size);
	if (!dest)
	{
		ft_putendl_fd("Error : Malloc Faild !!", 2);
		exit(1);
	}
	ft_bzero(dest, count * size);
	return (dest);
}
