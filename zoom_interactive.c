/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_interactive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:17:22 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/03 14:43:03 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

int		ft_zoom_mouse(int button, int x, int y, t_fract *fract)
{
	/*if (button == 5)
	{
		fract->zoom += 40 * fract->zoom_inc;
		fract->zoom_inc *= 1.2;
		fract->X1 += (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (x - 100);
		fract->X2 += (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (x - 100);
		fract->Y1 += (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (y - 100);
		fract->Y2 += (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (y - 100);
	}
	if (button == 4)
	{	
		fract->X1 -= (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (x - 100);
		fract->X2 -= (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (x - 100);
		fract->Y1 -= (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (y - 100);
		fract->Y2 -= (0.001 / pow(sqrt(fract->zoom_inc), 1.7)) * (y - 100);
		fract->zoom_inc /= 1.2;
		fract->zoom -= 40 * fract->zoom_inc;
	}*/
	ft_putnbr(button);
	if (button == 5)
	{
		fract->zoom += fract->zoom_inc;
		fract->zoom_inc *= 1.2;
	}
	if (button == 4)
	{
		fract->zoom_inc /= 1.2;
		fract->zoom -= fract->zoom_inc;
	}
	mlx_destroy_image(fract->mlx, fract->img);
	fract->img = mlx_new_image(fract->mlx, 1000, 1000);
	fract->img_string = (int*)mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->s_l), &(fract->endian));

	mlx_clear_window(fract->mlx, fract->win);
	julia(*fract);
	return (0);
}

