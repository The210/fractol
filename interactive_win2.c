/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_win2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:08:35 by dhorvill          #+#    #+#             */
/*   Updated: 2018/04/13 16:10:08 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_interactions_win2(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 18)
	{
		fract->zoom = 800;
		fract->zoom_inc = 1;
		fract->X2 = 0.6;
		fract->X1 = -2.1;
		fract->Y1 = -1.2;
		fract->Y2 = 1.2;
		fract->choice2 = 1;
	}
	if (keycode == 19)
	{
		fract->zoom = 800;
		fract->zoom_inc = 1;
		fract->JX1 = -1;
		fract->JX2 = 1;
		fract->JY1 = -1.2;
		fract->JY2 = 1.2;
		fract->choice2 = 2;
	}
	if (keycode == 20)
	{
		fract->zoom = 800;
		fract->zoom_inc = 1;
		fract->BX2 = 1;
		fract->BX1 = -2.5;
		fract->BY1 = -1;
		fract->BY2 = 1;
		fract->choice2 = 3;
	}
	ft_interactions2_win2(keycode, fract);
	return (0);
}

int		ft_interactions2_win2(int keycode, t_fract *fract)
{
	if (keycode == 124)
	{
		if (fract->choice2 == 1)
		{
			fract->X1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->X2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 2)
		{
			fract->JX1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JX2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 3)
		{
			fract->BX1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BX2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 125)
	{
		if (fract->choice2 == 1)
		{
			fract->Y1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->Y2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 2)
		{
			fract->JY1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JY2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 3)
		{
			fract->BY1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BY2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 126)
	{
		if (fract->choice2 == 1)
		{
			fract->Y1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->Y2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 2)
		{
			fract->JY1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JY2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 3)
		{
			fract->BY1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BY2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 123)
	{
		if (fract->choice2 == 1)
		{
			fract->X1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->X2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 2)
		{
			fract->JX1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JX2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice2 == 3)
		{
			fract->BX1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BX2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 69)
		fract->color -= 0.1;
	if (keycode == 78)
		fract->color += 0.1;
	if (keycode == 91)
		fract->iterations += 10;
	if (keycode == 84)
		fract->iterations -= 10;
	if (fract->choice2 == 1)
		draw_mandelbrot_win2(*fract);
	else if (fract->choice2 == 2)
		julia_win2(*fract);
	else if (fract->choice2 == 3)
		draw_burning_ship_win2(*fract);
	return (0);
}
