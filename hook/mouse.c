/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:47:49 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/20 03:28:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_close(int mousecode, t_data *data)
{
	if(mousecode != 0)
		exit (0);
}

int	mouse_zoom(int mousecode,int x, int y, t_fractal *fractalchaine, t_data *data)
{
	double zoom = fractalchaine->zoom;
	printf("%f \n", fractalchaine->zoom);
	printf("%d \n", data->height);
	if(mousecode == 4)
	{
		printf("Je zoom\n");
		fractalchaine->zoom *= 1.2;
		// mlx_destroy_image(data->mlx, data->img_str);
	}
	if(mousecode == 5)
	{
		printf("je dezoome \n");
		fractalchaine->zoom /= 1.2;

	}
}