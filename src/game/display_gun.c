/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:08:24 by esalim            #+#    #+#             */
/*   Updated: 2023/09/24 17:21:32 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"



// void    draw_gun(t_image *image, t_texture *guns_tex)
// {
//     int x = 0;
//     int y = 0;
//     printf("{%d %d}\t", HEIGHT / guns_tex->height, WIDTH / guns_tex->width);
//     while (y < WIDTH)
//     {
//         x = 0;
//         while (x < HEIGHT)
//         {
//             mlx_put_pixel(image->gunScreen, x, y, get_color(guns_tex->pixels[y / guns_tex->height][x / guns_tex->width]));
//             x++;
//         }
//         y++;
//     }
// }

// void draw_gun(t_image *image, t_texture *guns_tex)
// {
//     // Calculate the scaling factors for width and height
//     double scale_x = ((double)image->gunScreen->width / 2) / guns_tex->width;
//     double scale_y = ((double)image->gunScreen->height / 2) / guns_tex->height;

//     int x, y;
//     for (y = 0; y < (int)image->gunScreen->height / 2; y++)
//     {
//         for (x = 0; x < (int)image->gunScreen->width / 2; x++)
//         {
//             int tex_x = (int)(x / scale_x); // Calculate the corresponding x-coordinate in the texture
//             int tex_y = (int)(y / scale_y); // Calculate the corresponding y-coordinate in the texture

//             mlx_put_pixel(image->gunScreen, x + (image->gunScreen->width / 2), y + (image->gunScreen->height / 2), get_color(guns_tex->pixels[tex_y][tex_x]));
//         }
//     }
// }

// void    display_gun(t_image *image, t_list* lst)
// {
//     // int y = 0;
//     // int x = 0;
//     while (lst)
//     {
//         printf("hello from display_gun\n");
//         draw_gun(image, (t_texture *)lst->content);
//         usleep(5000);
//         lst = lst->next;
//     }
// }