typedef struct s_data 
{
    char *tex[4];
    int floor_color;
    int ceiling_color;
    char *map[];
} t_data;

#include <stdio.h>
int main(void) {
    t_data data;

    data.floor_color = 0xDC6400;
    printf("Floor color: 0x%06X\n", data.floor_color);
    printf("Floor color: %d\n", data.floor_color);
}