
#include "../../includes/minirt.h"

static double	process_dot(const char **str, double result, double scale)
{
	(*str)++;
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		scale *= 10.0;
		(*str)++;
	}
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

	result = 0.0;
	sign = 1.0;
	scale = 1.0;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	while (*str)
	{
		if (*str == '.')
			result = process_dot(&str, result, scale);
		else if (ft_isdigit(*str))
			result = process_digit(&str, result);
		else
			str++;
	}
	return (sign * result);
}
