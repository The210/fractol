/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:16:53 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/13 16:24:45 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*julia1(void *void_fract)
{
	float tempre;
	float tempim;
	int i;
	int j;
	t_fract *fract;

	fract = (t_fract*)void_fract;
	j = 599 - fract->thread;
	fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
	fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
	while(++j < 800 - fract->thread)
	{
		fract->nz_r = j / fract->zoom_y + fract->JY1;
		i = -1;
		while(++i < 800)
		{
			fract->z_r = i / fract->zoom_x + fract->JX1;
			fract->z_i = fract->nz_r;
			fract->k = 0;
			while(fract->k <= fract->iterations)
			{
				tempre = fract->z_r;
				tempim = fract->z_i;
				fract->z_r = tempre * tempre - tempim * tempim + fract->c_r;
				fract->z_i = 2 * tempre * tempim + fract->c_i;
				fract->k++;
				if(fract->z_r * fract->z_r + fract->z_i * fract->z_i > 4)
					break ;
			}
			if (fract->k >= fract->iterations)
				fract->img_string[(j - 600 + fract->thread) * 800 + i] = 0;
			else if (fract->k * 100 / fract->iterations < 50)
				fract->img_string[(j - 600 + fract->thread) * 800 + i] = draw_color(*fract, 0, fract->k);
			else
				fract->img_string[(j - 600 + fract->thread) * 800 + i] = draw_color(*fract, 1, fract->k);

		}
	}
	return NULL;
}

void	julia_win1(t_fract fract)
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;
	pthread_t tid4;
	t_fract	fract1;
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
	pthread_create(&tid1, NULL, julia1, &fract1);
	pthread_create(&tid2, NULL, julia1, &fract2);
	pthread_create(&tid3, NULL, julia1, &fract3);
	pthread_create(&tid4, NULL, julia1, &fract4);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	mlx_put_image_to_window(fract.mlx, fract.win, fract1.img, 0, 0);
	mlx_put_image_to_window(fract.mlx, fract.win, fract2.img, 0, 200);
	mlx_put_image_to_window(fract.mlx, fract.win, fract3.img, 0, 400);
	mlx_put_image_to_window(fract.mlx, fract.win, fract4.img, 0, 600);
}

void	julia_win2(t_fract fract)
{
	pthread_t tid1;
	pthread_t tid2;
	pthread_t tid3;
	pthread_t tid4;
	t_fract	fract1;
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
	pthread_create(&tid1, NULL, julia1, &fract1);
	pthread_create(&tid2, NULL, julia1, &fract2);
	pthread_create(&tid3, NULL, julia1, &fract3);
	pthread_create(&tid4, NULL, julia1, &fract4);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract1.img, 0, 0);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract2.img, 0, 200);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract3.img, 0, 400);
	mlx_put_image_to_window(fract.mlx, fract.win2, fract4.img, 0, 600);
}
