/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:17:46 by abekri            #+#    #+#             */
/*   Updated: 2024/06/08 03:26:44 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_start(t_mandel *m, int x, int y)
{
	m->r = m->xmin + (double)x / m->image->width * (m->xmax - m->xmin);
	m->i = m->ymin + (double)y / m->image->height * (m->ymax - m->ymin);
	m->cr = m->r;
	m->ci = m->i;
	m->iterations = 0;
	m->zr = 0.0;
	m->zi = 0.0;
}

void	mandelbrot_update(t_mandel *m)
{
	double	zretemp;

	zretemp = m->zr * m->zr - m->zi * m->zi + m->cr;
	m->zi = 2.0 * m->zr * m->zi + m->ci;
	m->zr = zretemp;
	m->iterations++;
}

void	draw_pixel(t_draw_params *params)
{
	if ((unsigned int)params->x < params->m->image->width
		&& (unsigned int)params->y < params->m->image->height)
	{
		mandelbrot_start(params->m, params->x, params->y);
		while (params->m->iterations < MAXITERATIONS && params->m->zr
			* params->m->zr + params->m->zi * params->m->zi <= 4.0)
		{
			mandelbrot_update(params->m);
		}
		params->m->color = ft_pixel(params->m->iterations % 128,
				params->m->iterations % 64, params->m->iterations % 255, 255);
		mlx_put_pixel(params->m->image, params->x, params->y, params->m->color);
	}
}

void	draw_line(t_draw_params *params)
{
	while ((unsigned int)params->x < params->m->image->width)
	{
		draw_pixel(params);
		params->x++;
	}
}

void	ft_mandelbrot(void *param)
{
	t_mandel		*m;
	t_draw_params	draw_params;

	m = (t_mandel *)param;
	draw_params.m = m;
	draw_params.x = 0;
	draw_params.y = 0;
	if (m->should_draw != 1)
		return ;
	while (draw_params.y < (int)m->image->height)
	{
		draw_params.x = 0;
		draw_line(&draw_params);
		draw_params.y++;
	}
	m->should_draw = 0;
}
