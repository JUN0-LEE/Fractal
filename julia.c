/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:12:24 by julee             #+#    #+#             */
/*   Updated: 2018/11/27 21:40:48 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_loop(void *ptr)
{
	t_fract		*j;

	j = (t_fract *)ptr;
	if (j->mlx.img_ptr != NULL)
		mlx_destroy_image(j->mlx.mlx_ptr, j->mlx.img_ptr);
	j->mlx.img_ptr = mlx_new_image(j->mlx.mlx_ptr, W, H);
	make_julia(j);
	return (0);
}

int		fractal_manage(int key, void *ptr)
{
	t_fract		*j;

	j = (t_fract *)ptr;
	if (key == 69)
		j->maxiter *= 2;
	if (key == 78)
		j->maxiter /= 2;
	if (key == 15)
		j->red += 1;
	if (key == 14)
		j->red -= 1;
	if (key == 5)
		j->green += 1;
	if (key == 3)
		j->green -= 1;
	if (key == 11)
		j->blue += 1;
	if (key == 9)
		j->blue -= 1;
	movingnzoom(key, j);
	return (0);
}

void	coloring(t_fract *j, int i)
{
	if (i == j->maxiter)
		j->color = 0xFFFFFF;
	else
		j->color = (j->red * i % 256) * 65536
			+ (j->green * i % 256) * 256 + j->blue * i % 256;
	draw_dot(&(j->mlx), j->x, j->y, j->color);
}

void	make_julia(t_fract *j)
{
	int			i;

	j->y = -1;
	while (++(j->y) < H)
	{
		j->x = -1;
		while (++(j->x) < W)
		{
			j->new_r = 1.5 * (j->x - W / 2) / (0.5 * j->zoom * W) + j->movex;
			j->new_i = (j->y - H / 2) / (0.5 * j->zoom * H) + j->movey;
			i = -1;
			while (++i < j->maxiter)
			{
				j->old_r = j->new_r;
				j->old_i = j->new_i;
				j->new_r = j->old_r * j->old_r - j->old_i * j->old_i + j->r;
				j->new_i = 2 * j->old_r * j->old_i + j->i;
				if ((j->new_r * j->new_r + j->new_i * j->new_i) > 4)
					break ;
			}
			coloring(j, i);
		}
	}
	mlx_put_image_to_window(j->mlx.mlx_ptr,
			j->mlx.win_ptr, j->mlx.img_ptr, 0, 0);
}

void	julia_set(void)
{
	t_fract		j;

	ft_memset(&j, 0, sizeof(t_fract));
	j.zoom = 1;
	j.movey = 0;
	j.movex = 0;
	j.maxiter = 128;
	j.r = -0.7;
	j.i = 0.27015;
	j.red = 1;
	j.green = 1;
	j.blue = 1;
	j.mlx.mlx_ptr = mlx_init();
	j.mlx.win_ptr = mlx_new_window(j.mlx.mlx_ptr, W, H, "Julia");
	j.mlx.img_ptr = mlx_new_image(j.mlx.mlx_ptr, W, H);
	make_julia(&j);
	mlx_hook(j.mlx.win_ptr, 2, 0, &fractal_manage, &j);
	mlx_hook(j.mlx.win_ptr, 4, 0, &mouse_press, &j);
	mlx_hook(j.mlx.win_ptr, 6, 0, &mouse_move, &j);
	mlx_hook(j.mlx.win_ptr, 17, 0, close_window, (void *)0);
	mlx_loop_hook(j.mlx.mlx_ptr, &julia_loop, &j);
	mlx_loop(j.mlx.mlx_ptr);
}
