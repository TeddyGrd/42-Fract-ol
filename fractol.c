/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/23 22:01:48 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char* argv[])
{
	t_data data;
	t_img img;
	data.height = HEIGHT;
	data.width = WIDTH;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Hello World");
	img.img = mlx_new_image(data.mlx, HEIGHT, WIDTH);
	img.img_str = mlx_get_data_addr(img.img, &img.bits, &img.size_line, &img.endian);
	
	// initialise la fractal ici
	t_fractal julia;
	initialize_julia(&julia);
	draw_julia(img.img_str, &julia);
	// fin de l init
	
	mlx_put_image_to_window(data.mlx, data.win,img.img, 0, 0);
	mlx_get_data_addr(img.img,&img.bits ,&img.size_line, &img.endian);

	mlx_mouse_hook(data.win,mouse_zoom, &data);
	mlx_hook(data.win, 33, 0, mouse_close, &data);
	mlx_key_hook(data.win,handle_key_press ,NULL);
    mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, img.img);
    sleep(5);
    return (0);
}
