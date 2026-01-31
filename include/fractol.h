/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:40 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 16:40:31 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/inc/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>

# define SIZE 700

// Magic number constants
# define MOVE_STEP 0.5
# define INITIAL_ITERATIONS 42
# define ITERATION_STEP 42
# define MIN_ITERATIONS 42
# define MAX_ITERATIONS 4200
# define INITIAL_ZOOM 250 // Adjusted for better initial view
# define MIN_ZOOM 0.1
# define MAX_ZOOM 1e10
# define ESCAPE_RADIUS_SQ 4.0
# define BLACK 0x000000

// KEYCODES - LINUX X11
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define P 112
# define M 109

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	oset_x;
	double	oset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// utils.c
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_fractal(t_fractal *fractal);
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);

// utils2.c
double		ft_atof(char *str);

// init.c
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal, char *query);

// mouse_and_keys.c
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

// draw.c
void		draw_mandelbrot(t_fractal *fractal);
void		draw_julia(t_fractal *fractal);

#endif