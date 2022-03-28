#include "bsq.h"

int get_square(char **map, int posX, int posY, char *sep)
{
    int ans;
    int len;
    int valid;

    ans = 0;
    len = -1;
    valid = 1;
    while (valid)
    {
        len += 1;
        while (len >= 0 && valid)
        {
            if ((map[posX][posY + len] == sep[1]) ||
                    (map[posX + len][posY] == sep[1]) ||
                        (map[posX + len][posY + len] == sep[1]))
                valid = 0;
            len -= 1;
        }
        if (valid)
            ans = len;
    }
    return (ans);
}

squr    *set_max(int posX, int posY, int len)
{
    squr    *max;

    max->len = len;
    max->posX = posX;
    max->posY = posY;
    return (max);
}

squr    *find_squr(char **map, t_list *list, char *sep)
{
    squr max;
    int len;
    int posX;
    int posY;

    max = set_max(0, 0, 0);
    posX = list->posX;
    posY = list->posY;
    len = get_square(map, posX + 1, posY + 1, sep);
    if (len > max->len)
        max = set_max(posX + 1, posY + 1);
    len = get_square(map, posX + 1, posY, sep);
    if (len > max->len)
        max = set_max(posX + 1, posY);
    len = get_square(map, posX, posY + 1, sep);
    if (len > max->len)
        max = set_max(posX, posY + 1);
    return (max);
}

squr    *ft_start(char **map, t_list *list, char *sep)
{
    t_squr *max;
    t_squr *cur_max;

    max = NULL;
    while (list)
    {
        cur_max = find_squr(map, list, sep);
        if ((cur_max->len) > (max->max))
            max = set_max(cur_max->posX, cur_max->posY, cur_max->len);
        list = list->next;
    }
    return  (max);
}