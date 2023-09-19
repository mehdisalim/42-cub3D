/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:51:30 by esalim            #+#    #+#             */
/*   Updated: 2023/09/18 22:03:19 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// void	getNewMap()
// {
// 	int		i = 0;
// 	int		j = 0;

// 	int		counter = -1;

// 	while (++counter < 9)
// 		ft_memset(newMap[counter], ' ', 9);
// 	int		x = 0;
// 	int		y = 0;
// 	int		iEnd = i + 4;
// 	int		jEnd = j + 4;
// 	y = i - 5;
// 	if (y < -1)
// 		y = -1;
// 	j -= 4;
// 	if (j < 0)
// 		j = 0;
// 	if (iEnd > verticalLength)
// 		iEnd = verticalLength - 1;
// 	while (++y < iEnd)
// 	{
// 		int a = 0;
// 		int jLen = ft_strlen(map[y]) - 1;
// 		if (jEnd > jLen)
// 			jEnd = jLen;
// 		jLen = j;
// 		while (j < jEnd)
// 			newMap[x][a++] = map[y][j++];
// 		j = jLen;
// 		x++;
// 	}
// }

// int	main(int ac, char **av)
// {
	


// 	return (0);    
// }


#include <stdio.h>

int main() {
    // Define the old map
    char oldMap[13][23] = {
        "1111111111111111111111",
        "1000000000000000000101",
        "1000000000000000000001",
        "1000000000000000000001",
        "1000000000000000000001",
        "10000000000000000N0001",
        "1000000000000000000001",
        "1000000000000000000001",
        "1000000000000000000001",
        "1000000000000000000001",
        "1000000000000000000001",
        "1000000000000000000001",
        "1111111111111111111111"
    };

    // Create a new map and place the player in the middle
    char newMap[10][10];
    int playerX, playerY;
    int centerX = 11 / 2; // Middle column index
    int centerY = 13 / 2; // Middle row index

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            newMap[i][j] = oldMap[centerY - 5 + i][centerX - 5 + j];
            if (newMap[i][j] == 'N') {
                playerX = j;
                playerY = i;
            }
        }
    }

    // Print the new map with the player in the middle
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", newMap[i][j]);
        }
        printf("\n");
    }

    printf("Player is at position (%d, %d)\n", playerX, playerY);

    return 0;
}