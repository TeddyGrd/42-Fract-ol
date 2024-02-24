/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:04:34 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/24 14:12:34 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	initialize_mandelbrot(t_fractal *mandelbrot, t_data *data)
{
	mandelbrot->min.real = -1.0 / data->zoom;
	mandelbrot->min.imag = -1.0 / data->zoom;
	mandelbrot->max.real = 1.0 / data->zoom;
	mandelbrot->max.imag = 1.0 / data->zoom;
}

void	calculate_mandelbrot(t_fractal *mandelbrot)
{
	t_complex	c;
	t_complex	z;
	t_complex	tmp;

	c.real = mandelbrot->min.real + (mandelbrot->x
			/ (double)WIDTH) * (mandelbrot->max.real
			- mandelbrot->min.real);
	c.imag = mandelbrot->min.imag + (mandelbrot->y
			/ (double)HEIGHT) * (mandelbrot->max.imag
			- mandelbrot->min.imag);
	z.real = 0.0;
	z.imag = 0.0;
	mandelbrot->iterations = 0;
	while (mandelbrot->iterations < 1000
		&& (z.real * z.real + z.imag * z.imag) < 4.0)
	{
		tmp.real = z.real * z.real - z.imag * z.imag + c.real;
		tmp.imag = 2 * z.real * z.imag + c.imag;
		z = tmp;
		mandelbrot->iterations++;
	}
}

void	draw_mandelbrot(char *image, t_fractal *mandelbrot)
{
	t_pixel		pixel;

	mandelbrot->y = 0;
	while (mandelbrot->y < HEIGHT)
	{
		mandelbrot->x = 0;
		while (mandelbrot->x < WIDTH)
		{
			calculate_mandelbrot(mandelbrot);
			set_color_mandelbrot(&pixel, mandelbrot->iterations);
			pixel.x = mandelbrot->x;
			pixel.y = mandelbrot->y;
			pixel.color = (pixel.red << 16) | (pixel.green << 8) | pixel.blue;
			put_pixel_image(pixel, image, WIDTH);
			mandelbrot->x++;
		}
		mandelbrot->y++;
	}
}
