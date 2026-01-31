/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:00 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 16:10:51 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;
	double	new_zoom;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		new_zoom = fractal->zoom * zoom_level;
		if (new_zoom > MAX_ZOOM)
			return ;
		fractal->oset_x = (x / fractal->zoom + fractal->oset_x) - (x / new_zoom);
		fractal->oset_y = (y / fractal->zoom + fractal->oset_y) - (y / new_zoom);
		fractal->zoom = new_zoom;
	}
	else if (zoom == -1)
	{
		new_zoom = fractal->zoom / zoom_level;
		if (new_zoom < MIN_ZOOM)
			return ;
		fractal->oset_x = (x / fractal->zoom + fractal->oset_x) - (x / new_zoom);
		fractal->oset_y = (y / fractal->zoom + fractal->oset_y) - (y / new_zoom);
		fractal->zoom = new_zoom;
	}
}

void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == LEFT)
		fractal->oset_x -= MOVE_STEP / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->oset_x += MOVE_STEP / fractal->zoom;
	else if (key_code == UP)
		fractal->oset_y -= MOVE_STEP / fractal->zoom;
	else if (key_code == DOWN)
		fractal->oset_y += MOVE_STEP / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cy);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
