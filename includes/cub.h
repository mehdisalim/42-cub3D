#ifndef CUB_H
#define CUB_H

# define    SUCCESS 1
# define    FAILED 0

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_elements
{
    char    *name;
    char    *value;
}   t_elements;

size_t	get_map_size(char *map_name);
void	free_double_pointer(char **str);
char	**get_map_content(char *map_name);
char	check_elements(char **map_content);
int		get_newline_pos(char *str);
void	remove_newlines(char **map_content);
void	print_map(char **map_content);
void	separate_map(char **map_content, char ***elements_part, char ***map_part);
int		map_size(char **map);
char	**get_new_map(char **old_map);
char	check_wall(char **map);
void	checking(char i);
char	check_invalid_char(char	**map);
char	check_player(char **map);
char	check_space(char	**map);
char	**trim_elements(char **elements);
char	check_map(char *map_name, char ***elements, char ***map);

t_elements	*parsing_elements(char **elements);

#endif