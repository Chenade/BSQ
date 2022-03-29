#include "bsq.h"

int	process(char **map, int fd)
{
	t_obstale *list;
    t_squr  *max;
	int	size_y;
    	char	symbol[4];
	char	*line;

	list = NULL;
	map = get_map(map, fd, symbol, &size_y);
	if (!size_y)
		return (0);
	line = ft_getline(fd, NULL);
	if (line && ft_strlen(line) != 0)
	{
		return (0);
	}
    list = find_obstale(map, symbol);
	max = ft_dp(map, 10, symbol);
	print_map(map, max, symbol);
	return (1);
}

void print_map(char **map, t_squr *max, char *symbol)
{
	int	i;
	int	j;
    int x;
    int y;

    x = max->posX - max->len;
    y = max->posY - max->len;
	i = 1;
	while(map[i])
	{
		j = 1;
        while (map[i][j])
        {
            if (i > x && i <= x + max->len && j > y && j <= y + max->len)
                    write (1, &symbol[0], 1);
	    else
           	 write (1, &map[i][j], 1);
            j += 1;
        }
		i += 1;
		write (1, "\n", 1);
	}
	write (1, "\n", 1);
}

int main(int argc, char *argv[])
{
	int	i;
	int	res;
	int	fd;
	char	**map;

	i = 1;
	while (1)
	{
		if (argc == 1)
			fd = 0;
		else
			fd = open (argv[i++], O_RDONLY, 0);
		if (fd >= 0)
		{
			res = process(map, fd);
			if (!res)
				write(1, "map error\n", 10);
			close (fd);
		}
		if (--argc <= 1)
			break ;
	}
	return (0);
}
