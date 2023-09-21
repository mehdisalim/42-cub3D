/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:13:42 by esalim            #+#    #+#             */
/*   Updated: 2023/09/21 13:20:28 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "structs.h"
#include "utils.h"

size_t	    get_map_size(char *map_name);
void	    free_double_pointer(char **str);
char	    **get_map_content(char *map_name, char *checker);
char	    check_elements(char **map_content);
int		    get_newline_pos(char *str);
void	    remove_newlines(char **map_content);
void	    separate_map(char **map_content, char ***elements_part, char ***map_part);
int		    map_size(char **map);
char	    **get_new_map(char **old_map);
char	    check_wall(char **map);
char	    check_invalid_char(char	**map);
char	    check_player(char **map);
char	    check_space(char	**map);
char	    **trim_elements(char **elements);
void        print_map(char **map_content);
char	    check_map(char *map_name, char ***elements, char ***map, char *checker);
t_elements	*parsing_elements(char **elements);
t_color		*parsing_colors(char	*str_color);

#endif