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

t_vector	ft_new_vector(t_point start, t_point end, t_options *options)
{
	t_vector	result;
	int			x, y;
	float 		angle;

	x = end.x;
	y = end.y;

	angle = options->angle * M_PI / 180.0;

	printf("ANGLE : %f\n", angle);

	x = x * cos(angle) - y * sin(angle);
	y = end.x * sin(angle) + y * cos(angle);

	end.x = x;
	end.y = y;

	result.start = start;
	result.end = end;

	result.delta.x = abs(end.x - start.x);
	result.delta.y = -abs(end.y - start.y);

	result.delta.content = result.delta.x + result.delta.y;
	if (start.x < end.x)
		result.x_direction = 1;
	else
		result.x_direction = -1;
	if (start.y < end.y)
		result.y_direction = 1;
	else
		result.y_direction = -1;
	return (result);
}

void	ft_render_info(t_info *info)
{
	info->window->current_img = !info->window->current_img;
	ft_render_vector(&info->window->images[info->window->current_img],
						info->vector,
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
		.angle = 0.0};

	start = (t_point){
		.x = 200,
		.y = 200,
		.content = '1'};

	end = (t_point){
		.x = 250,
		.y = 200,
		.content = '1'};

	vector = ft_new_vector(start, end, info.options);

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
