#include "bsq.h"

int	ft_atoi(char *str)
{
	int	ans;
	int	is_neg;
	int	i;

	ans = 0;
	is_neg = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 6 && str[i] < 14))
		i += 1;
	while (str[i] == 43 || str[i] == 45)
	{
		is_neg *= 44 - str[i];
		i += 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - 48);
		i += 1;
	}
	return (ans * is_neg);
}