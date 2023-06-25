#ifndef VECTOR_H
# define VECTOR_H

# include "model.h"

typedef struct s_ray {
	t_coordinate origin;
	t_vector	direction;
}	t_ray;

t_vector	init_vector(double x, double y, double z);

t_vector	get_vector_two_point(t_coordinate start, t_coordinate end);

t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_mult(t_vector v1, t_vector v2);
t_vector	vector_mult_scalar(t_vector v1, double t);

double		vector_length(t_vector v);
double		vector_dot(t_vector v1, t_vector v2);
t_vector	vector_cross(t_vector v1, t_vector v2);
t_vector	vector_unit(t_vector v);

#endif
