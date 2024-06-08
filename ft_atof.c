/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:02:30 by abekri            #+#    #+#             */
/*   Updated: 2024/06/03 22:22:55 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char **s)
{
	double	res;

	res = 0.0;
	while (**s >= '0' && **s <= '9')
	{
		res = res * 10.0 + (**s - '0');
		(*s)++;
	}
	return (res);
}

double	parse_fraction(const char **str)
{
	double	res;
	double	factor;

	factor = 0.1;
	res = 0.0;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		res += (**str - '0') * factor;
		(*str)++;
		factor *= 0.1;
	}
	return (res);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		f;

	result = 0.0;
	sign = 1.0;
	f = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	result = ft_atod(&str);
	if (*str == '.')
	{
		f = 1;
		result += parse_fraction(&str);
	}
	return (result * sign);
}
