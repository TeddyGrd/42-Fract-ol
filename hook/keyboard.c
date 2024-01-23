/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:15 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/23 22:02:18 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int handle_key_press(int keycode, t_fractal *fractal) {
    double zoom_factor = 0.8;
	// printf("%d",keycode);
    // if (keycode == 65362)
	// {
	// 	printf("ici \n");
	// 	zoom(mandelbrot, zoom_factor);
	// }
    // else if (keycode == 65364)
	// {
    //     zoom(mandelbrot, 1.0 / zoom_factor);
	// 	printf("Touche pressée : %d\n", keycode);
	// }
	if(keycode == 65307)
		exit (0);
    return 0;
}