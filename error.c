/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:26 by tguerran          #+#    #+#             */
/*   Updated: 2024/03/11 16:05:35 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checkerror_2(char *argv[])
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argv[2] != NULL) {
			error_list("mandelbrot ne prend pas de paramètres supplémentaires.");
			return (0);
		}
	} 
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argv[2] == NULL || argv[3] == NULL)
		{
			error_list("julia nécessite deux paramètres supplémentaires.");
			return (0);
		}
		if (ft_isalpha(argv[2][0]) == 1 || ft_isalpha(argv[3][0]) == 1)
		{
			error_list("Les paramètres pour julia doivent être des nombres valides.");
			return (0);
		}
	}
	else
	{
		error_list("Argument non reconnu.");
		return (0);
    }
    return (1);
}

int	checkerror(int argc, char *argv[])
{
	if (argc <= 1 || argc > 4)
	{
		error_command();
		return (0);
	}
	if (checkerror_2(argv) == 0)
	{
		return (0);
	}
	return (1);
}

void	error_command(void)
{
	ft_printf("----RAPPEL DES COMMANDES---- \n");
	ft_printf(" | | | | | | | | | | | | | | \n");
	ft_printf("-mandelbrot \n");
	ft_printf("-julia (param1) (param2)\n");
	ft_printf(" | | | | | | | | | | | | | | \n");
}

void	error_list(char *str)
{
	ft_printf(" | | | | | | | | | | | | | | \n");
	ft_printf("---- %s ----\n", str);
	ft_printf(" | | | | | | | | | | | | | | \n");
	error_command();
}
