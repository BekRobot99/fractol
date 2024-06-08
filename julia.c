/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:16:48 by abekri            #+#    #+#             */
/*   Updated: 2024/06/04 16:51:20 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia_iter(float fr, float fi, float cr, float ci)
{
	int		iterations;
	double	temp;

	iterations = 0;
	while (iterations < MAXITERATIONS && (fr * fr + fi * fi) <= 4)
	{
		temp = fr * fr - fi * fi + cr;
		fi = 2 * fr * fi + ci;
		fr = temp;
		iterations++;
	}
	return (iterations);
}

void	draw_julia(t_mandel *m)
{
	uint32_t	y;
	uint32_t	x;
	int			iterations;

	y = 0;
	while (y < m->image->height)
	{
		x = 0;
		while (x < m->image->width)
		{
			iterations = calc_julia_iter(m->xmin + (double)x / m->image->width
					* (m->xmax - m->xmin), m->ymin + (double)y
					/ m->image->height * (m->ymax - m->ymin), m->cr, m->ci);
			mlx_put_pixel(m->image, x, y, ft_pixel(iterations % 256, iterations
					% 128, iterations % 64, 255));
			x++;
		}
		y++;
	}
}

void	ft_julia(void *param)
{
	t_mandel	*m;

	m = (t_mandel *)param;
	if (m->should_draw != 1)
		return ;
	draw_julia(m);
	m->should_draw = 0;
}
