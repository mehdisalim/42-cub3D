#include "libft.h"
#include <stdio.h>

void    ft_free(void    *ptr)
{
    // static int a;
    // printf("%d ==> |%s|   |%p|\n", a, ptr, ptr);
    // a++;
    free(ptr);
}