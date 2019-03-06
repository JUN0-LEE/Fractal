/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:49:29 by julee             #+#    #+#             */
/*   Updated: 2018/11/27 19:49:04 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fract		*j;

	x = 0;
	y = 0;
	j = (t_fract *)param;
	if (button == 4)
		j->zoom *= 1.1;
	if (button == 5)
		j->zoom /= 1.1;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fract		*j;
	double		dx;
	double		dy;

	j = (t_fract *)param;
	dx = x;
	dy = y;
	dx -= W / 2;
	dy -= H / 2;
	j->r = -0.7 + dx / W;
	j->i = 0.27015 + dy / H;
	return (0);
}

int		movingnzoom(int key, void *ptr)
{
	t_fract		*j;

	j = (t_fract *)ptr;
	if (key == 24)
		j->zoom *= 1.1;
	if (key == 27)
		j->zoom /= 1.1;
	if (key == 126)
		j->movey -= 0.01;
	if (key == 125)
		j->movey += 0.01;
	if (key == 124)
		j->movex += 0.01;
	if (key == 123)
		j->movex -= 0.01;
	if (key == 53)
		exit(0);
	return (0);
}
