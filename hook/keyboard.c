/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:37:15 by tguerran          #+#    #+#             */
/*   Updated: 2024/02/21 19:46:03 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int handle_key_press(int keycode, t_data *data)
{
	if(keycode == 65307)
	{
		ft_clean(data);
	}
    return 0;
}