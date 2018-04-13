/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:47 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/13 12:35:45 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

typedef struct s_fract
{
	float	c_r;
	float	c_r1;
	float	c_r2;
	float	c_r3;
	float	c_i;
	float	c_i1;
	float	c_i2;
	float	c_i3;
	float	nz_r;
	float	z_r;
	float	oz_r;
	float	z_i;
	float	oz_i;
	int		k;
	int		mousex;
	int		mousey;
	float	zoom;
	float	zoom_inc;
	float	zoom_x;
	float	zoom_y;
	float	tmp;
	int		bpp;
	int		s_l;
	int		endian;
	float	iterations;
	float	X1;
	float	X2;
	float	Y1;
	float	Y2;
	float	JX1;
	float	JX2;
	float	JY1;
	float	JY2;
	float	BX1;
	float	BX2;
	float	BY1;
	float	BY2;
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_string;
	void	*img2;
	int		*img_string2;
	float	distx;
	float	disty;
	float	deltai;
	float	deltaj;
	int		julia_change;
	int		thread;
	int 	choice1;
	int		choice2;
}				t_fract;

int		change_julia(int x, int y, t_fract *fract);
void	draw_mandelbrot(t_fract fract);
void	julia(t_fract fract);
float	draw_color(t_fract fract, int a, int i);
int		ft_loop_julia(t_fract *fract);
void	*burning_ship(void *void_fract);
void	draw_burning_ship(t_fract fract);
int		ft_zoom_mouse(int button, int x, int y, t_fract *fract);

#endif
