#ifndef MODEL_H
# define MODEL_H

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

typedef struct s_node
{
	void			*object;
	int				type;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	t_node			*headnode;
}					t_list;

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct s_coordinate
{
	double			x;
	double			y;
	double			z;
}					t_coordinate;

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct s_ambient
{
	double			ratio;
	t_color			color;
}					t_ambient;

typedef struct s_camera
{
	t_coordinate	coordinate;
	t_vector		vector;
	double			fov;
}					t_camera;

typedef struct s_light
{
	t_coordinate	coordinate;
	double			brightness;
	t_color			color;
}					t_light;

typedef struct s_sphere
{
	t_coordinate	center;
	double			diameter;
	t_color			color;
}					t_sphere;

typedef struct s_plane
{
	t_coordinate	coordinate;
	t_vector		vector;
	t_color			color;
}					t_plane;

typedef struct s_cylinder
{
	t_coordinate	coordinate;
	t_vector		vector;
	double			diameter;
	double			height;
	t_color			color;
}					t_cylinder;

typedef struct s_screen
{
	double			view_width;
	double			view_height;
	double			distance;
	t_vector		horizontal;
	t_vector		vertical;
	t_coordinate	start_point;
}					t_screen;

typedef struct s_data
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_list			*object_list;
	t_screen		screen;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_render
{
	int				window_width;
	int				window_height;
	double			focal_length;
	t_coordinate	origin;
	t_vector		horizontal;
	t_vector		vertical;
	t_coordinate	lower_left_corner;
}					t_render;

typedef struct s_phong
{
	t_color			ambient_color;
	t_color			diffuse_color;
	t_color			specular_color;
}					t_phong;

typedef struct s_hit_sphere
{
	t_vector	dif;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		t_1;
	double		t_2;
}					t_hit_sphere;

typedef struct s_hit_cylinder
{
	t_vector	oc;
	double		k;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double	    base;
	double		top;
	double		t_1;
	double		t_2;
}					t_hit_cylinder;

enum				e_definition
{
	SPHERE = 1,
	PLANE = 2,
	SQUARE = 3,
	CYLINDER = 4,
	TRIANGLE = 5,
	NONE = -1
};

#endif
