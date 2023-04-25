/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_renderer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:42:04 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/25 17:43:59 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDERER_H
# define CUB3D_RENDERER_H

# include "cub3d_color.h"
# include "cub3d_window.h"

typedef struct s_options
{
	int		scale;
	int		color;
	int		row_gap;
	int		column_gap;
	int		x_offset;
	int		y_offset;
	float	angle;
}			t_options;

typedef struct s_point
{
	int		x;
	int		y;
	int		content;
}			t_point;

typedef struct s_vector
{
	t_point	start;
	t_point	end;
	t_point	delta;
	int		x_direction;
	int		y_direction;
}			t_vector;

int			ft_is_valid_options(t_options *options);

void		ft_rotate_point(t_point *point, float angle);

void		ft_draw_point(t_image *img, t_point *point, int color);

void		ft_render_point(t_image *img, t_point *point, t_options *options);

void		ft_render_vector(t_image *img, t_vector *vector,
				t_options *options);

int			ft_is_point_in_image(t_point *point, t_image *img);

int			ft_collision(t_point *first, t_point *second);


#endif
