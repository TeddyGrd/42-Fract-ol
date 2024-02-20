/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:47:49 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/20 16:11:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void drawfractal_zoom(t_data *data)
{
	t_fractal fractal;

	if(data->fractal == 0)
	{
		initialize_mandelbrot(&fractal, data);
		draw_mandelbrot(data->img_str, &fractal);
	}
	if(data->fractal == 1)
	{
		if(data->fractal)
			initialize_julia(&fractal, data->param1, data->param2);
		else
			initialize_julia(&fractal, -0.8, 0.156);
	draw_julia(data->img_str, &fractal, data);
	}
}

int	mouse_close(int mousecode, t_data *data)
{
	if(mousecode != 0)
		exit (0);
}

int	mouse_zoom(int mousecode,int x, int y, t_data *data)
{
	double zoom = data->zoom;
	printf("%f \n", data->zoom);
	if(mousecode == 4)
	{
		printf("Je zoom\n");
		data->zoom *= 1.2;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		data->img_str = mlx_get_data_addr(data->img, &data->bits, &data->size_line, &data->endian);
		drawfractal_zoom(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_get_data_addr(data->img, &data->bits, &data->size_line, &data->endian);
	}
	if(mousecode == 5)
	{
		printf("je dezoome \n");
		data->zoom /= 1.2;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
		data->img_str = mlx_get_data_addr(data->img, &data->bits, &data->size_line, &data->endian);
		drawfractal_zoom(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_get_data_addr(data->img, &data->bits, &data->size_line, &data->endian);
	}
}