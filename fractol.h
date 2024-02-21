/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:30:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:44 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

#define WIDTH 800
#define HEIGHT 800


typedef struct s_data
{
	void *mlx;
	void *win;
	char *data;
	void *img;
	char *img_str;
	int bits;
	int size_line;
	int endian;
	double zoom;
	int	fractal;
	double param1;
	double param2;
} t_data;

typedef struct s_pixel
{
	int x;
	int y;
	int color;
	int red;
	int blue;
	int green;
} t_pixel;

typedef struct s_complex
{
	double real;
	double imag;
} t_complex;

typedef struct s_fractal
{
	t_complex min;
	t_complex max;
	t_complex constant;
} t_fractal;

void	screen_init(t_data *data);
void	put_pixel_image(t_pixel pixel, char *str, int len);
void    initialize_mandelbrot(t_fractal *mandelbrot, t_data *data);
void	set_color_mandelbrot(t_pixel *color, int iterations);
void    draw_mandelbrot(char *image, t_fractal *mandelbrot);
void	initialize_julia(t_fractal *julia, double param1, double param2);
void	set_color_julia(t_pixel *color, int iterations);
void	draw_julia(char *image, t_fractal *julia, t_data *data);
int		mouse_close(t_data *data);
int		mouse_zoom(int mousecode,int x , int y, t_data *data);
int		handle_key_press(int keycode, t_data *data);
double	ft_atof(const char *nptr);
void	error_list(char *str);
int		checkerror(int argc, char *argv[]);
int		ft_strcmp(const char *s1, const char *s2);
void	error_command(void);
void	drawfractal(int argc, char *argv[], t_data *data);
int		ft_clean(t_data *data);



#endif