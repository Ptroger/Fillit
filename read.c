#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"
#include "../GNLfail/get_next_line.h"

int		check_chars(char *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	// A REVOIR
	while (map[i])
	{
		if (map[i] == '\n')
		{
			// CHECK SI IL Y A LE \N EN FIN DE TETRIS
			if (j == 1)
				j = 0;
			// CHECK SI IL Y A LE \N EN FIN DE LIGNE
			else if ((i + 1) % 5 == 0)
				j = 1;
			else
				return (-1);
		}
		if (map[i] != '\n' && map[i] != '.' && map[i] != '#')
			return (-1);
		i++;
	}
	return (1);
}

char	*read_file(int	fd)
{
	char		*map;
	int			i;

	i = 0;
	if ((read(fd, map, 546)) == -1)
	{
		// A FAIRE == ETRE SUR QUil Y A LE BON NOMBRE DE TTRIS
		ft_putstr("READ ERROR");
		return (NULL);
	}
	if (read(fd, map, 1) != 0)
	{
		ft_putstr("WRONG NUMBER OF TTRIS");
		return (NULL);
	}
	if (!(check_chars(map)))
	{
		ft_putstr("WRONG CHAR ON MAP");
		return (NULL);
	}

	return (map);
}

int main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	read_file(fd);
	return (0);
}
