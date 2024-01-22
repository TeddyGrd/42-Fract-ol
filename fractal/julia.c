/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:03:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/09 15:43:15 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		double factor = 0.1;
		color->red = (sin(factor * iterations) + 1.0) * 128;
        color->green = (sin(factor * iterations + 2.0) + 1.0) * 128;
        color->blue = (sin(factor * iterations + 4.0) + 1.0) * 128;

        color->red += (sin(0.1 * iterations) + 1.0) * 128;
        color->green += (sin(0.2 * iterations) + 1.0) * 128;
        color->blue += (sin(0.3 * iterations) + 1.0) * 128;
    }
}


void draw_julia(char *image, t_fractal *julia) {
    int x = 0, y = 0;
    t_complex z, tmp;
    int iterations;
    t_color color;
    t_pixel pixel;

    while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            z.real = (x - WIDTH / 2) * 3.0 / WIDTH;
            z.imag = (y - HEIGHT / 2) * 3.0 / HEIGHT;

            iterations = 0;

            while (iterations < 1000) {
                tmp.real = z.real * z.real - z.imag * z.imag + julia->constant.real;
                tmp.imag = 2 * z.real * z.imag + julia->constant.imag;
                z = tmp;
                iterations++;

                if (z.real * z.real + z.imag * z.imag > 4.0) {
                    break;
                }
            }

			set_color(&color, iterations);

            pixel.x = x;
            pixel.y = y;
            pixel.color = (color.red << 16) | (color.green << 8) | color.blue;

            put_pixel_image(pixel, image, WIDTH);

            x++;
        }
        y++;
    }
}

int main() {
	int bits_per_pixel;
	int size_line;
	int endian;
    void *mlx_ptr = mlx_init();
    void *win1 = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Julia Set");

    char *image1 = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
    char *image_data1 = mlx_get_data_addr(image1, &bits_per_pixel, &size_line, &endian);

    t_fractal julia;
    julia.constant.real = -0.8;
    julia.constant.imag = 0.156;

	draw_julia(image_data1, &julia);
	mlx_put_image_to_window(mlx_ptr, win1, image1, 0, 0);
	mlx_do_sync(mlx_ptr);

    mlx_loop(mlx_ptr);

    mlx_destroy_image(mlx_ptr, image1);

    return (0);
}
