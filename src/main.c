/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:51:30 by esalim            #+#    #+#             */
/*   Updated: 2023/09/09 08:59:43 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	char	**map_elements;
	char	**map;
	char	checker = 0;

	if (ac < 2)
	{
		ft_putstr_fd("bad args\n", 2);
		return (1);
	}
	if (!check_map(av[1], &map_elements, &map, &checker))
	{
		if (checker)
			return (printf("File not found !!\n"), 1);
		free_double_pointer(map_elements);
		free_double_pointer(map);
		return (1);
	}
	t_elements *elements = parsing_elements(map_elements);
	free_double_pointer(map_elements);
	if (!elements)
	{
		free_double_pointer(map);
		return (1);
	}
	return (0);    
}