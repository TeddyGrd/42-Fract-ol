/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:38:18 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/22 18:15:30 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int n;
    n = ft_strlen(s1);
    while (n > 0 && *s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
        n--;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

double ft_atof(const char *nptr)
{
    double val = 0.0;
    int sign = 1;
    int decimal = 0;
    while (*nptr == ' ')
        nptr++;
    if (*nptr == '-')
    {
        sign = -1;
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        val = val * 10.0 + (*nptr++ - '0');
        if (decimal)
            decimal++;
    }
    if (*nptr == '.')
    {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9')
        {
            val = val + ((*nptr++ - '0') / pow(10, decimal));
            decimal++;
        }
    }
    return sign * val;
}


void ft_clean(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}