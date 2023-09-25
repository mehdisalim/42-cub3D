/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:18 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 22:27:18 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

//====== Handling Images functions ======//
unsigned char	**convert_texture_to_2d_array(unsigned char *srcArray, \
												int height, int width);
unsigned char	***convert_2d_array_to_3d_array(mlx_texture_t *texture, \
												unsigned char **_2DArray);
t_color			**convert_3d_array_to_pixels_color(mlx_texture_t *texture, \
												unsigned char ***_3DArray);

void			print_pixels_color(t_color **pixelsColor);
unsigned long	get_color(t_color color);
t_texture		*get_texture(const char *str);

//====== De-allocating functions ======//

void			free_elements(t_elements *elements);
void			free_double_pointer(char **str);
void			free_texture(t_texture *texture);
void			destroy_program(t_image *image);

char			is_number(char *str);

#endif
