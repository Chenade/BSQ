#ifndef BSQ_H
# define BSQ_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
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

//main
int	        process(char **map, int fd);
void        print_map(char **map, t_squr *max, char *symbol);
//bsq_table
int         check_symbol(char *line, char *symbol, char c, int *x);
char	    *ft_getline(int fd, char *symbol);
int	        get_symbol(int fd, char *symbol);
int	        fill_map(char **map, int size_y, int fd, char *symbol);
char	    **get_map(char **map, int fd, char *symbol);
//init
t_squr      *set_squr(int posX, int posY, int len);
t_obstale   *find_obstale(char **map, char *symbol);
//solve
int         check_obstale(char **map, int posX, int posY, char *sep);
int         check_squr(char **map, t_squr *squr, char *sep);
int         get_square(char **map, int posX, int posY, char *sep);
t_squr      *find_squr(char **map, t_obstale *list, char *sep);
t_squr      *ft_start(char **map, t_obstale *list, char *sep);
//utils.c
int	        ft_atoi(char *str);
char        *ft_strcpy(char *dest, char *src);
int	        ft_strlen(char *str);
int	        in_charset(char *charset, char c);
#endif
