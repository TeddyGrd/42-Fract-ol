/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/10 15:39:27 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	mouse_close(int mousecode, t_data *data)
{
	if(mousecode != 0)
		exit (0);
}

int	mouse_move(int mousecode, t_data *data)
{
	printf(" %d \n", mousecode);
	if(mousecode == 4)
	{
		printf("Je zoom");
	}
	if(mousecode == 5)
	{
		printf("je dezoome");
	}

}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_str + (y * img->size_line + x * (img->bits / 8));
	*(unsigned int*)dst = color;
}

void	initialize_mandelbrot(t_fractal *mandelbrot)
{
    mandelbrot->min.real = -2.0;
    mandelbrot->min.imag = -1.5;
    mandelbrot->max.real = 2.0;
    mandelbrot->max.imag = 1.5;
}

void	zoom(t_fractal *mandelbrot, double factor)
{
    double width = mandelbrot->max.real - mandelbrot->min.real;
    double height = mandelbrot->max.imag - mandelbrot->min.imag;

    mandelbrot->min.real += width * (1-factor) / 2;
    mandelbrot->max.real -= width * (1-factor) / 2;
    mandelbrot->min.imag += height * (1-factor) / 2;
    mandelbrot->min.imag -= height * (1-factor) / 2;

}

int handle_key_press(int keycode, t_fractal *mandelbrot) {
    double zoom_factor = 0.8; 
    if (keycode == 65362)
	{
		printf("ici \n");
		zoom(mandelbrot, zoom_factor);
	}
    else if (keycode == 65364)
	{
        zoom(mandelbrot, 1.0 / zoom_factor);
		printf("Touche pressée : %d\n", keycode);
	}
	else if(keycode == 65307)
		exit (0);
    return 0;
}

int	main(void)
{
	t_data data;
	t_img img;
	t_fractal mandelbrot;
	initialize_mandelbrot(&mandelbrot);
	data.height = HEIGHT;
	data.width = WIDTH;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Hello World");
	mlx_hook(data.win, 2, 1L<< 0, (int (*)())handle_key_press, &mandelbrot); // Gestion des événements clavier
	// draw_mandelbrot(data.mlx,data.win, &mandelbrot);

	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.img_str = mlx_get_data_addr(img.img,img.bits ,img.size_line, img.endian);
	mlx_put_image_to_window(data.mlx, data.win,img.img, 0, 0);
	// data.img = mlx_xpm_file_to_image(data.mlx, relative_path, &data.width, &data.height );
	// printf("%s \n", data.img);
	// if(!data.img)
	// {
	// 	printf("erreur chargement image \n");
	// 	return (1);
	// }
	// img.img = mlx_new_image(data.mlx, 500, 500);
	// img.img_str = mlx_get_data_addr(img.img, &img.bits, &img.size_line,&img.endian);
	mlx_mouse_hook(data.win,mouse_move, &data);
	mlx_hook(data.win, 33, 0, mouse_close, &data);
	// display_color(&img, &data);
	// display_image(&data);
    // mlx_hook(data.win, 2,  1L<<0, (int (*)())key_press_hook, &data);
    mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
    // sleep(5);
    return (0);
}
