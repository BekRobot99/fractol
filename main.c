/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:53:52 by abekri            #+#    #+#             */
/*   Updated: 2024/06/08 03:21:01 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_mlx_and_image(mlx_t *mlx_ptr, t_mandel *m)
{
	if (!mlx_ptr)
	{
		write_error("MLX Error: ");
		return (EXIT_FAILURE);
	}
	m->image = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	if (!m->image)
	{
		mlx_terminate(mlx_ptr);
		write_error("Image Creation Error: ");
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx_ptr, m->image, 0, 0) == -1)
	{
		mlx_delete_image(mlx_ptr, m->image);
		mlx_terminate(mlx_ptr);
		write_error("Image Display Error: ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_start_mandel(t_mandel *m, char **argv, mlx_t *mlx_ptr, int argc)
{
	m->should_draw = 1;
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		init_mandelbrot(m, mlx_ptr);
	}
	else if ((argc == 4 || argc == 2) && !ft_strncmp(argv[1], "julia", 5))
	{
		if (argc == 4)
			init_julia(m, argv, mlx_ptr);
		else
			init_julia_def(m, mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Invalid parameters for Julia or Mandelbrot\n", 1);
		exit(EXIT_FAILURE);
	}
}

static int	initialize_mlx_and_mandel(mlx_t **mlx_ptr, t_mandel **m)
{
	*mlx_ptr = init_mlx();
	if (!*mlx_ptr)
		return (EXIT_FAILURE);
	*m = init_mandel();
	if (!*m)
	{
		mlx_terminate(*mlx_ptr);
		return (EXIT_FAILURE);
	}
	(*m)->mlx_ptr = *mlx_ptr;
	return (EXIT_SUCCESS);
}

int	init_and_run(int argc, char **argv)
{
	mlx_t		*mlx_ptr;
	t_mandel	*m;

	if (initialize_mlx_and_mandel(&mlx_ptr, &m) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_mlx_and_image(mlx_ptr, m) == EXIT_SUCCESS)
	{
		ft_start_mandel(m, argv, mlx_ptr, argc);
		mlx_scroll_hook(mlx_ptr, zoom, m);
		mlx_key_hook(mlx_ptr, ft_hook, m);
		mlx_loop(mlx_ptr);
		mlx_terminate(mlx_ptr);
		free(m);
		return (EXIT_SUCCESS);
	}
	free(m);
	mlx_terminate(mlx_ptr);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)) || (argc == 2
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		return (init_and_run(argc, argv));
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}
