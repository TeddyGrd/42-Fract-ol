/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:04:34 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/10 15:06:59 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_image(t_pixel pixel, char *str, int color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int len;

	len = HEIGHT; /* En réalité, il s'agit de la longueur de votre image. Ici, mon image et ma fenêtre font la même taille */

	/* in this part you'll see how i decompose a decimal color in a third part decimal color rgb(255, 255, 255) */
	/* Dans cette partie, voici comment je decompose une couleur decimal en une couleur décimale en trois partie rgb(255, 255, 255) */
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;

	/* (pixel.x * 4) + (len * 4 * pixel.y) : cible le premier bit d'un pixel */
	str[(pixel.x * 4) + (len * 4 * pixel.y)] = b;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 1] = g;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 2] = r;
	str[(pixel.x * 4) + (len * 4 * pixel.y) + 3] = 0;
}

void set_color(t_color *color, int red, int green, int blue)
{
    color->red = red;
    color->green = green;
    color->blue = blue;
}

void draw_mandelbrot(void *mlx_ptr, void *win_ptr, t_fractal *mandelbrot) {
    int x, y;
    t_complex c, z, tmp;
    int iterations;
    t_color color;
    t_pixel pixel;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Cartographier les coordonnées de la fenêtre à l'ensemble de Mandelbrot
            c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            c.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            // Initialiser z à (0, 0)
            z.real = 0.0;
            z.imag = 0.0;

            iterations = 0;

            // Appliquer l'algorithme de Mandelbrot
            while (iterations < 1000 && (z.real * z.real + z.imag * z.imag) < 4.0) {
                tmp.real = z.real * z.real - z.imag * z.imag + c.real;
                tmp.imag = 2 * z.real * z.imag + c.imag;
                z = tmp;
                iterations++;
            }

            // Coloration en fonction du nombre d'itérations
            set_color(&color, (iterations) % 256, (iterations *2) % 256,(iterations * 4) % 256);
            put_pixel_image(pixel, win_ptr, (color.red << 16) | (color.green << 8) | (color.blue));
        }
    }
}