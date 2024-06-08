/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:54:17 by abekri            #+#    #+#             */
/*   Updated: 2024/06/08 03:30:35 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1024
# define HEIGHT 1024
# define MAXITERATIONS 100
# define EXIT_SUCCESS 0
# define ERROR_MESSAGE "Error\n"

typedef struct mandelbrot_julia
{
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
	double		cr;
	double		ci;
	mlx_image_t	*image;
	mlx_t		*mlx_ptr;
	int			should_draw;
	int			iterations;
	double		zr;
	double		zi;
	double		r;
	double		i;
	uint32_t	color;
}				t_mandel;

typedef struct s_draw_params
{
	t_mandel	*m;
	int			x;
	int			y;
}				t_draw_params;

int				init_and_run(int argc, char **argv);
int				init_mlx_and_image(mlx_t *mlx, t_mandel *m);
void			ft_start_mandel(t_mandel *m, char **c, mlx_t *mlx_ptr,
					int argc);
mlx_t			*init_mlx(void);
t_mandel		*init_mandel(void);

double			ft_atof(const char *str);
double			parse_fraction(const char **str);
double			ft_atod(const char **s);

void			init_julia(t_mandel *m, char **c, mlx_t *mlx_ptr);
void			init_mandelbrot(t_mandel *m, mlx_t *mlx_ptr);

void			ft_mandelbrot(void *param);
void			draw_line(t_draw_params *params);
void			draw_pixel(t_draw_params *params);
void			mandelbrot_update(t_mandel *m);
void			mandelbrot_start(t_mandel *m, int x, int y);

int				calc_julia_iter(float fr, float fi, float cr, float ci);
void			draw_julia(t_mandel *m);
void			ft_julia(void *param);
void			init_julia_def(t_mandel *m, mlx_t *mlx_ptr);

int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			write_error(const char *msg);
void			ft_putchar_fd(char c, int fd);
size_t			ft_strlen(const char *s);

void			up(t_mandel *m);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

void			ft_hook(mlx_key_data_t keydata, void *param);
void			zoom(double xd, double yd, void *param);

#endif
