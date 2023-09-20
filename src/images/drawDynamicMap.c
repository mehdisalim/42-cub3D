#include "../../includes/cub3.h"

void    drawPlayer(t_image *image, double xPlayer, double yPlayer)
{
    int circleRay = 4;
	int x = -circleRay;
    int y;
    int err;

	while (x <= circleRay)
    {
        y = -circleRay;
        while (y <= circleRay)
        {
            err = x * x + y * y - circleRay * circleRay;
            if (err <= 0)
                mlx_put_pixel(image->mapScreen, xPlayer + x, yPlayer + y , 0xffffff);
            y++;
        }
        x++;
    }
    // DDA();
    float destX = xPlayer + (10 * cos(image->angle * (M_PI / 180)));
    float destY = yPlayer + (10 * sin(image->angle * (M_PI / 180)));
    DDA(xPlayer, yPlayer, destX,destY , image);
}

void	drawDynamicMap(t_image *image)
{
    float yStartMap = image->yMap - 100;
    float yEndMap = image->yMap + 100;
    float xEndMap = image->xMap + 100;
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

    int circleRay = 100;
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
            else if (err > -200 && err <= 0)
                mlx_put_pixel(image->mapScreen, circleRay + x, circleRay + y , 0xffffff);
                
            y++;
        }
        x++;
    }
    int t = 0;
    while (t < 210)
    {
        draw_pixel(0, image, t, 200);
        draw_pixel(0, image, 200, t);
        t += 20;
    }

}