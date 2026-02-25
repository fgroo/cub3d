typedef struct s_data {
    t_mapdata map;
} t_data;
}

typedef struct s_mapdata 
{
    char *tex[4];
    int floor_color;
    int ceiling_color;
    char *map[];
} t_mapdata;

#include <stdio.h>
int main(void) {
    t_mapdata data.map = {};

    data.floor_color = 0xDC6400;
    printf("Floor color: 0x%06X\n", data.floor_color);
    printf("Floor color: %d\n", data.floor_color);
}