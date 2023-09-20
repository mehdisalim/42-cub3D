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
                mlx_put_pixel(image->mapScreen, xPlayer + x, yPlayer + y , 0xffffff);
            y++;
        }
        x++;
    }
}

void	drawDynamicMap(t_image *image)
{
    // int width = 200;
    // int height = 200;

    float yStartMap = image->yMap - 100;
    float yEndMap = image->yMap + 100;
    float xEndMap = image->xMap + 100;
    // float xPlayerMap = image->xMap;
    // float yPlayerMap = image->yMap;
    float xstart = image->xMap - 100;
    float ystart = yStartMap;
    while (yStartMap < yEndMap)
    {
        unsigned int i = (yStartMap - (MINIMAPSIZE / 2)) / MINIMAPSIZE;
        float xStartMap = xstart;
        while (xStartMap < xEndMap)
        {
            float xTmp = xStartMap - xstart;
            float yTmp = yStartMap - ystart;
            unsigned int j = (xStartMap - (MINIMAPSIZE / 2)) / MINIMAPSIZE;
            if (i < (unsigned int)image->verticalLength && j < (unsigned int)ft_strlen(image->map[i]))
            {
                if (image->map[i][j] == '1')
                    draw_pixel(0xFF0000FF, image, xTmp, yTmp);
                else if (!ft_strchr("1 ", image->map[i][j]))
                    draw_pixel(0x696ca5, image, xTmp, yTmp);
                else
                    draw_pixel(0, image, xTmp, yTmp);
            }
            else
                draw_pixel(0, image, xTmp, yTmp);
            xStartMap++;
        }
        yStartMap++;
    }
    drawPlayer(image, 110, 110);

    // mlx_put_string(image->mlx, "N", 110, 0);
    // mlx_put_string(image->mlx, "S", 0, 110);
    // mlx_put_string(image->mlx, "E", 220, 110);
    // mlx_put_string(image->mlx, "W", 110, 220);

    int circleRay = 110;
    int x = -circleRay;
    int y;
    int err;


	while (x < circleRay)
    {
        y = -circleRay;
        while (y < circleRay)
        {
            err = x * x + y * y - circleRay * circleRay;
            if (err > 0)
                mlx_put_pixel(image->mapScreen, circleRay + x, circleRay + y , 0);
            y++;
        }
        x++;
    }
}