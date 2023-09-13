#include "../../includes/cub3.h"

void    getImage(t_image *image)
{
    mlx_texture_t *textureImage;
	t_color **imageColors;

    (void)image;
    textureImage = mlx_load_png("assets/test2.png");
	imageColors = ft_calloc(textureImage->height + 1, sizeof(*imageColors));
	if (!imageColors)
		return ;
    int i = 0;
	int end = textureImage->width * textureImage->height * 4;
    while (i < end && textureImage->pixels[i])
    {
        int j = i + 4;
        while (i < j)
		{
			if (i % textureImage->width == 0)
				printf("\n");
            printf("{%i = %d} ", i, textureImage->pixels[i]);
			i++;
		}
		if (i != j)
			i++;
    }
    
    // xpm_t *xpm = mlx_load_xpm42("assets/sa.xpm");
    // printf("textureImage->bytes_per_pixel ==> [%d]\n", textureImage->bytes_per_pixel);
    // printf("textureImage->heigh ==> [%d]\n", textureImage->height);
    // printf("textureImage->width ==> [%d]\n", textureImage->width);
}

void	draw_3D(t_image *image, float ray, unsigned int color, int i)
{
	// int i;
	float	start;
	float pj;
	int y;
	


	/**
	 * @brief Equation is :		PJ	=	(Screen * SQUARE) / rays	==> TO FIND PROJECTION USING RAYS DISTANCE
	 * 							Start =	(Screen / 2) - (PJ / 2)		==> TO FIND START POINT
	 */
	pj = (HEIGHT * SIZE) / (ray * cos((image->ray_angle - image->angle) * (M_PI / 180)));
	if (pj > HEIGHT)
		pj = HEIGHT;
	start = (HEIGHT / 2) - (pj / 2);
	if (start < 0)
		start = 0;
	y = start;
	pj += start;
	while (y < pj)
		mlx_put_pixel(image->img, i, y++, color);
}

