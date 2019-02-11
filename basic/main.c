#include "doth.h"

void		mbrot(t_main m)
{
	m.add.x1 = -2.1;
	m.add.x2 = 0.6;
	m.add.y1 = -1.2;
	m.add.y2 = 1.2;
	int zoom = 10;
	int i_max;
	m.o.image_x = (m.add.x2 - m.add.x1) * zoom;
	m.o.image_y = (m.add.y2 - m.add.y1) * zoom;
	int x = 0;

	while(x < image_x)
	{
		while(y < image_y)
		{
			x++;
			m.c.r = x / zoom + m.add.x1;
			m.c.i = y / zoom + m.add.y1;
			m.z.r = 0;
			m.z.i = 0;
			m.o.i = 0;
			while (1)
			{
				m.o.tmp = m.z.r;
				m.z.r = m.z.r * m.z.r - m.z.r + m.c.r;
				m.z.i = 2 * m.z.i * m.o.tmp + m.c.i;
				m.o.i = m.o.i + 1;
				if (m.z.r * m.z.r + m.z.i * m.z.i < 4 && m.o.i < i_max)
					break;
			}
			if (m.o.i = i_max)
				mlx_pixel_put(m.mlx_ptr, m.win_ptr, x, y);
			else
				mlx_pixel_put(m.mlx_ptr, m.win_ptr, x, y);
		}
	}
}

int			main(void)
{
	ft_printf("----------Fract'ol--------------------------------------------\n");
	t_main	m;
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, 1000, 1000, "test");
	mbrot(m);
	mlx_loop(m.mlx_ptr);
}
