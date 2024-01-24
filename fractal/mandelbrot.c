/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:04:34 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/23 19:41:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


void    initialize_mandelbrot(t_fractal *mandelbrot)
{
    mandelbrot->min.real = -2.0;
    mandelbrot->min.imag = -2;
    mandelbrot->max.real = 2.0;
    mandelbrot->max.imag = 2;
}

void    draw_mandelbrot(char *image, t_fractal *mandelbrot) {
    int x = 0, y = 0;
    t_complex c, z, tmp;
    int iterations;
    t_color color;
    t_pixel pixel;

    while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            c.real = mandelbrot->min.real + (x / (double)WIDTH) * (mandelbrot->max.real - mandelbrot->min.real);
            c.imag = mandelbrot->min.imag + (y / (double)HEIGHT) * (mandelbrot->max.imag - mandelbrot->min.imag);

            z.real = 0.0;
            z.imag = 0.0;

            iterations = 0;

            while (iterations < 1000 && (z.real * z.real + z.imag * z.imag) < 4.0) {
                tmp.real = z.real * z.real - z.imag * z.imag + c.real;
                tmp.imag = 2 * z.real * z.imag + c.imag;
                z = tmp;
                iterations++;
            }

            set_color_mandelbrot(&color,iterations);

            pixel.x = x;
            pixel.y = y;
            pixel.color = (color.red << 16) | (color.green << 8) | color.blue;

            put_pixel_image(pixel, image, WIDTH);
            x++;
        }
        y++;
    }
}