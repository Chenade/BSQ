#include "bsq.h"

int check_obstale(char **map, t_squr *check, char *sep, t_obstale *max_corner)
{
	if (check->posX > max_corner->posX - 1 || check->posY > max_corner->posY - 1)
		return (1);
    if (map[check->posX][check->posY] != 0)
    {
        	if (map[check->posX][check->posY] != sep[1])
            		return (0);
    }
    return (1);
}

int check_squr(char **map, t_squr *squr, char *sep, t_obstale *max_corner)
{
    int valid;
    int len;
    int posX;
    int posY;
    t_squr  *check;

    valid = 1;
    len = squr->len;
    posX = squr->posX;
    posY = squr->posY;
    while (len)
    {
        check = set_squr(posX + len, posY + squr->len, 0);
        if (check_obstale(map, check, sep, max_corner))
            return (0);
        len -= 1;
    }
    len = squr->len;
    while (len)
    {
        check = set_squr(posX + squr->len, posY + len, 0);
        if (check_obstale(map, check, sep, max_corner))
            return (0);
        len -= 1;
    }
    return (valid);
}

int get_square(char **map, t_squr *start_pos, char *sep, t_obstale *max_corner)
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
        len = ans + 1;
	int test = len;
        while (len >= 0 && valid)
        {
            check = set_squr(start_pos->posX, start_pos->posY, len);
            if (!(check_squr(map, check ,sep, max_corner)))
                valid = 0;
            len -= 1;
        }
        if (valid)
            ans = test;
    }
    return (ans);
}

t_squr    *find_squr(char **map, t_obstale *list, char *sep, t_obstale *max_corner)
{
    t_squr *max;
    int len;
    int posX;
    int posY;
    t_squr *check;

    max = set_squr(0, 0, 0);
    posX = list->posX;
    posY = list->posY;
    check = set_squr(posX + 1, posY, 0);
    len = get_square(map, check, sep, max_corner);
    if (len > max->len)
        max = set_squr(posX + 1, posY, len);
    check = set_squr(posX + 1, posY + 1, 0);
    len = get_square(map, check, sep, max_corner);
    if (len > max->len)
        max = set_squr(posX + 1, posY + 1, len);
    check = set_squr(posX, posY + 1, 0);
    len = get_square(map, check, sep, max_corner);
    if (len > max->len)
        max = set_squr(posX, posY + 1, len);
    return (max);
}

t_squr    *ft_start(char **map, t_obstale *list, char *sep)
{
    t_squr *max;
    t_squr *cur_max;
    t_obstale   *max_corner;

    max_corner = list;
    list = list->next;
    max = set_squr(0, 0, 0);
    while (list)
    {
        cur_max = find_squr(map, list, sep, max_corner);
        if ((cur_max->len) >= (max->len))
            max = set_squr(cur_max->posX, cur_max->posY, cur_max->len);
        list = list->next;
    }
    return  (max);
}
