#include "../../includes/cub3.h"

t_color**	getImage(const char *str)
{
	mlx_texture_t	*textureImage;
	unsigned char	***_3DArray;
	unsigned char	**_2DArray;
	t_color			**pixels;
	int				i;

	textureImage = mlx_load_png(str);
	if (!textureImage)
		return (NULL);
	_2DArray = convertTextureTo2DArray(textureImage->pixels, textureImage->height, textureImage->width * 4);
	_3DArray = convert2DArrayTo3DArray(textureImage, _2DArray);
	free_double_pointer((void *)_2DArray);
	pixels = convert3DArrayToPixelsColor(textureImage, _3DArray);
	i = -1;
	while (_3DArray[++i])
		free_double_pointer((void *)_3DArray[i]);
	free(_3DArray);
	free(textureImage->pixels);
	free(textureImage);
	return (pixels);
}

void *getDataFromElements(t_elements *elements, char *data)
{
	int i = -1;
	while (elements[++i].name)
		if (!ft_strncmp(elements[i].name, data, ft_strlen(data)))
			return (elements[i].value.color);
	return (NULL);
}

void	draw_3D(t_image *image, float ray, unsigned long color, int i, char check)
{
	// int i;
	float	start;
	float	pj;
	int		y;
	t_color *floorOrCeilingColor;
	unsigned long floorOrCeiling;
	


	(void)color;
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
	y = 0;

	// =================================== FLOOR AND CEILING COLOR ===================================
	/**/	floorOrCeilingColor = getDataFromElements(image->elements, "C");
	/**/	floorOrCeiling =  getColor(*floorOrCeilingColor);
	/**/	while (y < start)
	/**/		mlx_put_pixel(image->img, i, y++, floorOrCeiling);
	// =================================== FLOOR AND CEILING COLOR ===================================
	float x = 0;
	if (check == 1)
	{
		x = 1;
	}
	y = start;
	pj += start;
	while (y < pj)
	{
		mlx_put_pixel(image->img, i, y, color);
		y++;
	}

	// ===================================== FLOOR AND CEILING COLOR ===================================
	/**/	floorOrCeilingColor = getDataFromElements(image->elements, "F");
	/**/	floorOrCeiling =  getColor(*floorOrCeilingColor);
	/**/	while (y < HEIGHT)
	/**/		mlx_put_pixel(image->img, i, y++, floorOrCeiling);
	// ===================================== FLOOR AND CEILING COLOR ===================================
}

