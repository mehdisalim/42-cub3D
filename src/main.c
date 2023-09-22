/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:22:00 by esalim            #+#    #+#             */
/*   Updated: 2023/09/21 22:45:01 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3.h"

/**
 * @brief Secound Main function for testing leaks memory allocation, checking and parsing map also in this function
 * 
 * @param ac number of args
 * @param av args value
 * @return int 
 */

int main2(int ac, char **av)
{
	char **map_elements;
	char **map;
	t_elements *elements;
	char checker = 0;

	if (ac < 2)
		return (ft_putstr_fd("bad args\n", 2), 1);
	if (ft_strlen(av[1]) < 4 || ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4))
		return (ft_putstr_fd("File Name Error\n", 2), 0);
	if (!check_map(av[1], &map_elements, &map, &checker))
	{
		if (checker)
			return (ft_putstr_fd("File not found !!\n", 2), 1);
		free_double_pointer(map_elements);
		free_double_pointer(map);
		return (1);
	}
	elements = parsing_elements(map_elements);
	free_double_pointer(map_elements);
	if (!elements)
		return (free_double_pointer(map), 1);
	create_window(elements, map);
	return (0);
}

/**
 * @brief Main Function
 * 
 * @param argc number of args
 * @param argv args values
 * @return int (exit status)
 */
int main(int argc, char **argv)
{
	main2(argc, argv);
	// system("leaks -q cub3D");
	return 0;
}
