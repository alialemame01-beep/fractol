/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:05:11 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/31 16:05:11 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

static double	parse_decimal(char *str)
{
	double	res;
	double	div;

	res = 0;
	div = 1;
	while (*str >= '0' && *str <= '9')
	{
		div /= 10;
		res += (*str - '0') * div;
		str++;
	}
	return (res);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		res += parse_decimal(str + 1);
	return (res * sign);
}
