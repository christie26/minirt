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
