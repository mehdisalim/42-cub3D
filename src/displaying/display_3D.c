#include "../../includes/cub3.h"


void *getDataFromElements(t_elements *elements, char *data)
{
    int i = -1;
    while (elements[++i].name)
        if (!ft_strncmp(elements[i].name, data, ft_strlen(data)))
            return (elements[i].value.color);
    return (NULL);
}

void draw_3D(t_image *image, float ray, int i, int pixelXPos, const t_texture* const texture)
{
    float start;
    float pj;
    float offsetY;
    float yPos;
    int y;

    pj = (HEIGHT * TILESIZE) / (ray * cos((image->ray_angle - image->angle) * (M_PI / 180))) * 1.5;
    start = (HEIGHT / 2) - (pj / 2);
    if (start < 0)
        start = 0;
    y = 0;
    while (y < start)
        mlx_put_pixel(image->img, i, y++, image->mapInfo.ceilingColor);
    y = pj + start;
    while (y < HEIGHT)
        mlx_put_pixel(image->img, i, y++, image->mapInfo.floorColor);
    y = 0;
    offsetY = texture->height / pj;
    yPos = offsetY * (pj / 2 - HEIGHT / 2);
    if (yPos < 0)
        yPos = 0;
    while (y < pj && y < HEIGHT)
    {
        mlx_put_pixel(image->img, i, y + start, getColor(texture->pixels[(int)yPos][pixelXPos]));
        yPos += offsetY;
        if (yPos >= texture->height)
            yPos = 0;
        y++;
    }
}