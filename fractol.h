/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/09 16:01:46 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

#define WIDTH 800
#define HEIGHT 800

// int	main(void);
// void	put_pixel_image(t_pixel pixel, char *str, int color);
// int	mandelbrot(double real, double imag);
// int	main_mandelbrot(void);



typedef struct  s_img
{
    void    *img;
    char    *img_str;
    int     bits;
    int     size_line;
    int     endian;
}   t_img;

typedef struct	s_data 
{
	void	*mlx;
	void	*win;
    void    *img;
    char    *data;
    int     width;
    int     height;
}				t_data;

typedef struct s_pixel
{
    int     x;
    int     y;
}	t_pixel;

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

typedef struct	s_fractal
{
    t_complex   min;
    t_complex   max;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	int			max_iter;
	double		c_re;
	double		c_im;
}				t_fractal;

void draw_mandelbrot(void *mlx_ptr, void *win_ptr, t_fractal *mandelbrot);


typedef struct s_color {
    int red;
    int blue;
    int green;
} t_color;

#endif