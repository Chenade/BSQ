#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_squr t_squr;
typedef struct s_obstale t_obstale;

struct s_squr {
    int posX;
    int posY;
    int len;
};

struct s_obstale {
    int         posX;
    int         posY;
    t_obstale  *next;
};

int     get_square(char **map, int posX, int posY, char *sep);
t_squr    *set_max(int posX, int posY, int len);
t_squr    *find_squr(char **map, t_obstale *list, char *sep);
t_squr    *ft_start(char **map, t_obstale *list, char *sep);
#endif