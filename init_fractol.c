/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:17:45 by abekri            #+#    #+#             */
/*   Updated: 2024/06/03 19:18:56 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx_ptr;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx_ptr)
	{
		ft_putstr_fd("MLX initialization failed\n", STDERR_FILENO);
	}
	return (mlx_ptr);
}

t_mandel	*init_mandel(void)
{
	t_mandel	*m;

	m = (t_mandel *)malloc(sizeof(t_mandel));
	if (!m)
	{
		ft_putstr_fd("Memory allocation failed\n", STDERR_FILENO);
		return (NULL);
	}
	m->image = NULL;
	m->mlx_ptr = NULL;
	m->should_draw = 0;
	m->iterations = 0;
	m->zr = 0.0;
	m->zi = 0.0;
	m->r = 0.0;
	m->i = 0.0;
	m->color = 0;
	return (m);
}

void	init_julia(t_mandel *m, char **c, mlx_t *mlx_ptr)
{
	m->xmin = -1.5;
	m->xmax = 1.5;
	m->ymin = -1.5;
	m->ymax = 1.5;
	m->cr = ft_atof(c[2]);
	m->ci = ft_atof(c[3]);
	mlx_loop_hook(mlx_ptr, ft_julia, m);
}

void	init_julia_def(t_mandel *m, mlx_t *mlx_ptr)
{
	m->xmin = -1.5;
	m->ymin = -1.5;
	m->xmax = 1.5;
	m->ymax = 1.5;
	m->cr = atof("0.355");
	m->ci = atof("0.355");
	m->mlx_ptr = mlx_ptr;
	mlx_loop_hook(mlx_ptr, ft_julia, m);
}

void	init_mandelbrot(t_mandel *m, mlx_t *mlx_ptr)
{
	m->xmin = -2.0;
	m->xmax = 1.0;
	m->ymin = -1.5;
	m->ymax = 1.5;
	mlx_loop_hook(mlx_ptr, ft_mandelbrot, m);
}
