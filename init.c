#include "bsq.h"

t_squr    *set_squr(int posX, int posY, int len)
{
    t_squr    *max;

    max->len = len;
    max->posX = posX;
    max->posY = posY;
    return (max);
}
