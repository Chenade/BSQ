#include "bsq.h"

int	ft_strlen(char *str)
{
	int	ans;
	ans = 0;
	while (str[ans])
		ans ++;
	return (ans);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

int	in_charset(char *charset, char c)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}
