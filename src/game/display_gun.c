/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:08:24 by esalim            #+#    #+#             */
/*   Updated: 2023/09/23 16:01:46 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3.h"


void    draw_gun(t_image *image, t_texture *guns_tex)
{
    int x = 0;
    int y = 0;
    while (y < 280)
    {
        x = 0;
        while (x < 500)
        {
            mlx_put_pixel(image->gunScreen, x, y, get_color(guns_tex->pixels[guns_tex->height % y][guns_tex->width % x]));
            x++;
        }
        y++;
    }
}
void    display_gun(t_image *image, t_list* lst)
{
    // int y = 0;
    // int x = 0;
    while (lst)
    {
        printf("hello from display_gun\n");
        draw_gun(image, (t_texture *)lst->content);
        usleep(1000);
        lst = lst->next;
    }
}