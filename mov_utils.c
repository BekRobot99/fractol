/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:54:45 by abekri            #+#    #+#             */
/*   Updated: 2024/06/03 22:05:00 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	up(t_mandel *m)
{
	m->ymin += (m->ymax - m->ymin) * -0.1;
	m->ymax += (m->ymax - m->ymin) * -0.1;
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	int32_t	result;

	result = 0;
	result += r * 16777216;
	result += g * 65536;
	result += b * 256;
	result += a;
	return (result);
}
