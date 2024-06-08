/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:54:45 by abekri            #+#    #+#             */
/*   Updated: 2024/06/03 22:38:29 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

void	write_error(const char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	if (mlx_strerror(mlx_errno))
		write(STDERR_FILENO, mlx_strerror(mlx_errno),
			ft_strlen(mlx_strerror(mlx_errno)));
	write(STDERR_FILENO, "\n", 1);
}
