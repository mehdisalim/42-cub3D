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

// void	draw_3D(t_image *image, float ray, unsigned long color, int i, int __unused pixelXPos)
// {
// 	// int i;
// 	float	start;
// 	float	pj;
// 	float	pj2;
// 	int		y;
// 	t_color *floorOrCeilingColor;
// 	unsigned long floorOrCeiling;
// 	static int	as;


// 	(void)color;
// 	/**
// 	 * @brief Equation is :		PJ	=	(Screen * SQUARE) / rays	==> TO FIND PROJECTION USING RAYS DISTANCE
// 	 * 							Start =	(Screen / 2) - (PJ / 2)		==> TO FIND START POINT
// 	 */
// 	pj = (HEIGHT * 20) / (ray * cos((image->ray_angle - image->angle) * (M_PI / 180)));
// 	if (pj > HEIGHT)
// 		pj = HEIGHT;
// 	pj2 = pj;
// 	start = (HEIGHT / 2) - (pj / 2);
// 	if (start < 0)
// 		start = 0;
// 	y = 0;

// 	// =================================== CEILING COLOR ===================================
// 	/**/	floorOrCeilingColor = getDataFromElements(image->elements, "C");
// 	/**/	floorOrCeiling =  getColor(*floorOrCeilingColor);
// 	/**/	while (y < start)
// 	/**/		mlx_put_pixel(image->img, i, y++, floorOrCeiling);
// 	// =================================== CEILING COLOR ===================================
// 	// float x = 0;
// 	y = start;
// 	pj += start;
// 	while (y < pj)
// 	{
// 		int offsetY = (y - start) * (20 / pj2);
// 		mlx_put_pixel(image->img, i, y, /*0x616161*/getColor(image->pixels[offsetY][pixelXPos]));
// 		y++;
// 	}
// 	// if (as == 3)
// 	// 	exit(0);

// 	// as++;
// 	// ===================================== FLOOR COLOR ===================================
// 	/**/	floorOrCeilingColor = getDataFromElements(image->elements, "F");
// 	/**/	floorOrCeiling =  getColor(*floorOrCeilingColor);
// 	/**/	while (y < HEIGHT)
// 	/**/		mlx_put_pixel(image->img, i, y++, floorOrCeiling);
// 	// ===================================== FLOOR COLOR ===================================
// }

void draw_3D(t_image *image, float ray, unsigned long color, int i, int pixelXPos)
{
    float start;
    float pj;
    float pj2;
    int y;
    t_color *floorOrCeilingColor;
    unsigned long floorOrCeiling;

    (void)color;

    pj = (HEIGHT * 20) / (ray * cos((image->ray_angle - image->angle) * (M_PI / 180)));
    if (pj > HEIGHT)
        pj = HEIGHT;
    pj2 = pj;
    start = (HEIGHT / 2) - (pj / 2);
    if (start < 0)
        start = 0;
    y = 0;


    /**
     * 		     0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|
     * 		     |                  |                   |
     * 		     |                  |       IMAGE       | <------ Wall
     * 		     |                  |       ---------------------- Intersections
     * 		     |                  |       V   .   D   |
     *          {|------------------xxxxxxxxxxxxxX[-----]|}  <----- 200px
     *                             /////////////   ^------------------> Distance between the rest of the wall and the last intersection                                
     *                  Rays ---> ////////////                          170px
     *                           ///////////
     *                          /////////               Intersection Dustance = 70px
     *                         ////////                 Image Pixel Position  = 70 / 10 = 7;
     *                        ///////
     *                       //////
     *                      /////
     *                     ////
     *                    ///
     *                   //
     *                  /   
     *  Player  ---->  *
     * 
     *  
     * 
     */

    // Ceiling Color
    floorOrCeilingColor = getDataFromElements(image->elements, "C");
    floorOrCeiling = getColor(*floorOrCeilingColor);
    while (y < start)
        mlx_put_pixel(image->img, i, y++, floorOrCeiling);
    // int imageX = (int)(((float)pixelXPos) * (20 / 20));
    int offsetY = (y - start) * (20 / pj2);
    y = start;
    pj += start;
    while (y < pj)
    {
        // if (offsetY < 0)
        //     offsetY = 0;
        // else
            // offsetY *= size;
        // Map image pixel onto the wall
        // printf("offsetY ==> %d | imageX ==> %d\n", offsetY, imageX);
        mlx_put_pixel(image->img, i, y, getColor(image->pixels[offsetY][pixelXPos]));
        y++;
    }
    // static int ice;
    // if (ice == 1000)
    //     exit(0);
    // ice++;
    // Floor Color
    floorOrCeilingColor = getDataFromElements(image->elements, "F");
    floorOrCeiling = getColor(*floorOrCeilingColor);
    while (y < HEIGHT)
        mlx_put_pixel(image->img, i, y++, floorOrCeiling);
}