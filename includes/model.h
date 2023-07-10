#ifndef MODEL_H
# define MODEL_H

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define THREADS_PER_DIMENSION 3
# define NUM_THREADS 9
# define EPSILON 0.0001

typedef struct s_node
{
	void			*object;
	int				type;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	t_node			*headnode;
	int				size;
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
	int				checker;
}					t_sphere;

typedef struct s_plane
{
	t_coordinate	coordinate;
	t_vector		vector;
	t_color			color;
	int				checker;
}					t_plane;

typedef struct s_cylinder
{
	t_coordinate	base;
	t_coordinate	top;
	t_vector		vector;
	double			diameter;
	double			height;
	t_color			color;
	int				checker;
}					t_cylinder;

typedef struct s_paraboloid
{
	t_coordinate	coordinate;
	t_vector		vector;
	double			parameter_x;
	double			parameter_y;
	double			height;
	t_color			color;
	int				checker;
}					t_paraboloid;

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
	t_list			*light_list;
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

typedef struct s_phong
{
	t_color			ambient_color;
	t_color			diffuse_color;
	t_color			specular_color;
}					t_phong;

typedef struct s_hit_sphere
{
	t_vector		dif;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			t_1;
	double			t_2;
}					t_hit_sphere;

typedef struct s_hit_cylinder
{
	t_vector		oc;
	double			k;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			base;
	double			top;
	double			t_1;
	double			t_2;
}					t_hit_cylinder;

typedef struct s_hit_paraboloid
{
	t_vector		oc;
	double			k;
	double			a;
	double			b;
	double			c;
	double			discriminant;
	double			base;
	double			top;
	double			t_1;
	double			t_2;
	t_coordinate	hit_point_1;
	t_coordinate	hit_point_2;
	t_vector		normal_1;
	t_vector		normal_2;
}					t_hit_paraboloid;

typedef struct s_specular_light
{
	t_vector		reflected_light;
	t_vector		viewer_direction;
	double			specular_intensity;
	double			ambient_ratio;
}					t_specular_light;

enum				e_definition
{
	SPHERE = 1,
	PLANE = 2,
	CYLINDER = 3,
	PARABOLOID = 4,
	NONE = -1
};

enum e_cylinder
{
	BASE,
	TOP,
	NOT_LID
};

typedef struct s_render
{
	double			u;
	double			v;
	t_coordinate	lower_left_corner;
	t_vector		horizontal;
	t_vector		vertical;
	t_coordinate	origin;
	t_color			color_rgb;
	int				color_hex;
}					t_render;

typedef struct s_render_thread
{
	t_data			*data;
	int				start_x;
	int				end_x;
	int				start_y;
	int				end_y;
	t_vector		horizontal;
	t_vector		vertical;
	t_coordinate	pixel;
	int				thread_index;
}					t_render_thread;

#endif
