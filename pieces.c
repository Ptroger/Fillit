#include "fillit.h"
#include "../GNLfail/libft/libft.a"

t_point			*new_points_list(*t_point points)
{
	t_point	temp;
	int		i;

	temp = points;
	i = 0;
	while (i < 4)
	{
		if (!(temp = (t_point*)malloc(sizeof(t_point) * 4)))
			return (NULL);
		i++;
	}
}

t_tetris		*new_tetris_list(t_tetris	*piece, int nb_elem)
{
	t_tetris	*temp;
	int			j;

	temp = piece;
	j = 0;
	while (j <= nb_elem)
	{
		if (!(temp = (t_tetris*)malloc(sizeof(t_tetris))))
			return (NULL);
		if (!(new_points_list(temp->points)))
			return (NULL);
		temp = temp->next;
		j++;
	}
	temp = NULL;
	return (piece);
}
