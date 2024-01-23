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

void put_pixel_image(t_pixel pixel, char *str, int len) {
    unsigned char r, g, b;

    r = (pixel.color >> 16) & 0xff;
    g = (pixel.color >> 8) & 0xff;
    b = pixel.color & 0xff;

    str[(pixel.x * 4) + (len * 4 * pixel.y)] = b;
    str[(pixel.x * 4) + (len * 4 * pixel.y) + 1] = g;
    str[(pixel.x * 4) + (len * 4 * pixel.y) + 2] = r;
    str[(pixel.x * 4) + (len * 4 * pixel.y) + 3] = 0;
}

void set_color(t_color *color, int iterations) {
    if (iterations == 1000) {
        color->red = 0;
        color->green = 0;
        color->blue = 0;
    } else {
        color->red = (sin(0.05 * iterations) + 1.0) * 128;
        color->green = (sin(0.1 * iterations) + 1.0) * 128;
        color->blue = (sin(0.15 * iterations) + 1.0) * 128;
    }
}

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

            set_color(&color,iterations);

            pixel.x = x;
            pixel.y = y;
            pixel.color = (color.red << 16) | (color.green << 8) | color.blue;

            put_pixel_image(pixel, image, WIDTH);
            x++;
        }
        y++;
    }
}

// int main() {
// 	int bits_per_pixel;
//     int size_line;
//     int endian;
//     void *mlx_ptr = mlx_init();
//     void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

//     char *image = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
//     char *image_data = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);

//     t_fractal mandelbrot;
//     initialize_mandelbrot(&mandelbrot);

//     draw_mandelbrot(image_data, &mandelbrot);

//     mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
//     mlx_loop(mlx_ptr);
// 	mlx_destroy_image(mlx_ptr, image);
//     return 0;
// }