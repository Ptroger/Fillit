#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"
#include "../GNLfail/get_next_line.h"

int		check_line(char *map)
{
	int	c;
	int	diese;

	diese = 0;
	c = 0;
	while (c < 4)
	{
		if (map[c] != '#' && map[c] != '.')
			return (-1);
		if (map[c] == '#')
			diese++;
		c++;
	}
	if (map[c] != '\n')
		return (-1);
	return (diese);
}

int		check_chars(char *map)
{
	int	i;
	int	l;
	int	nbr_tris;
	int	diese;

	diese = 0;
	nbr_tris = 0;
	i = 0;
	l = 0;
	while (nbr_tris++ < 26)
	{
		while (l++ < 4)
		{
			if (check_line(map + i) == -1)
				return (-1);
			diese += check_line(map + i);
			i += 5;
		}
		if (diese % 4 != 0 || map[i] != '\n')
				return (-1);
		i++;
		if (map[i + 1] == '\0')
			return (nbr_tris);
		l = 0;
	}
	return (-1);
}

char	*read_file(int	fd)
{
	char		*map;
	char		*test;
	int			i;

	i = 0;
	map = ft_strnew(547);
	map[547] = '\0';
	if ((read(fd, map, 546)) == -1)
	{
		// A FAIRE == ETRE SUR QUil Y A LE BON NOMBRE DE TTRIS
		ft_putstr("READ ERROR");
		return (NULL);
	}
	if (read(fd, test, 1) != 0)
	{
		ft_putstr("WRONG NUMBER OF TTRIS");
		return (NULL);
	}
	if (check_chars(map) == -1)
	{
		ft_putstr("WRONG CHAR ON MAP");
		return (NULL);
	}
	return (map);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*map;

	fd = open(argv[1], O_RDONLY);
	if ((map = read_file(fd)) == NULL)
		return (-1);
	fill_tetris(map, check_chars(map));
	return (0);
}
