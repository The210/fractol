/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_interactive_win2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:23:56 by dhorvill          #+#    #+#             */
/*   Updated: 2018/04/13 16:10:23 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		change_julia_win2(int x, int y, t_fract *fract)
{
	if (fract->julia_change == 0)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->c_r = fract->JX1 + x / fract->zoom_x;
		fract->c_i = fract->JY1 + y / fract->zoom_y;
	}
	if (fract->choice2 == 2)
		julia_win2(*fract);
	return (0);
}

int		ft_zoom_mouse_win2(int button, int x, int y, t_fract *fract)
{
	if (button == 5)
	{
		ft_move_to_corner(fract, x, y, fract->choice2);
		fract->zoom += 40 * fract->zoom_inc;
		fract->zoom_inc *= 1.2;
		ft_move_from_corner(fract, x, y, fract->choice2);
	}
	if (button == 4)
	{
		ft_move_to_corner(fract, x, y, fract->choice2);
		fract->zoom_inc /= 1.2;
		fract->zoom -= 40 * fract->zoom_inc;
		ft_move_from_corner(fract, x, y, fract->choice2);
	}
	if (button == 1 && fract->choice2 == 2)
		fract->julia_change = fract->julia_change == 1 ? 0 : 1;
	if (fract->choice2 == 1)
		draw_mandelbrot_win2(*fract);
	else if (fract->choice2 == 2)
		julia_win2(*fract);
	else if (fract->choice2 == 3)
		draw_burning_ship_win2(*fract);
	return (0);
}
