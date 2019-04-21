#ifndef FILLIT_H
# define FILLIT_H
# include "../bonnelib/libft.h"

typedef		struct	s_point
{
	int				x;
	int				y;
	struct	s_point	*next;
}					t_point;

typedef		struct	s_tetris
{
	char			name;
	t_point			*points;
	struct s_tetris	*next;
}					t_tetris;

int			check_line(char *map);
int			check_chars(char *map);
char		*read_file(int fd);
t_tetris	*fill_tetris(char *map, int nb_tris);
t_point		*get_points(char *map);
#endif
