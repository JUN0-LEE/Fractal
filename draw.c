/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:47:43 by julee             #+#    #+#             */
/*   Updated: 2018/11/27 16:18:09 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_dot(t_mlx *mlx, int x, int y, int color)
{
	int i;

	i = 0;
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx->color = mlx_get_color_value(mlx->mlx_ptr, color);
	while (i < mlx->bpp / 8)
	{
		*(mlx->img_addr + (mlx->size_line * y
					+ (mlx->bpp * x) / 8) + i) = mlx->color >> (8 * i) & 0xFF;
		i++;
	}
}
