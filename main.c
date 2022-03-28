#include "bsq.h"

int	process(char **map, int fd)
{
	t_obstale *list;
    t_squr  *max;
	char	symbol[4];
	char	*line;

	list = NULL;
	map = get_map(map, fd, symbol);
	if (!map)
		return (0);
	line = ft_getline(fd, NULL);
	if (line && ft_strlen(line) != 0)
	{
		return (0);
	}
    list = find_obstale(map, symbol);
	max = ft_start(map, list, symbol);
	print_map(map);
	return (1);
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

int main(int argc, char *argv[])
{
	int	i;
	int	res;
	int	fd;
	char	**map;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open (argv[i], O_RDONLY, 0);
			if (fd > 0)
			{
				res = process(map, fd);
				if (!res)
					write(1, "map error\n", 10);
				close (fd);
			}
			i++;
		}
	}
	// else
		//standard input
	return (0);
}
