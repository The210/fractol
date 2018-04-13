/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:21:41 by dhorvill          #+#    #+#             */
/*   Updated: 2018/04/13 16:09:46 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*burning_ship1(void *void_fract)
{
	int		i;
	int		j;
	t_fract *fract;

	fract = (t_fract*)void_fract;
	j = 599 - fract->thread;
	fract->zoom_x = fract->zoom / (fract->BX2 - fract->BX1);
	fract->zoom_y = fract->zoom / (fract->BY2 - fract->BY1);
	while (++j < 800 - fract->thread)
	{
		i = -1;
		fract->c_i = j / fract->zoom_y + fract->BY1;
		while (++i < 800)
		{
			fract->c_r = i / fract->zoom_x + fract->BX1;
			fract->z_r = 0;
			fract->z_i = 0;
			fract->oz_r = 0;
			fract->oz_i = 0;
			fract->k = 0;
			while (fract->oz_r + fract->oz_i <= 4 &&
			fract->k++ < fract->iterations)
			{
				fract->tmp = fract->oz_r - fract->oz_i + fract->c_r;
				fract->z_r = fract->z_r + fract->z_r;
				fract->z_i = fabs(fract->z_r * fract->z_i + fract->c_i);
				fract->z_r = fabs(fract->tmp);
				fract->oz_r = fabs(fract->z_r * fract->z_r);
				fract->oz_i = fabs(fract->z_i * fract->z_i);
			}
			if (fract->k >= fract->iterations)
				fract->img_string[(j - 600 + fract->thread) * 800 + i] = 0;
			else if (fract->k * 100 / fract->iterations < 50)
				fract->img_string[(j - 600 + fract->thread) * 800 + i] =
				draw_color(*fract, 0, fract->k);
			else
				fract->img_string[(j - 600 + fract->thread) * 800 + i] =
				draw_color(*fract, 1, fract->k);
		}
	}
	return (NULL);
}

void	draw_burning_ship_win1(t_fract fract)
{
	t_fract fract1;
	t_fract fract2;
	t_fract fract3;
	t_fract fract4;

	fract1 = fract;
	fract2 = fract;
	fract3 = fract;
	fract4 = fract;
	fract1.thread = 600;
	fract2.thread = 400;
	fract3.thread = 200;
	fract4.thread = 0;
	fract1.img = mlx_new_image(fract.mlx, 800, 200);
	fract1.img_string = (int*)mlx_get_data_addr(fract1.img, &(fract1.bpp), &(fract1.s_l), &(fract1.endian));
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
	pthread_create(&tid1, NULL, burning_ship1, &fract1);
	pthread_create(&tid2, NULL, burning_ship1, &fract2);
	pthread_create(&tid3, NULL, burning_ship1, &fract3);
	pthread_create(&tid4, NULL, burning_ship1, &fract4);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	mlx_put_image_to_window(fract.mlx, fract.win, fract1.img, 0, 0);
	mlx_put_image_to_window(fract.mlx, fract.win, fract2.img, 0, 200);
	mlx_put_image_to_window(fract.mlx, fract.win, fract3.img, 0, 400);
	mlx_put_image_to_window(fract.mlx, fract.win, fract4.img, 0, 600);
}

void	draw_burning_ship_win2(t_fract fract)
{
	t_fract fract1;
	t_fract fract2;
	t_fract fract3;
	t_fract fract4;

	fract1 = fract;
	fract2 = fract;
	fract3 = fract;
	fract4 = fract;
	fract1.thread = 600;
	fract2.thread = 400;
	fract3.thread = 200;
	fract4.thread = 0;
	fract1.img = mlx_new_image(fract.mlx, 800, 200);
	fract1.img_string = (int*)mlx_get_data_addr(fract1.img, &(fract1.bpp), &(fract1.s_l), &(fract1.endian));
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
	pthread_create(&tid1, NULL, burning_ship1, &fract1);
	pthread_create(&tid2, NULL, burning_ship1, &fract2);
	pthread_create(&tid3, NULL, burning_ship1, &fract3);
	pthread_create(&tid4, NULL, burning_ship1, &fract4);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract1.img, 0, 0);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract2.img, 0, 200);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract3.img, 0, 400);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract4.img, 0, 600);
}
