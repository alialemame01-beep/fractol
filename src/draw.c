/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:33 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:36 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
