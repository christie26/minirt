/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:58 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:58 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	process_dot(const char **str, double result, \
						double scale, char *bit)
{
	if (*bit & 1)
		error_msg(PARSE_DOUBLE);
	(*str)++;
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		scale *= 10.0;
		(*str)++;
	}
	*bit |= 1;
	return (result / scale);
}

static double	process_digit(const char **str, double result)
{
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	get_double(const char *str)
{
	double	result;
	double	sign;
	double	scale;
	char	bit;

	result = 0.0;
	sign = 1.0;
	scale = 1.0;
	bit = 0;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	while (*str && *str != '\n')
	{
		if (*str == '.')
			result = process_dot(&str, result, scale, &bit);
		else if (ft_isdigit(*str))
			result = process_digit(&str, result);
		else
			error_msg(PARSE_DOUBLE);
	}
	return (sign * result);
}
