#include "../../includes/cub3.h"


void	free_elements(t_elements *elements)
{
	int	i;

	if (!elements)
		return ;
	i = 0;
	while (elements[i].name)
	{
		if (elements[i].name[0] != 'C' && elements[i].name[0] != 'F')
			free(elements[i].value.path);
		else
			free(elements[i].value.color);
		free(elements[i].name);
		i++;
	}
	free(elements);
}


void	free_double_pointer(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}


void	freeTexture(t_texture *texture)
{
	free_double_pointer((char **)texture->pixels);
	free(texture);
}

void	destroyProgram(t_image *image)
{	
    freeTexture(image->mapInfo.north);
    freeTexture(image->mapInfo.west);
    freeTexture(image->mapInfo.south);
    freeTexture(image->mapInfo.east);
	free_elements(image->elements);	
	free_double_pointer(image->map);
	free(image);
}