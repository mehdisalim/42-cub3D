/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:09:58 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 20:50:09 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t count, size_t size, char freeing)
{
	char			*dest;
	static t_list	*head;

	dest = (char *)ft_calloc(count, size);
	if (!dest)
		return (0);
	ft_lstadd_back(&head, ft_lstnew(dest));
	if (freeing)
		ft_lstclear(&head, free);
	return (dest);
}
