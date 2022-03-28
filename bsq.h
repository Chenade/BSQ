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

t_squr      *set_squr(int posX, int posY, int len);
int         check_obstale(char **map, int posX, int posY, char *sep);
int         check_squr(char **map, t_squr *squr, char *sep);
int         get_square(char **map, int posX, int posY, char *sep);
t_squr      *find_squr(char **map, t_obstale *list, char *sep);
t_squr      *ft_start(char **map, t_obstale *list, char *sep);
#endif