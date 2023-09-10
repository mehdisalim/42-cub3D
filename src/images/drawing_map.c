#include "../../includes/cub3.h"

void    drawAllMaps(t_image *image)
{
    int j;
    int i;
    
    i = -1;
	while (image->map[++i])
	{
		j = 0;
		while (image->map[i][j])
		{
			if (image->map[i][j] == '1')
				draw_pixel(0xFF0000FF, image, (j * SIZE), (i * SIZE));
			else if (!ft_strchr("1 ", image->map[i][j]))
				draw_pixel(0x696ca5, image, j * SIZE, i * SIZE);
			if (ft_strchr("ESNW", image->map[i][j]) && image->hasEntered == 0)
			{
				image->xposition_p = (j * SIZE) + (SIZE / 2);
				image->yposition_p = (i * SIZE) + (SIZE / 2);
				image->hasEntered = 1;
			}
			j++;
		}
	}
}