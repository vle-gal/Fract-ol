#ifndef doth_h
# define doth_h
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "printf.h"
# include "mlx.h"

# define BUFFER 1000
# define BUFFER_PRINT 4

# define LARG 1000
typedef struct 	s_comp
{
	double      r;
	double      i;
}				t_comp;

typedef	struct	s_add
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
}				t_add;

typedef	struct	s_other
{
	int			i;
	double		tmp;
	double		image_x;
	double		image_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_other;

typedef struct	s_im
{
	void		*im_ptr;
	int			*im_data;
	int 		bpp;
	int 		size_line;
	int  		endian;
}				t_im;

typedef struct  s_main
{
	t_other		o;
	t_comp		c;
	t_comp		z;
	t_add		add;
	t_im		i;
}               t_main;

/*
**	main
*/

int sec(void);
#endif
