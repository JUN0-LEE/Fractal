/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:05 by julee             #+#    #+#             */
/*   Updated: 2018/11/27 21:49:59 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_loop(void *ptr)
{
	t_fract		*m;

	m = (t_fract *)ptr;
	if (m->mlx.img_ptr != NULL)
		mlx_destroy_image(m->mlx.mlx_ptr, m->mlx.img_ptr);
	m->mlx.img_ptr = mlx_new_image(m->mlx.mlx_ptr, W, H);
	make_mandelbrot(m);
	return (0);
}

void	mandelbrot_set(void)
{
	t_fract	m;

	ft_memset(&m, 0, sizeof(t_fract));
	m.zoom = 1;
	m.movey = 0;
	m.movex = -0.5;
	m.maxiter = 160;
	m.red = 1;
	m.green = 1;
	m.blue = 1;
	m.mlx.mlx_ptr = mlx_init();
	m.mlx.win_ptr = mlx_new_window(m.mlx.mlx_ptr, MW, MH, "Mandelbrot");
	m.mlx.img_ptr = mlx_new_image(m.mlx.mlx_ptr, MW, MH);
	make_mandelbrot(&m);
	mlx_hook(m.mlx.win_ptr, 2, 0, &fractal_manage, &m);
	mlx_hook(m.mlx.win_ptr, 4, 0, &mouse_press, &m);
	mlx_hook(m.mlx.win_ptr, 17, 0, close_window, (void *)0);
	mlx_loop_hook(m.mlx.mlx_ptr, &mandelbrot_loop, &m);
	mlx_loop(m.mlx.mlx_ptr);
}

void	mandelbrot_initializer(t_fract *m)
{
	m->r = 1.5 * (m->x - MW / 2) / (0.5 * m->zoom * MW) + m->movex;
	m->i = (m->y - MH / 2) / (0.5 * m->zoom * MH) + m->movey;
	m->new_r = 0;
	m->new_i = 0;
	m->old_r = 0;
	m->old_i = 0;
}

void	mandelbrot_coloring(t_fract *j, int i)
{
	j->color = (j->red * i % 256) * 65536
			+ (j->green * i % 256) * 256 + j->blue * i % 256;
	draw_dot(&(j->mlx), j->x, j->y, j->color);
}

void	make_mandelbrot(t_fract *m)
{
	int		i;

	m->y = -1;
	while (++(m->y) < MH)
	{
		m->x = -1;
		while (++(m->x) < MW)
		{
			mandelbrot_initializer(m);
			i = -1;
			while (++i < m->maxiter)
			{
				m->old_r = m->new_r;
				m->old_i = m->new_i;
				m->new_r = m->old_r * m->old_r - m->old_i * m->old_i + m->r;
				m->new_i = 2 * m->old_r * m->old_i + m->i;
				if ((m->new_r * m->new_r + m->new_i * m->new_i) > 4)
					break ;
			}
			mandelbrot_coloring(m, i);
		}
	}
	mlx_put_image_to_window(m->mlx.mlx_ptr,
			m->mlx.win_ptr, m->mlx.img_ptr, 0, 0);
}
