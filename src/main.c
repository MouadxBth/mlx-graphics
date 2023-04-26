#include "cub3d.h"
#include "cub3d_color.h"
#include "cub3d_renderer.h"
#include "cub3d_window.h"

typedef struct s_info
{
	t_window *window;
	t_vector	*vector;
	t_options	*options;
}				t_info;

t_vector	*ft_process_vector(t_vector *vector, t_options *options)
{
	float 		angle;
	float	cosA;
	float	sinA;

	angle = options->angle * M_PI / 180.0;
    cosA = cos(angle);
    sinA = sin(angle);

	vector->delta.x = vector->end.x - vector->start.x;
	vector->delta.y = vector->end.y - vector->start.y;

	vector->end.x = vector->start.x + round(vector->delta.x * cosA - vector->delta.y * sinA);
	vector->end.y = vector->start.y + round(vector->delta.x * sinA + vector->delta.y * cosA);

	vector->delta.x = abs(vector->end.x - vector->start.x);
	vector->delta.y = -abs(vector->end.y - vector->start.y);

	vector->delta.content = vector->delta.x + vector->delta.y;

	if (vector->start.x < vector->end.x)
		vector->x_direction = 1;
	else
		vector->x_direction = -1;
	if (vector->start.y < vector->end.y)
		vector->y_direction = 1;
	else
		vector->y_direction = -1;
	return (vector);
}

void	ft_render_info(t_info *info)
{
	info->window->current_img = !info->window->current_img;

	ft_render_vector(&info->window->images[info->window->current_img],
						ft_process_vector(info->vector, info->options),
						info->options);

	mlx_put_image_to_window(info->window->mlx,
							info->window->id,
							info->window->images[info->window->current_img].id,
							0,
							0);
	ft_clear_image(&(info->window->images[!info->window->current_img]),
					info->window->width,
					info->window->height);
}
int	ft_handle_movement(int key, t_info *info)
{
	int	flag;
	int	step;

	printf("%d\n", key);
	flag = 0;
	step = 1;
	if (!info)
		return (1);
	if (key == 65361 && ++flag)
	{
		info->options->angle -= step;
		printf("left %f\n", info->options->angle);
	}
	if (key == 65362 && ++flag)
	{
		info->vector->start.x -= step;
		info->vector->end.x -= step;
		printf("left %f\n", info->options->angle);
	}
	else if (key == 65363 && ++flag)
	{
		info->options->angle += step;
		printf("right %f\n", info->options->angle);
	}
	if (key == 65364 && ++flag)
	{
		info->vector->start.y -= step;
		info->vector->end.y -= step;
		printf("left %f\n", info->options->angle);
	}

	if (flag)
	{
		printf("RE-RENDERING\n");
		ft_render_info(info);
	}
	return (0);
}

static void	ft_render(void)
{
	t_window	*window;
	t_info		info;
	t_vector vector;
	t_point start, end;

	window = ft_new_window(W_WIDTH, W_HEIGHT);
	ft_new_image(&window->images[0],
					window->mlx,
					window->width,
					window->height);
	ft_new_image(&window->images[1],
					window->mlx,
					window->width,
					window->height);

	info.options = &(t_options){
		.color = ft_mix_color(0, 255, 0, 0),
		.scale = 1,
		.row_gap = 0,
		.column_gap = 0,
		.x_offset = 0,
		.y_offset = 0,
		.angle = 90.0};

	start = (t_point){
		.x = 200,
		.y = 200,
		.content = '1'};

	end = (t_point){
		.x = 250,
		.y = 200,
		.content = '1'};

	vector.start = start;
	vector.end = end;

	info.vector = &vector;
	info.window = window;

	ft_setup_hooks(window);

	mlx_hook(window->id, 2, 1L << 0, ft_handle_movement, &info);

	ft_render_info(&info);

	mlx_loop(window->mlx);

	ft_free_window(window);

	ft_free_image(window->mlx, &window->images[0]);
	ft_free_image(window->mlx, &window->images[1]);
}

int	main(void)
{
	ft_render();
	return (0);
}
