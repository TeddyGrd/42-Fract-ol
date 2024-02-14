/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:03:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/13 18:41:00 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void initialize_julia(t_fractal *julia, double param1, double param2)
{
	if (param1 && param2)
	{
		julia->constant.real = param1;
		julia->constant.imag = param2;
	}
	else
	{
		param1 = -0.8;
		param2 = 0.156;
		julia->constant.real = param1;
		julia->constant.imag = param2;
	}
}

void draw_julia(char *image, t_fractal *julia)
{
	int x = 0, y = 0;
	t_complex z, tmp;
	int iterations;
	t_color color;
	t_pixel pixel;
	t_fractal fractalchaine;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.real = (x - WIDTH / 2) * (3.0 + fractalchaine.zoom) / WIDTH;
			z.imag = (y - HEIGHT / 2) * (3.0 + fractalchaine.zoom) / HEIGHT;

			iterations = 0;

			while (iterations < 1000)
			{
				tmp.real = z.real * z.real - z.imag * z.imag + julia->constant.real;
				tmp.imag = 2 * z.real * z.imag + julia->constant.imag;
				z = tmp;
				iterations++;

				if (z.real * z.real + z.imag * z.imag > 4.0)
				{
					break;
				}
			}

			set_color_julia(&color, iterations);

			pixel.x = x;
			pixel.y = y;
			pixel.color = (color.red << 16) | (color.green << 8) | color.blue;

			put_pixel_image(pixel, image, WIDTH);

			x++;
		}
		y++;
	}
}
