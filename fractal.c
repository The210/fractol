/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:47:24 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/13 12:37:51 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

float		draw_color(t_fract fract, int a, int i)
{
	float color;

	if (a == 0)
		color =  ((i*255/(fract.iterations*0.75)) * 1000000) +  i*255/(fract.iterations*0.75);
	else
		color =  255000000 +  (i*255/fract.iterations) * 1000; 
	return (color);
}

void	*draw_mandelbrot1(void *void_fract)
{
	int i;
	int j;
	t_fract *fract;

	fract = (t_fract*)void_fract;
	j = 599 - fract->thread;
	fract->zoom_x = fract->zoom / (fract->X2 - fract->X1); 
	fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
	while (++j < 800 - fract->thread)
	{
		i = -1;
		fract->c_i = j / fract->zoom_y + fract->Y1;
		while (++i < 800)
		{
			fract->c_r = i / fract->zoom_x + fract->X1;
			fract->z_r = 0;
			fract->z_i = 0;
			fract->oz_r = 0;
			fract->oz_i = 0;
			fract->k = 0;
			while (fract->oz_r + fract->oz_i <= 4 && fract->k++ < fract->iterations)
			{
				fract->tmp = fract->oz_r - fract->oz_i + fract->c_r;
				fract->z_r = fract->z_r + fract->z_r;
				fract->z_i = fract->z_r * fract->z_i + fract->c_i;
				fract->z_r = fract->tmp;
				fract->oz_r = fract->z_r * fract->z_r;
				fract->oz_i = fract->z_i * fract->z_i;
			}
			if (fract->k >= fract->iterations)
				fract->img_string[(j - 600 + fract->thread) * 800 + i] = 0;
			else if (fract->k * 100 / fract->iterations < 50)
				fract->img_string[(j - 600 + fract->thread) * 800 + i] = draw_color(*fract, 0, fract->k);
			else 
				fract->img_string[(j - 600 + fract->thread)* 800 + i] = draw_color(*fract, 1, fract->k);
		}
	}
	return NULL;
}

void	draw_mandelbrot(t_fract fract)
{
	t_fract fract2;
	t_fract fract3;
	t_fract fract4;

	fract2 = fract;
	fract3 = fract;
	fract4 = fract;
	fract.thread = 600;
	fract2.thread = 400;
	fract3.thread = 200;
	fract4.thread = 0;
	fract2.img = mlx_new_image(fract.mlx, 800, 200);
	fract2.img_string = (int*)mlx_get_data_addr(fract2.img, &(fract2.bpp), &(fract2.s_l), &(fract2.endian));
	fract3.img = mlx_new_image(fract.mlx, 800, 200);
	fract3.img_string = (int*)mlx_get_data_addr(fract3.img, &(fract3.bpp), &(fract3.s_l), &(fract3.endian));
	fract4.img = mlx_new_image(fract.mlx, 800, 200);
	fract4.img_string = (int*)mlx_get_data_addr(fract4.img, &(fract4.bpp), &(fract4.s_l), &(fract4.endian));

	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;
	pthread_t tid4;
	pthread_create(&tid1, NULL, draw_mandelbrot1, &fract);
	pthread_create(&tid2, NULL, draw_mandelbrot1, &fract2);
	pthread_create(&tid3, NULL, draw_mandelbrot1, &fract3);
	pthread_create(&tid4, NULL, draw_mandelbrot1, &fract4);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	mlx_put_image_to_window(fract.mlx, fract.win, fract.img, 0, 0);
	mlx_put_image_to_window(fract.mlx, fract.win, fract2.img, 0, 200);
	mlx_put_image_to_window(fract.mlx, fract.win, fract3.img, 0, 400);
	mlx_put_image_to_window(fract.mlx, fract.win, fract4.img, 0, 600);
}

int		ft_interactions2(int keycode, t_fract *fract)
{
	if (keycode == 124)
	{
		if (fract->choice1 == 1)
		{
			fract->X1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->X2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 2)
		{
			fract->JX1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JX2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 3)
		{
			fract->BX1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BX2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 125)
	{
		if (fract->choice1 == 1)
		{
			fract->Y1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->Y2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 2)
		{
			fract->JY1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JY2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 3)
		{
			fract->BY1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BY2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 126)
	{
		if (fract->choice1 == 1)
		{
			fract->Y1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->Y2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 2)
		{
			fract->JY1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JY2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 3)
		{
			fract->BY1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BY2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 123)
	{
		if (fract->choice1 == 1)
		{
			fract->X1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->X2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 2)
		{
			fract->JX1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->JX2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
		else if (fract->choice1 == 3)
		{
			fract->BX1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
			fract->BX2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		}
	}
	if (keycode == 91)
	{
		fract->iterations += 10;
	}
	if (keycode == 84)
		fract->iterations -= 10;
	if (fract->choice1 == 1)
		draw_mandelbrot(*fract);
	else if (fract->choice1 == 2)
		julia(*fract);
	else if (fract->choice1 == 3)
		draw_burning_ship(*fract);
	return (0);
}

int		ft_interactions(int keycode, t_fract *fract)
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
		fract->choice1 = 1;
	}	
	if (keycode == 19)
	{
		fract->zoom = 800;
		fract->zoom_inc = 1;
		fract->JX1 = -1;
		fract->JX2 = 1;
		fract->JY1 = -1.2;
		fract->JY2 = 1.2;
		fract->choice1 = 2;
	}
	if (keycode == 20)
	{
		fract->zoom = 800;
		fract->zoom_inc = 1;
		fract->BX2 = 1;
		fract->BX1 = -2.5;
		fract->BY1 = -1;
		fract->BY2 = 1;
		fract->choice1 = 3;
	}
	ft_interactions2(keycode, fract);
	return (0);
}



int		main(int argc, char **argv)
{
	t_fract fract;
	t_fract fract2;

	if (argc < 2 || argc > 3)
	{
		ft_putendl("usage: fractol -Mandelbrot -Julia -Burning_ship");
		return(0);
	}
	fract.choice1 = 1;
	if (strcmp( "Mandelbrot", argv[1]) == 0)
		fract.choice1 = 1;
	else if (ft_strcmp("Julia", argv[1]) == 0)
		fract.choice1 = 2;
	else if (ft_strcmp("Burning_ship", argv[1]) == 0)
		fract.choice1 = 3;
	else
	{
		ft_putendl("usage: fractol -Mandelbrot -Julia -Burning_ship");
		return (0);
	}
	fract.c_r = 0.285;
	fract.c_i = 0.01;
	fract.iterations = 70;
	fract.zoom = 800;
	fract.X1 = -2.1;
	fract.julia_change = 1;
	fract.X2 = 0.6;
	fract.zoom_inc = 1;
	fract.Y1 = -1.2;
	fract.Y2 = 1.2;
	fract.JX1 = -1;
	fract.JX2 = 1;
	fract.JY1 = -1.2;
	fract.JY2 = 1.2;
	fract.BX1 = -2.5;
	fract.BX2 = 1;
	fract.BY1 = -1;
	fract.BY2 = 1;
	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, 800, 800, "Fractal_Mandelbrot");
	fract.img = mlx_new_image(fract.mlx, 800, 200);
	fract.img_string = (int*)mlx_get_data_addr(fract.img, &(fract.bpp), &(fract.s_l), &(fract.endian));
	if (fract.choice1 == 1)
		draw_mandelbrot(fract);
	else if (fract.choice1 == 2)
		julia(fract);
	else if (fract.choice1 == 3)
		draw_burning_ship(fract);
	mlx_hook(fract.win,2, (1L << 0), ft_interactions, (void *)&fract);
	mlx_hook(fract.win, 6, (1L << 6), change_julia, (void *)&fract);
	mlx_mouse_hook(fract.win, ft_zoom_mouse, (void *)&fract);
	mlx_loop(fract.mlx);
	return (0);
}
