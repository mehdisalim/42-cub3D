/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:51:30 by esalim            #+#    #+#             */
/*   Updated: 2023/08/27 13:22:20 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	char	**map_elements;
	char	**map;

	if (ac < 2)
	{
		ft_putstr_fd("bad args\n", 2);
		return (1);
	}
	if (!check_map(av[1], &map_elements, &map))
	{
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
	int	i = -1;
	while (elements[++i].name)
	{
		if (elements[i].name[0] != 'C' && elements[i].name[0] != 'F')
			printf("name ==> |%s| - value ==> |%s|\n", elements[i].name, elements[i].value.path);
		else
			printf("name ==> |%s| - red ( %d )  -  green ( %d )  -  blue ( %d )\n", elements[i].name, elements[i].value.color->red, elements[i].value.color->green, elements[i].value.color->blue);
	}
	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
	return (0);    
}