#include "bsq.h"

int check_dp(int **dp, int i, int j)
{
    int min;

    if (i == 0 || j == 0)
        return (0);
    min = dp[i][j - 1];
    if (min > dp[i - 1][j])
        min = dp[i - 1][j];
    if (min > dp[i - 1][j - 1])
        min = dp[i- 1][j - 1];
    return (min);
}

int **init_dp(char **map, int size)
{
    int     i;
    int     j;
    int     **dp;

    i = 0;
    dp = (int **) malloc ( size * sizeof(int *));
    while (map[i])
    {
        j = 0;
        dp[i] = (int *) malloc (ft_strlen(map[i]) * sizeof (int));
        while (map[i][j])
        {
            dp[i][j] = 0;
            j += 1;
        }
        i += 1;
    }
    return (dp);
}

void    free_dp(int **dp, int size)
{
    int i;

    i = -1;
    while (++i < size)
    {
        free (dp[i]);
    }
    free (dp);
}

t_squr  *ft_dp(char **map, int size_y, char *sep)
{
    int     i;
    int     j;
    int     **dp;
    t_squr  *max;

    i = -1;
    max = set_squr(max, 0, 0, 0);
    dp = init_dp(map, size_y + 1);
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] != sep[1])
                dp[i][j] = (check_dp(dp, i, j) + 1);
            if (max->len < dp[i][j])
                max = set_squr(max, i, j, dp[i][j]);
        }
    }
    free_dp(dp, size_y);
    return (max);
}
