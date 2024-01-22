/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:15 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/22 21:44:27 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


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