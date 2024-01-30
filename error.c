/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:26 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/27 09:39:43 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error_command(){
    ft_printf("----RAPPEL DES COMMANDES---- \n" );
    ft_printf(" | | | | | | | | | | | | | | \n");
    ft_printf("-mandelbrot \n");
    ft_printf("-julia \n");
    ft_printf("-julia (param1) (param2)\n");
    ft_printf(" | | | | | | | | | | | | | | \n" );   
}

void error_list(char *str)
{
    ft_printf("---- %s N'EST PAS RECONNU ----\n",str);
    ft_printf(" | | | | | | | | | | | | | | \n" );
    error_command();
}