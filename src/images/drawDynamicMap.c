#include "../../includes/cub3.h"

void	draw_pixel(unsigned int color, t_image *image, int xx, int yy)
{
	int	x;
	int	y;

	x = 0;
	while (x <= MINIMAPSIZE)
	{
		y = 0;
		while (y <= MINIMAPSIZE)
		{
			mlx_put_pixel(image->mapScreen, (x + xx), (y + yy), color);
			y++;
		}
		x++;
	}
}

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
    float destX = xPlayer + (15 * cos(image->angle * (M_PI / 180)));
    float destY = yPlayer + (15 * sin(image->angle * (M_PI / 180)));
    DDA(xPlayer, yPlayer, destX,destY , image);
}

void	drawDynamicMap(t_image *image)
{
    float yStartMap = image->yMap - 100;
    float yEndMap = image->yMap + 100;
    float xEndMap = image->xMap + 100;
    float xstart = image->xMap - 100;
    float ystart = yStartMap;
    unsigned long south_color;
    unsigned long north_color;
    if (image->mapInfo.south->height / 2 - 1 < 0 || image->mapInfo.north->height / 2 - 1 < 0)
    {
        south_color = 0xff0ff0;
        north_color = 0xAAABBB;
    }
    else
    {
        south_color = get_color(image->mapInfo.south->pixels[image->mapInfo.south->height / 2 - 1][image->mapInfo.south->width / 2 - 1]);
        north_color = get_color(image->mapInfo.north->pixels[image->mapInfo.north->height / 2 - 1][image->mapInfo.north->width / 2 - 1]);
        if (north_color == south_color)
            north_color /= 2;
    }
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
                    draw_pixel(south_color, image, xTmp, yTmp);
                else if (!ft_strchr("1 ", image->map[i][j]))
                    draw_pixel(north_color, image, xTmp, yTmp);
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

    int circleRay = 90;
    int border = 110 - circleRay;
    int x = -circleRay;
    int y;
    int err;
    int t = 0;


	while (x < circleRay)
    {
        y = -circleRay;
        while (y < circleRay)
        {
            err = x * x + y * y - circleRay * circleRay;
            if (err > 0)
                mlx_put_pixel(image->mapScreen, circleRay + x + border, circleRay + y + border , 0);
            y++;
        }
        if (t < 210)
        {
            draw_pixel(0, image, 0, t);
            draw_pixel(0, image, t, 0);
            draw_pixel(0, image, 200, t);
            draw_pixel(0, image, t, 200);
            t += 20;
        }
        x++;
    }

}