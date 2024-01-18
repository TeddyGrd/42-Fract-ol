/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:03:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/09 15:43:15 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

int		julia_iterations(double x, double y, t_fractal *fractal)
{
	double	real = x;
	double	imag = y;
	double	temp;
	int		iterations = 0;

	while (iterations < fractal->max_iter)
	{
		temp = real * real - imag * imag + fractal->c_re;
		imag = 2 * real * imag + fractal->c_im;
		real = temp;
		if (real * real + imag * imag > 4)
			break ;
		iterations++;
	}
	return (iterations);
}

int		color(int iterations, int max_iter)
{
	if (iterations == max_iter)
		return (0xFFFFFF); // couleur du fond
	return (iterations * 255 / max_iter); // exemple de couleur basée sur le nombre d'itérations
}

void	draw_fractal(t_mlx *mlx, t_fractal *fractal)
{
	int		x;
	int		y;
	int		iterations;
	int		color_val;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iterations = julia_iterations(
				fractal->min_x + (x / (double)WIDTH) * (fractal->max_x - fractal->min_x),
				fractal->min_y + (y / (double)HEIGHT) * (fractal->max_y - fractal->min_y),
				fractal
			);
			color_val = color(iterations, fractal->max_iter);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color_val);
			x++;
		}
		y++;
	}
}

int		main(void)
{
	t_mlx		mlx;
	t_fractal	fractal;

	fractal.min_x = -2.0;
	fractal.max_x = 2.0;
	fractal.min_y = -2.0;
	fractal.max_y = 2.0;
	fractal.max_iter = 1000;
	fractal.c_re = -0.7; // modifier ces valeurs pour changer la fractale de Julia
	fractal.c_im = 0.27015;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Fractal Julia");

	draw_fractal(&mlx, &fractal);

	mlx_loop(mlx.mlx_ptr);

	return (0);
}
