/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/20 03:29:27 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int fractal(int argc, char *argv[], t_data *data, t_fractal *fractalchaine)
{
	printf(" %f 2\n", fractalchaine->zoom);
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	data->img_str = mlx_get_data_addr(data->img, &data->bits, &data->size_line, &data->endian);
	drawfractal(argc,argv, data,fractalchaine);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_get_data_addr(data->img, &data->bits, &data->size_line, &data->endian);
	mlx_mouse_hook(data->win, mouse_zoom, fractalchaine);
	mlx_hook(data->win, 33, 0, mouse_close, data);
	mlx_key_hook(data->win, handle_key_press, NULL);
	mlx_do_sync(data->mlx);
	mlx_loop(data->mlx);
	return (0);
}

void drawfractal(int argc, char *argv[], t_data *data,t_fractal *fractalchaine)
{
	t_fractal fractal;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		{
			initialize_mandelbrot(&fractal, data,fractalchaine);
			draw_mandelbrot(data->img_str, &fractal);
		}
	else if (ft_strcmp(argv[1], "julia") == 0)
		{
			if (argv[2] && argv[3])
				initialize_julia(&fractal, ft_atof(argv[2]), ft_atof(argv[3]));
			else
				initialize_julia(&fractal, -0.8, 0.156);
			draw_julia(data->img_str, &fractal, data,fractalchaine);
		}
}

int main(int argc, char *argv[])
{
	t_data data;
	t_fractal fractalchaine;

	fractalchaine.zoom = 1.0;
	data.height = 5;
	if (checkerror(argc, argv) == 0)
		return (0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "Fractal");
	fractal(argc, argv ,&data,&fractalchaine);
}
