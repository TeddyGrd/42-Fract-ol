/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/30 13:55:24 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int fractal(int argc, char* argv[], t_img img)
{
	int	i;
	i = 0;
	if(argc >= 2)
	{
		while(i < argc)
		{
			if (ft_strcmp(argv[1],"mandelbrot") == 0)
			{
				t_fractal mandelbrot;
				initialize_mandelbrot(&mandelbrot);
				draw_mandelbrot(img.img_str, &mandelbrot);
			}
			else if(ft_strcmp(argv[1],"julia") == 0)
			{
				t_fractal julia;
				if(argv[2] && argv[3])
					initialize_julia(&julia,ft_atof(argv[2]),ft_atof(argv[3]));
				else
					initialize_julia(&julia, -0.8, 0.156);
				draw_julia(img.img_str, &julia);
			}
			else 
				if(i == 1)
					error_list(argv[1]);
			i++;
		}
	}
	return(0);
}

int	main(int argc, char* argv[])
{
	t_data data;
	t_img img;
	data.height = HEIGHT;
	data.width = WIDTH;
	if(argc > 1)
	{
    	data.mlx = mlx_init();
    	data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Hello World");
		img.img = mlx_new_image(data.mlx, HEIGHT, WIDTH);
		img.img_str = mlx_get_data_addr(img.img, &img.bits, &img.size_line, &img.endian);
	
		fractal(argc, argv, img);

		mlx_put_image_to_window(data.mlx, data.win,img.img, 0, 0);
		mlx_get_data_addr(img.img,&img.bits ,&img.size_line, &img.endian);
		mlx_mouse_hook(data.win,mouse_zoom, &data);
		mlx_hook(data.win, 33, 0, mouse_close, &data);
		mlx_key_hook(data.win,handle_key_press ,NULL);
    	mlx_do_sync(data.mlx);
		mlx_loop(data.mlx);
		mlx_destroy_image(data.mlx, img.img);
    	return (0);
	}
	else{
		error_command();
		return (0);
	}
}
