/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:26 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/15 16:43:06 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int checkerror(int argc, char *argv[])
{
	if (argc <= 1 || argc > 4)
	{
		error_command();
		return (0);
	}
	else if ((ft_strcmp(argv[1], "mandelbrot") != 0) && (ft_strcmp(argv[1], "julia") != 0))
	{
		error_list(argv[1]);
		return (0);
	}
	else if (argv[2])
	{
		if (ft_isdigit(atof(argv[2])) == 1)
		{
			error_list(argv[2]);
			return (0);
		}
		if (argv[3])
		{
			if (ft_isdigit(atof(argv[3])) == 1)
			{
				error_list(argv[3]);
				return (0);
			}
		}
	}
	return (1);
}

void error_command(void)
{
	ft_printf("----RAPPEL DES COMMANDES---- \n");
	ft_printf(" | | | | | | | | | | | | | | \n");
	ft_printf("-mandelbrot \n");
	ft_printf("-julia \n");
	ft_printf("-julia (param1) (param2)\n");
	ft_printf(" | | | | | | | | | | | | | | \n");
}

void error_list(char *str)
{
	ft_printf(" | | | | | | | | | | | | | | \n");
	ft_printf("---- %s N'EST PAS RECONNU ----\n", str);
	ft_printf(" | | | | | | | | | | | | | | \n");
	error_command();
}