#include "bsq.h"

int check_obstale(char **map, int posX, int posY, char *sep)
{
    if (map[posX][posY])
        if (map[posX][posY] != sep[1])
            return (0);
    return (1);
}

int check_squr(char **map, t_squr *squr, char *sep)
{
    int valid;
    int len;
    int posX;
    int posY;

    valid = 1;
    len = squr->len;
    posX = squr->posX;
    posY = squr->posY;
    while (len)
    {
        if (check_obstale(map, posX + len, posY + squr->len, sep))
            return (0);
        len -= 1;
    }
    len = squr->len;
    while (len)
    {
        if (check_obstale(map, posX + squr->len, posY + len, sep))
            return (0);
        len -= 1;
    }
    return (valid);
}

int get_square(char **map, int posX, int posY, char *sep)
{
    int     ans;
    int     len;
    int     valid;
    t_squr  *check;

    ans = 0;
    len = -1;
    valid = 1;
    while (valid)
    {
        len += 1;
        while (len >= 0 && valid)
        {
            check = set_squr(posX, posY, len);
            if (!(check_squr(map, check ,sep)))
                valid = 0;
            len -= 1;
        }
        if (valid)
            ans = len;
    }
    return (ans);
}

t_squr    *find_squr(char **map, t_obstale *list, char *sep)
{
    t_squr *max;
    int len;
    int posX;
    int posY;

    max = set_squr(0, 0, 0);
    posX = list->posX;
    posY = list->posY;
    len = get_square(map, posX + 1, posY + 1, sep);
    if (len > max->len)
        max = set_squr(posX + 1, posY + 1, len);
    len = get_square(map, posX + 1, posY, sep);
    if (len > max->len)
        max = set_squr(posX + 1, posY, len);
    len = get_square(map, posX, posY + 1, sep);
    if (len > max->len)
        max = set_squr(posX, posY + 1, len);
    return (max);
}

t_squr    *ft_start(char **map, t_obstale *list, char *sep)
{
    t_squr *max;
    t_squr *cur_max;

    max = NULL;
    while (list)
    {
        cur_max = find_squr(map, list, sep);
        if ((cur_max->len) > (max->len))
            max = set_squr(cur_max->posX, cur_max->posY, cur_max->len);
        list = list->next;
    }
    printf("WORKED\n\n");
    return  (max);
}