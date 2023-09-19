#include "../../includes/cub3.h"

void    drawPlayer(t_image *image, double xPlayer, double yPlayer)
{
	int x = -4;
    int y;
    int err;

	while (x <= 4)
    {
        y = -4;
        while (y <= 4)
        {
            err = x * x + y * y - 4 * 4;
            if (err <= 0)
                mlx_put_pixel(image->img, xPlayer + x, yPlayer + y , 0xffffff);
            y++;
        }
        x++;
    }
}

void    drawDynamicMap(t_image *image)
{
    // int width = 200;
    // int height = 200;

    float yStartMap = image->yMap - 100;
    float yEndMap = image->yMap + 100;
    if (yStartMap < 0)
    {
        yEndMap += -yStartMap;
        yStartMap = 0;
    }
    if (yEndMap >= HEIGHT)
    {
        yStartMap -= yEndMap - HEIGHT;
        yStartMap = HEIGHT;
    }

    float xPlayerMap = image->xMap;
    float yPlayerMap = image->yMap;
    float ystart = yStartMap;
    while (yStartMap < yEndMap)
    {
        float xStartMap = image->xMap - 100;
        float xEndMap = image->xMap + 100;
        if (xStartMap < 0)
        {
            xEndMap += -xStartMap;
            xStartMap = 0;
        }
        if (xEndMap > WIDTH)
        {
            xStartMap -= xEndMap - WIDTH;
            xStartMap = WIDTH;
        }
        float xstart = xStartMap;
        while (xStartMap < xEndMap)
        {
            unsigned int i = (yStartMap - (MINIMAPSIZE / 2)) / MINIMAPSIZE;
            unsigned int j = (xStartMap - (MINIMAPSIZE / 2)) / MINIMAPSIZE;
            if (i < (unsigned int)image->verticalLength && j < (unsigned int)ft_strlen(image->map[i]))
            {
                if (image->map[i][j] == '1')
                    draw_pixel(0xFF0000FF, image, xStartMap - xstart, yStartMap - ystart);
                else if (!ft_strchr("1 ", image->map[i][j]))
                    draw_pixel(0x696ca5, image, xStartMap - xstart, yStartMap - ystart);
                else if (ft_strchr("ESNW", image->map[i][j]))
                {
                    yPlayerMap = yStartMap - ystart;
                    xPlayerMap = xStartMap - xstart;
                }
            }
            xStartMap++;
        }
        yStartMap++;
    }
    drawPlayer(image, xPlayerMap, yPlayerMap);
}