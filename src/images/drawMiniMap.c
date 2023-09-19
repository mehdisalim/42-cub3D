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
			mlx_put_pixel(image->img, (x + xx), (y + yy), color);
			y++;
		}
		x++;
	}
}

void	drawMiniMap(t_image *img)
{
	int i;
	int j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == '1')
				draw_pixel(0xFF0000FF, img, (j * MINIMAPSIZE), (i * MINIMAPSIZE));
			else if (!ft_strchr("1 ", img->map[i][j]))
				draw_pixel(0x696ca5, img, j * MINIMAPSIZE, i * MINIMAPSIZE);
			j++;
		}
		i++;
	}

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
                mlx_put_pixel(img->img,  img->xMap + x, img->yMap + y , 0xffffff);
            y++;
        }
        x++;
    }
}