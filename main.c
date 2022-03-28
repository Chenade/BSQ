#include "bsq.h"

int	process(char **map, int fd)
{
	t_obstale *list;
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
	ft_start(map, list, symbol);
	print_map(map);
	return (1);
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
