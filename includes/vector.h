#ifndef VECTOR_H
# define VECTOR_H

# include "model.h"

typedef struct s_ray
{
	t_coordinate	origin;
	t_vector		direction;
	t_coordinate	hit_point;
	t_vector		hit_normal;
	t_vector		hit_direction;
	t_coordinate	light;
	void			*object;
	int				object_type;
}					t_ray;

t_vector			init_vector(double x, double y, double z);
t_vector			coordinate_to_vector(t_coordinate coordinate);
t_vector			get_vector_two_point(t_coordinate start, t_coordinate end);
t_coordinate		vector_to_coordinate(t_vector vec);

t_coordinate		calculate_hit_point(t_ray ray, double t);
double				get_distance(t_coordinate start, t_coordinate end);

t_vector			vector_add(t_vector v1, t_vector v2);
t_vector			vector_sub(t_vector v1, t_vector v2);
t_vector			vector_mult(t_vector v1, t_vector v2);
t_vector			vector_mult_scalar(t_vector v1, double t);

double				vector_length(t_vector v);
double				vector_dot(t_vector v1, t_vector v2);
t_vector			vector_cross(t_vector v1, t_vector v2);
t_vector			vector_unit(t_vector v);
t_vector			rotate_vector(t_vector vec, t_vector rotation_angle);

#endif
