/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:54:25 by abekri            #+#    #+#             */
/*   Updated: 2024/06/08 02:58:30 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(double xd, double yd, void *param)
{
	t_mandel	*m;
	double		zoom_factor;
	double		x_range;
	double		y_range;

	(void)xd;
	m = (t_mandel *)param;
	x_range = m->xmax - m->xmin;
	y_range = m->ymax - m->ymin;
	zoom_factor = 0.1;
	if (yd < 0)
	{
		m->xmin -= x_range * zoom_factor;
		m->xmax += x_range * zoom_factor;
		m->ymin -= y_range * zoom_factor;
		m->ymax += y_range * zoom_factor;
	}
	else if (yd > 0)
	{
		m->xmin += x_range * zoom_factor;
		m->xmax -= x_range * zoom_factor;
		m->ymin += y_range * zoom_factor;
		m->ymax -= y_range * zoom_factor;
	}
	m->should_draw = 1;
}

static void	key_hook_esc(int key, t_mandel *m)
{
	if (key == MLX_KEY_ESCAPE)
	{
		if (m->image)
			mlx_delete_image(m->mlx_ptr, m->image);
		if (m->mlx_ptr)
			mlx_terminate(m->mlx_ptr);
		free(m);
		exit(EXIT_SUCCESS);
	}
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_mandel	*m;
	double		move;

	m = (t_mandel *)param;
	move = (m->ymax - m->ymin) * 0.1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		m->xmin += move;
		m->xmax += move;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		m->xmin -= move;
		m->xmax -= move;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		m->ymin += move;
		m->ymax += move;
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		up(m);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		key_hook_esc(MLX_KEY_ESCAPE, m);
	m->should_draw = 1;
}
