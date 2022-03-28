#include "bsq.h"

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
			if (!x)
			{
				line[x] = symbol[1];
				x = 1;
			}
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

int	fill_map(char **map, int y, int fd, char *symbol)
{
	int	len;
	char	*line;
	len = ft_strlen(map[1]);
	line = ft_getline(fd, symbol);
	if (!line)
		return (0);
	if (ft_strlen(line) != len)
		return (0);
	ft_strcpy(map[y], line);
	y++;
	return (1);
}

char	**get_map(char **map, int fd, char *symbol)
{
	int	i;
	int	size_y;
	int	size_x;
	char	*line;

	i = -1;
	size_y = get_symbol(fd, symbol) + 1;
	if (size_y < 2)
		return (NULL);
	map = (char **) malloc (sizeof (char *) * (size_y + 1));
	line = ft_getline(fd, symbol);
	size_x = ft_strlen(line) + 1;
	while (++i < size_y)
		map[i] = (char *)malloc(size_x + 1);
	map[i] = NULL;
	i = -1;
	while (++i < size_x - 1)
		map[0][i] = symbol[1];
	map[0][i] = 0;
	ft_strcpy(map[1], line);
	i = 1;
	while (++i < size_y)
	{
		if (!(fill_map(map, i, fd, symbol)))
			return (NULL);
	}
	return (map);
}

void print_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i += 1;
	}
}