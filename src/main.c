/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:12 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 14:37:09 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *name)
{
	if (!name)
		return (1);
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
	{
		draw_mandelbrot(fractal);
	}
	else if (ft_strncmp(name, "julia", 6) == 0)
	{
		draw_julia(fractal);
	}
	else
	{
		ft_printf("Error: Invalid fractal name\n");
		ft_printf("Available fractals: mandelbrot, julia\n");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

static int	is_valid_double(char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		else if (str[i] == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

static int	check_args(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
	{
		ft_printf("Usage: ./fractol <fractal> [cx cy]\n");
		ft_printf("Available fractals: mandelbrot, julia\n");
		return (0);
	}
	if (argc == 4 && (!is_valid_double(argv[2]) || !is_valid_double(argv[3])))
	{
		ft_printf("Error: cx and cy must be valid decimal numbers\n");
		return (0);
	}
	return (1);
}

static void	init_fractal_state(t_fractal *fractal, int argc, char **argv)
{
	fractal->name = argv[1];
	init_fractal(fractal);
	if (argc == 4)
	{
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else
	{
		fractal->cx = -0.745429;
		fractal->cy = 0.05;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (!check_args(argc, argv))
		return (1);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal_state(fractal, argc, argv);
	init_mlx(fractal);
	mlx_hook(fractal->window, 2, 1L << 0, key_hook, fractal);
	mlx_hook(fractal->window, 4, 1L << 2, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
