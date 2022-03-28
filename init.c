#include "bsq.h"

t_squr    *set_squr(int posX, int posY, int len)
{
    t_squr    *max;

    max->len = len;
    max->posX = posX;
    max->posY = posY;
    return (max);
}

t_obstale  *add_link(t_obstale *list, int posX, int posY)
{
    t_obstale *tmp;

    tmp = malloc(sizeof(t_obstale));
    if(tmp)
    {
        tmp->posX = posX;
        tmp->posY = posY;
        tmp->next = list;
    }

    return (tmp);
}

t_obstale *find_obstale(char **map, char *symbol)
{
    t_obstale *list;
    int i;
    int j;

    list = NULL;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == symbol[1])
                list = add_link(list, i, j);
            j += 1;
        }
        i += 1;
    }
    return (list);
}