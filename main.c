#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    while (i++ < 50)
        system("./cub3D maps/map1.cub | grep 'ddsfa'");
    return 0;
}
