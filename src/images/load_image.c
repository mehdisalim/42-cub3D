#include "../../includes/cub3.h"

unsigned char	**convertTextureTo2DArray(unsigned char *srcArray, int height, int width)
{
	if (!srcArray)
		return (NULL);
	
	unsigned char **_2DArray = ft_calloc(height + 1, sizeof(unsigned char *));
	int i;
	int j = 0;
	int x = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		_2DArray[i] = ft_calloc(width + 1, sizeof(unsigned char));
		while (j < width)
			_2DArray[i][j++] = srcArray[x++];
		i++;
	}
	return (_2DArray);
}

unsigned char	***convert2DArrayTo3DArray(mlx_texture_t *texture, unsigned char **_2DArray)
{
	if (!_2DArray)
		return (NULL);
	unsigned char ***_3DArray = ft_calloc(texture->height + 1, sizeof(unsigned char **));
	int p = 0;
	int i = -1;
	int j = 0;
	int a = 0;
	while (++i <  (int)texture->height)
	{
		j = 0;
		a = 0;
		_3DArray[i] = ft_calloc(texture->width + 1, sizeof(unsigned char *));
		while (j < (int)texture->width * 4)
		{
			_3DArray[i][a] = ft_calloc(5, sizeof(unsigned char));
			ft_memcpy(_3DArray[i][a++], _2DArray[i] + j, sizeof(unsigned char) * 4);
			j += 4;
		}
		p++;
	}
	return (_3DArray);
}

t_color	**convert3DArrayToPixelsColor(mlx_texture_t *texture, unsigned char ***_3DArray)
{
	t_color **pixelsColors;
	int     i;
	int     j;
    int     a;

	if (!_3DArray)
		return (NULL);
	pixelsColors = ft_calloc(texture->height + 1, sizeof(t_color *));
	i = -1;
	while (++i <  (int)texture->height)
	{
		j = 0;
		a = 0;
		pixelsColors[i] = ft_calloc(texture->width + 1, sizeof(t_color));
		while (j < (int)texture->width * 4)
		{
			pixelsColors[i][a].red = _3DArray[i][a][0];
			pixelsColors[i][a].green = _3DArray[i][a][1];
			pixelsColors[i][a].blue = _3DArray[i][a][2];
			pixelsColors[i][a].alpha = _3DArray[i][a][3];
			pixelsColors[i][a].size = texture->width;
			a++;
			j += 4;
		}
	}
	return (pixelsColors);
}

void	printPixelsColor(t_color **pixelsColor)
{
	int i = 0;
	int j = 0;
	int size = 0;
	if (!pixelsColor)
		return ;

	if (*pixelsColor)
		size = pixelsColor[i][0].size;
	while (pixelsColor[i])
	{
		j = 0;
		printf("\n=========================================={%d}====================================================\n", i);
		while (j < size)
		{
			printf("pixels Color red ==> {%d}\t", pixelsColor[i][j].red);
			printf("pixels Color green ==> {%d}\t", pixelsColor[i][j].green);
			printf("pixels Color blue ==> {%d}\t", pixelsColor[i][j].blue);
			printf("pixels Color alpha ==> {%d}\n", pixelsColor[i][j].alpha);
			j++;
		}
		printf("\n=========================================={%d}====================================================\n", i);
		i++;
	}
}

unsigned long	getColor(t_color color)
{
	return ((color.red & 0xff) << 24) + ((color.green & 0xff) << 16) + ((color.blue & 0xff) << 8) + (color.alpha & 0xff);
}
