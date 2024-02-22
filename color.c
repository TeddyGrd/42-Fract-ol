/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:30:21 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/22 21:33:45 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_image(t_pixel pixel, char *str, int len)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (pixel.color >> 16) & 0xff;
	g = (pixel.color >> 8) & 0xff;
	b = pixel.color & 0xff;
	str[(pixel.x * 4) + (len * 4 * pixel.y)] = b;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 1] = g;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 2] = r;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 3] = 0;
}

void	set_color_mandelbrot(t_pixel *color, int iterations)
{
	if (iterations == 1000)
	{
		color->red = 0;
		color->green = 0;
		color->blue = 0;
	}
	else
	{
		color->red = (sin(0.05 * iterations) + 1.0) * 128;
		color->green = (sin(0.1 * iterations) + 1.0) * 128;
		color->blue = (sin(0.15 * iterations) + 1.0) * 128;
	}
}

void	set_color_julia(t_pixel *color, int iterations)
{
	double	factor;

	if (iterations == 1000)
	{
		color->red = 0;
		color->green = 0;
		color->blue = 0;
	}
	else
	{
		factor = 0.1;
		color->red = (sin(factor * iterations) + 1.0) * 128;
		color->green = (sin(factor * iterations + 2.0) + 1.0) * 128;
		color->blue = (sin(factor * iterations + 4.0) + 1.0) * 128;
		color->red += (sin(0.1 * iterations) + 1.0) * 128;
		color->green += (sin(0.2 * iterations) + 1.0) * 128;
		color->blue += (sin(0.3 * iterations) + 1.0) * 128;
	}
}
