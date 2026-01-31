/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:54 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 16:40:03 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;
	int	index;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		return ;
	buffer = (int *)fractal->pointer_to_image;
	index = (y * fractal->size_line / 4) + x;
	buffer[index] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	if (fractal)
	{
		if (fractal->image && fractal->mlx)
			mlx_destroy_image(fractal->mlx, fractal->image);
		if (fractal->window && fractal->mlx)
			mlx_destroy_window(fractal->mlx, fractal->window);
		if (fractal->mlx)
		{
			mlx_destroy_display(fractal->mlx);
			free(fractal->mlx);
		}
		free(fractal);
	}
	exit(0);
}

double	generate_random_c(void)
{
	static int	seeded = 0;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > MIN_ITERATIONS)
			fractal->max_iterations -= ITERATION_STEP;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < MAX_ITERATIONS)
			fractal->max_iterations += ITERATION_STEP;
	}
}
