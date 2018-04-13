/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:47 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/13 16:08:26 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
	void	*mlx2;
	void	*win;
	void	*win2;
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
	float	color;
}				t_fract;

int		change_julia(int x, int y, t_fract *fract);
void	draw_mandelbrot_win1(t_fract fract);
void	draw_mandelbrot_win2(t_fract fract);
void	julia_win1(t_fract fract);
void	julia_win2(t_fract fract);
float	draw_color(t_fract fract, int a, int i);
int		ft_loop_julia(t_fract *fract);
void	*burning_ship(void *void_fract);
void	draw_burning_ship_win1(t_fract fract);
void	draw_burning_ship_win2(t_fract fract);
int		ft_zoom_mouse(int button, int x, int y, t_fract *fract);
int		ft_interactions(int keycode, t_fract *fract);
int		ft_interactions_win2(int keycode, t_fract *fract);
int		ft_interactions2(int keycode, t_fract *fract);
int		ft_interactions2_win2(int keycode, t_fract *fract);
int		change_julia(int x, int y, t_fract *fract);
int		change_julia_win2(int x, int y, t_fract *fract);
int		ft_zoom_mouse(int button, int x, int y, t_fract *fract);
int		ft_zoom_mouse_win2(int button, int x, int y, t_fract *fract);
void	ft_move_to_corner(t_fract *fract, int x, int y, int a);
void	ft_move_from_corner(t_fract *fract, int, int y, int a);


#endif
