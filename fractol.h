/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:46:35 by julee             #+#    #+#             */
/*   Updated: 2018/11/27 21:45:47 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# define W 1000
# define H 1000
# define MW 1200
# define MH 900

typedef struct		s_struct1
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;
}					t_mlx;

typedef struct		s_struct2
{
	double			r;
	double			i;
	double			new_r;
	double			new_i;
	double			old_r;
	double			old_i;
	double			zoom;
	double			movex;
	double			movey;
	int				maxiter;
	int				color;
	int				x;
	int				y;
	int				red;
	int				green;
	int				blue;
	t_mlx			mlx;
}					t_fract;

int					julia_loop(void *ptr);
void				make_julia(t_fract *j);
void				julia_set(void);
int					fractal_manage(int key, void *ptr);
void				coloring(t_fract *j, int i);

void				mandelbrot_set(void);
int					mandelbrot_iter(int key, void *ptr);
void				make_mandelbrot(t_fract *m);
int					mandelbrot_loop(void *ptr);

int					close_window(void *param);
int					mouse_move(int x, int y, void *param);
int					mouse_press(int buttun, int x, int y, void *param);
int					movingnzoom(int key, void *ptr);

void				make_clover(t_fract *j);
int					clover_loop(void *ptr);
void				clover_set(void);

void				draw_dot(t_mlx *mlx, int x, int y, int color);

#endif
