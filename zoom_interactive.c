/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_interactive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:17:22 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/13 12:38:20 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void	ft_move_to_corner(t_fract *fract, int x, int y, int a)
{
	if (a == 1)
	{
		fract->zoom_x = fract->zoom / (fract->X2 - fract->X1);
		fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
		fract->X1 += x / fract->zoom_x;
		fract->X2 += x / fract->zoom_x;
		fract->Y1 += y / fract->zoom_y;
		fract->Y2 += y / fract->zoom_y;
	}
	else if (a == 2)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->JX1 += x / fract->zoom_x;
		fract->JX2 += x / fract->zoom_x;
		fract->JY1 += y / fract->zoom_y;
		fract->JY2 += y / fract->zoom_y;
	}
	else if (a == 3)
	{
		fract->zoom_x = fract->zoom / (fract->BX2 - fract->BX1);
		fract->zoom_y = fract->zoom / (fract->BY2 - fract->BY1);
		fract->BX1 += x / fract->zoom_x;
		fract->BX2 += x / fract->zoom_x;
		fract->BY1 += y / fract->zoom_y;
		fract->BY2 += y / fract->zoom_y;
	}
}

void	ft_move_from_corner(t_fract *fract, int x, int y, int a)
{
	if (a == 1)
	{
		fract->zoom_x = fract->zoom / (fract->X2 - fract->X1);
		fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
		fract->X1 -= x / fract->zoom_x;
		fract->X2 -= x / fract->zoom_x;
		fract->Y1 -= y / fract->zoom_y;
		fract->Y2 -= y / fract->zoom_y;
	}
	else if (a == 2)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->JX1 -= x / fract->zoom_x;
		fract->JX2 -= x / fract->zoom_x;
		fract->JY1 -= y / fract->zoom_y;
		fract->JY2 -= y / fract->zoom_y;
	}
	else if (a == 3)
	{
		fract->zoom_x = fract->zoom / (fract->BX2 - fract->BX1);
		fract->zoom_y = fract->zoom / (fract->BY2 - fract->BY1);
		fract->BX1 -= x / fract->zoom_x;
		fract->BX2 -= x / fract->zoom_x;
		fract->BY1 -= y / fract->zoom_y;
		fract->BY2 -= y / fract->zoom_y;
	}
}

int		change_julia(int x, int y, t_fract *fract)
{
	if (fract->julia_change == 0)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->c_r = fract->JX1 + x / fract->zoom_x;
		fract->c_i = fract->JY1 + y / fract->zoom_y;
	}
		if (fract->choice1 == 2)
			julia(*fract);
	return (0);
}

int		ft_zoom_mouse(int button, int x, int y, t_fract *fract)
{
	if (button == 5)
	{
		ft_move_to_corner(fract, x, y, fract->choice1);
		fract->zoom += 40 * fract->zoom_inc;
		fract->zoom_inc *= 1.2;
		ft_move_from_corner(fract, x, y, fract->choice1);
	}
	if (button == 4)
	{
		ft_move_to_corner(fract, x, y, fract->choice1);
		fract->zoom_inc /= 1.2;
		fract->zoom -= 40 * fract->zoom_inc;
		ft_move_from_corner(fract, x, y, fract->choice1);
	}
	if (button == 1 && fract->choice1 == 2)
		fract->julia_change = fract->julia_change == 1 ? 0 : 1;
	if (fract->choice1 == 1)
		draw_mandelbrot(*fract);
	else if (fract->choice1 == 2)
		julia(*fract);
	else if (fract->choice1 == 3)
		draw_burning_ship(*fract);
	return (0);
}
