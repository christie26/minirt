
#ifndef MODEL_H
# define MODEL_H

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_cordinate {
	double	x;
	double	y;
	double	z;
}	t_cordinate;

typedef struct s_vector {
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_ambient {
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera {
	t_cordinate	cordinate;
	t_vector	vector;
	double		fov;
}	t_camera;

typedef struct s_light {
	t_cordinate	cordinate;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_sphere {
	t_cordinate	cordinate;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane {
	t_cordinate	cordinate;
	t_vector	vector;
	t_color		color;
}	t_plane;

typedef struct s_cylinder {
	t_cordinate	cordinate;
	t_vector	vector;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

#endif
