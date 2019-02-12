#include "doth.h"

void		put_the_pix(int x, int y, t_main *m)
{
		// int i;

		// printf("test2, x = %d, y = %d\n", x, y);
	 	m->i.im_data[x * LARG + y] = 255 * m->o.i * 155 / 50;
		// i = x * LARG + y;
		// m->i.im_data[i + 0] = (char)0;
		// m->i.im_data[i + 1] = (char)0 >> 8;
		// m->i.im_data[i + 2] = (char)155 >> 16;
}

void		mbrot(t_main m)
{
	m.add.x1 = -2.1;
	m.add.x2 = 0.6;
	m.add.y1 = -1.2;
	m.add.y2 = 1.2;
	int i_max = 50;
	int zoom = 100;
	m.o.image_x = (m.add.x2 - m.add.x1) * zoom;
	printf("image_x = %f\n", m.o.image_x);
	m.o.image_y = (m.add.y2 - m.add.y1) * zoom;
	printf("image_y = %f\n", m.o.image_y);
	int x = 0;
	int y;

	while(x < m.o.image_x)
	{
		y = 0;
		while(y < m.o.image_y)
		{
			m.c.r = x / zoom + m.add.x1;
			m.c.i = y / zoom + m.add.y1;
			m.z.r = 0;
			m.z.i = 0;
			m.o.i = 0;
			m.o.tmp = m.z.r;
			m.z.r = m.z.r * m.z.r - m.z.i * m.z.i + m.c.r;
			m.z.i = 2 * m.z.i * m.o.tmp + m.c.i;
			m.o.i = m.o.i + 1;
			while (m.z.r * m.z.r + m.z.i * m.z.i < 4 && m.o.i < i_max)
			{
				m.o.tmp = m.z.r;
				m.z.r = m.z.r * m.z.r - m.z.i * m.z.i + m.c.r;
				m.z.i = 2 * m.z.i * m.o.tmp + m.c.i;
				m.o.i = m.o.i + 1;
			}
			// while (1)
			// {
			// 	m.o.tmp = m.z.r;
			// 	m.z.r = m.z.r * m.z.r - m.z.i * m.z.i + m.c.r;
			// 	m.z.i = 2 * m.z.i * m.o.tmp + m.c.i;
			// 	m.o.i = m.o.i + 1;
			// 	if (m.z.r * m.z.r + m.z.i * m.z.i > 4 || m.o.i > i_max)
			// 	{
			// 		break;
			// 	}
			// }
			if (m.o.i == i_max)
			{
				// m.i.im_data[(int)x * (int)LARG + (int)y] = (char)255;
				put_the_pix(x, y, &m);
			}
			y++;
		}
		x++;
	}
		printf("%d, %d\n", x, y);
}

int			main(void)
{
	ft_printf("----------Fract'ol------------------------------------------\n");
	t_main	m;
	m.o.mlx_ptr = mlx_init();
	m.o.win_ptr = mlx_new_window(m.o.mlx_ptr, 1000, LARG, "test");
	m.i.im_ptr = mlx_new_image(m.o.mlx_ptr, 1000, LARG);
	m.i.im_data = (int *)mlx_get_data_addr(m.i.im_ptr, &m.i.bpp, &m.i.size_line,\
		 &m.i.endian);
	mbrot(m);
	mlx_put_image_to_window(m.o.mlx_ptr, m.o.win_ptr, m.i.im_ptr, 0, 0);
	mlx_loop(m.o.mlx_ptr);
}
