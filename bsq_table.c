#include "bsq.h"
/*
int check_symbol(char *line, char *symbol, char c, int *x)
{
	if (!(in_charset(symbol, c)))
		return (0);
	if (!(*x))
	{
		line[*x] = symbol[1];
		*x = 1;
	}
	return (1);
}*/

char	*ft_getline(int fd, char *symbol)
{
	static char	line[1024];
	char		c[1];
	int		x;
	int		i;

	x = 0;
	while (1)
	{
		i = read(fd, c, 1);
		if (i == 0 || c[0] == 10)
		{
			line[x] = 0;
			break ;
		}
		if (symbol)
		{
			if (!(in_charset(symbol, c[0])))
				return (NULL);
		}
		line[x++] = c[0];
	}
	return (line);
}

int	get_symbol(int fd, char *symbol)
{
	char	*line;
	int	i;
	int	y;
	
	i = -1;
	y = 0;
	line = ft_getline(fd, NULL);
	while (line[y])
		y++;
	while (++i < 3)
	{
		symbol[i] = line[y - i - 1];
		line[y - i] = 0;
	}
	symbol[i] = 0;
	return (ft_atoi(line));
}
/*
int	fill_map(char **map, int size_y, int fd, char *symbol)
{
	int i;
	int	len;
	char	*line;

	i = 1;
	while (++i < size_y)
	{
		len = ft_strlen(map[1]);
		line = ft_getline(fd, symbol);
		if (!line)
			return (0);
		if (ft_strlen(line) != len)
			return (0);
		ft_strcpy(map[i], line);
	}
		return (1);
}
*/
char	**get_map(char **map, int fd, char *symbol, int *size_y)
{
	int	i;
	int	size_x;
	char	*line;

	i = -1;
	*size_y = get_symbol(fd, symbol);
	printf("size ---------------%d\n", *size_y);
	if (*size_y < 2)
		return (NULL);
	map = (char **) malloc (sizeof (char *) * (*size_y + 1));
	line = ft_getline(fd, symbol);
	printf("line : %s\n", line);
	size_x = ft_strlen(line);
	printf("size -==============%d\n", size_x);
	while (++i < *size_y)
	{
		map[i] = (char *)malloc(size_x + 1);
		ft_strcpy(map[i], line);
		printf("\nmap[%d]  :  %s\n", i, line);
		line = ft_getline(fd, symbol);
		if (!line && ft_strlen(line) != size_x)
			return (NULL);
	}
	map[i] = NULL;
	return (map);
}
