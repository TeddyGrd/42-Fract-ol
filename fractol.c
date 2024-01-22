/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/22 22:03:55 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char* argv[])
{
	t_data data;
	t_img img;
	t_fractal mandelbrot;
	data.height = HEIGHT;
	data.width = WIDTH;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Hello World");
	initialize_mandelbrot(&mandelbrot);

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
	// img.img_str = mlx_get_data_addr(img.img, &img.bits, &img.size_line,&img.endian);
	mlx_mouse_hook(data.win,mouse_zoom, &data);
	mlx_hook(data.win, 33, 0, mouse_close, &data);
	// display_color(&img, &data);
	// display_image(&data);
    mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
    // sleep(5);
    return (0);
}
