#include "../GNLfail/get_next_line.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

static	int	count_links(t_point *points)
{
	printf("count_links\n");
	int count;
	t_point *temp;
	t_point *premier;

	premier = points;
	temp = points->next;
	count = 0;
	while (points)
	{
		if (!(points->next))
			return (count);
		if (temp == points)
			temp = points->next;
		if (points->x + 1 == temp->x || points->x - 1 == temp-> x)
			if (points->y == temp ->y)
				count++;
		if (points->y + 1 == temp->y || points->y - 1 == temp-> y)
			if (points->x == temp ->x)
				count++;
		points = points->next;
		temp = premier;
	}
	return (count);
}

int				check_tetris(t_tetris *temp)
{

	return (1);
}

void	get_x(char	*map, t_point *points)
{
	printf("get_x\n");
	int	x;
	int	i;

	i = 0;
	x = 1;
	while (map[i] != '#')
		i++;
	i++;
	while (i <= 21)
	{
		printf("%c\n", map[i]);
		printf("%c\n", map[i + 1]);
		printf("%c\n", map[i + 2]);
		while (map[i] == '.')
		{
			printf("la\n");
			i++;
			x++;
		}
		printf("%d\n", x);
		if (map[i] == '\n')
			x = x - 4;
		printf("%d\n", x);
		if (map[i] == '#')
		{
			points->x = ()malloc(sizeof(int));
			printf("ou ici\n");
			points->x = x;
			printf("ou ici\n");
			points = points->next;
		}
		i++;
	}
}

void	get_y(char	*map, t_point *points)
{
	printf("get_y\n");
	int	y;
	int	i;
	int	line;

	line = 0;
	y = 0;
	i = 0;
	while (map[i] != '#')
		i++;
	while (line < 4)
	{
		printf("ici?\n");
		while (map[i] != '\n' && map[i] != '#')
			i++;
		if (map[i] == '#')
		{
			printf("la?\n");
			points->y = y;
			points = points->next;
		}
		i++;
		y++;
		line++;
	}
}

t_point			*get_points(char *map)
{
	printf("get_points\n");
	int			i;
	t_point		*points;
	t_point		*temp;
	i = 0;
	if (!(points = (t_point*)ft_memalloc(sizeof(t_point) * 4)))
	{
		ft_putstr("MALLOC ERROR ON LINKED LIST POINTS");
		return (NULL);
	}
	temp = points->next;
	points->x = 0;
	printf("%d\n", points->x);
	points->y = 0;
	while (i++ <= 2)
	{
		get_x(map, temp);
		points->next = temp;
		get_y(map, temp);
	}
	return (points);
}

// JAI VERIFIER:
// - LE NOMBRE DE TTRIS
// - QU IL Y A LES BONS CHARACTERS
t_tetris		*fill_tetris(char *map, int nb_tris)
{
	int			i;
	t_tetris	*tetris;
	t_tetris	*temp;

	printf("fill_tetris\n");
	if (!(tetris = (t_tetris*)malloc(sizeof(t_tetris) * nb_tris)))
	{
		ft_putstr("MALLOC ERROR ON LINKED LIST TETRIS");
		return (NULL);
	}
	temp = tetris;
	i = 0;
	while (i++ < nb_tris)
	{
		temp->name = i + 65;
		temp->points = get_points(map);
		check_tetris(temp);
		temp = tetris->next;
	}
	return (tetris);
}
