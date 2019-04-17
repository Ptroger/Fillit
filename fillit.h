#ifndef FILLIT_H
# define FILLIT_H
# include "../bonnelib/libft.h"

typedef		struct	s_file
{
	int				nb_pieces;
	t_list			*pieces;
}					t_file;

typedef		struct	s_point
{
	int				x;
	int				y;
}					t_point;

typedef		struct	s_tetris
{
	int				height;
	int				width;
	char			name;
	t_point			*points;
}					t_tetris;

#endif
