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
