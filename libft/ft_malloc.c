#include "libft.h"

void	*ft_malloc(size_t count, size_t size, char freeing)
{

	char	*dest;
	static	t_list	*head;

	dest = (char *)ft_calloc(count, size);
	if (!dest)
		return (0);
	ft_lstadd_back(&head, ft_lstnew(dest));
	if (freeing)
		ft_lstclear(&head, free);
	return (dest);
}