/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:26 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:29 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error_command(){
    ft_printf("rappel des commandes \n");
    ft_printf("-mandelbrot \n");
    ft_printf("-julia \n");
    ft_printf("-julia (param1) (param2)\n");    
}

void error_list(char *str)
{
    ft_printf("%s n est pas reconnu \n",str);
    error_command();
}