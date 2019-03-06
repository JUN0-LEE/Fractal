/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:32:39 by julee             #+#    #+#             */
/*   Updated: 2018/11/27 21:30:35 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	if (argc == 2 && ((ft_strcmp(argv[1], "julia") != 0) &&
				(ft_strcmp(argv[1], "mandelbrot") != 0) &&
				(ft_strcmp(argv[1], "clover") != 0)))
		ft_putstr("Invalid fractal name\n");
	else if (argc == 2 && (ft_strcmp(argv[1], "julia") == 0))
		julia_set();
	else if (argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0))
		mandelbrot_set();
	else if (argc == 2 && (ft_strcmp(argv[1], "clover") == 0))
		clover_set();
	else
		ft_putstr("usage : ./fractol fractol_name\n");
	return (0);
}
