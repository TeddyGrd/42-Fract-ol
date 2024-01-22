/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:47:49 by tguerran          #+#    #+#             */
/*   Updated: 2024/01/22 21:56:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_close(int mousecode, t_data *data)
{
	if(mousecode != 0)
		exit (0);
}

int	mouse_zoom(int mousecode, t_data *data)
{
	printf(" %d \n", mousecode);
	if(mousecode == 4)
	{
		printf("Je zoom");
	}
	if(mousecode == 5)
	{
		printf("je dezoome");
	}
}