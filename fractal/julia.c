/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:03:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/23 16:02:47 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	initialize_julia(t_fractal *julia, double param1, double param2)
{
	julia->x = 0;
	julia->y = 0;
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

void	calculate_julia(t_fractal *julia, t_data *data)
{
	t_complex	z;
	t_complex	tmp;

	z.real = (julia->x - WIDTH / 2) * (2.0 / data->zoom) / WIDTH;
	z.imag = (julia->y - HEIGHT / 2) * (2.0 / data->zoom) / HEIGHT;
	julia->iterations = 0;
	while (julia->iterations < 1000)
	{
		tmp.real = z.real * z.real - z.imag
			* z.imag + julia->constant.real;
		tmp.imag = 2 * z.real * z.imag + julia->constant.imag;
		z = tmp;
		julia->iterations++;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			break ;
	}
}

void	draw_julia(char *image, t_fractal *julia, t_data *data)
{
	t_pixel		pixel;

	while (julia->y < HEIGHT)
	{
		julia->x = 0;
		while (julia->x < WIDTH)
		{
			calculate_julia(julia, data);
			set_color_julia(&pixel, julia->iterations);
			pixel.x = julia->x;
			pixel.y = julia->y;
			pixel.color = (pixel.red << 16) | (pixel.green << 8) | pixel.blue;
			put_pixel_image(pixel, image, WIDTH);
			julia->x++;
		}
		julia->y++;
	}
}
