/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:28 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:30 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	// cx and cy are NOT reset here to avoid overwriting command line args
	if (fractal->name && ft_strncmp(fractal->name, "julia", 6) != 0)
	{
		fractal->cx = 0.0;
		fractal->cy = 0.0;
	}
	fractal->color = 0xFCBE11;
	fractal->zoom = INITIAL_ZOOM;
	fractal->offset_x = -1.85; // Better center for Mandelbrot
	fractal->offset_y = -1.35;
	fractal->max_iterations = INITIAL_ITERATIONS;
}

static void	cleanup_mlx_error(t_fractal *fractal, int stage, char *msg)
{
	ft_printf("Error: %s\n", msg);
	if (stage >= 3)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (stage >= 2)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (stage >= 1)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	free(fractal);
	exit(1);
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		cleanup_mlx_error(fractal, 0, "MLX initialization failed");
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	if (!fractal->window)
		cleanup_mlx_error(fractal, 1, "Window creation failed");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
		cleanup_mlx_error(fractal, 2, "Image creation failed");
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
	if (!fractal->pointer_to_image)
		cleanup_mlx_error(fractal, 3, "Getting image data failed");
}
