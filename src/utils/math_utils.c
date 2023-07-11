/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:54 by yoonsele          #+#    #+#             */
/*   Updated: 2023/07/11 14:50:54 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	quadratic_equation_1(double a, double b, double c)
{
	return (((-1) * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
}

double	quadratic_equation_2(double a, double b, double c)
{
	return (((-1) * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

double	radian_to_degree(double radian)
{
	double	degree;

	degree = radian * 180 / PI;
	return (degree);
}

double	dmod(double x, double y)
{
	return (x - (int)(x / y) * y);
}
