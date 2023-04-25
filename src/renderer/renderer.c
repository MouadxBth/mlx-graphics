/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:08:30 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/25 17:38:44 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_renderer.h"

/**
 * Draws a point of a specified color on the given image
 * at the given point coordinates.
 *
 * Calculate the step size in bytes, since the pixels data is
 * stored each one next to the other, we need to figure out how
 * many bytes the pixel occupies to get the target pixel memory address.
 *
 * Then, we calculate the index of the pixel in the image where the point
 * will be rendered, all we need is to calculate the vertical offset
 * which can be done by multiplying the target point's y by the number of
 * lines the image has, and add the target point's x offset calculated before.
 *
 * Finally, we set the color of the pixel at the calculated index based
 * on the endianness of @param img.
 *
 * @param img The image to draw on
 * @param point The point to draw on the image
 * @param color The color to draw the point in
 *
 * @return void
 */
void	ft_draw_point(t_image *img, t_point *point, int color)
{
	int	index;
	int	step;
	int	current;

	if (!img || !point || !ft_is_point_in_image(point, img)
		|| !ft_is_valid_rgb(color))
		return ;
	step = img->bits_per_pixel / 8;
	index = (point->y * img->line_length + point->x * step);
	current = -1;
	while (++current < step)
	{
		if (img->endian)
			img->address[index++] = color >> (((step - 1) * 8) - 8
					* current) & 0xFF;
		else
			img->address[index++] = color >> (8 * current) & 0xFF;
	}
}

/**
 * Renders a scaled point (square) of a given color, size,
 * vertical and horizontal gaps and offsets, starting from the
 * provided point onto an image.
 *
 * If NULL or invalid, default options with white color, no scaling, no gaps,
 * and no offset are used.
 *
 * @param img The image to render the point onto.
 * @param point The center point of the square to render.
 * @param options Optional rendering options to modify the color
 * and size of the square.
 *
 *
 * @return void
 */
void	ft_render_point(t_image *img, t_point *point, t_options *options)
{
	t_point	end;
	t_point	current;

	if (!img || !point)
		return ;
	if (!options || !ft_is_valid_options(options))
	{
		options = &(t_options){
			.color = 0xFFFFFF, .scale = 1, .row_gap = 0,
			.column_gap = 0, .x_offset = 0, .y_offset = 0};
		printf("Error!\n\
			Provided invalid/null options, using default options...\n");
	}
	end.x = (point->x + options->x_offset + options->scale)
		- options->column_gap;
	end.y = (point->y + options->y_offset + options->scale) - options->row_gap;
	current.y = point->y - 1 + options->y_offset;
	while (++current.y < end.y)
	{
		current.x = point->x - 1 + options->x_offset;
		while (++current.x < end.x)
			ft_draw_point(img, &current, options->color);
	}
}

/**
 * Renders a vector on the given image using the
 * Bresenham's line algorithm.
 *
 * This function iterates over the vector using
 * Bresenham's line algorithm.
 *
 * It renders the current point if it falls within the
 * image bounds and breaks the loop if the current point is
 * the end point of the vector.
 *
 * It calculates the error using the delta values of
 * the vector and updates the current point and error value based
 * on the x direction and the y direction.
 *
 * This process is repeated until the end point is reached,
 * and the entire vector is rendered on the image.
 *
 * @param img The image to render the vector on.
 * @param vector The vector to render.
 *
 * @return void
 */
void	ft_render_vector(t_image *img, t_vector *vector, t_options *options)
{
	int		error;
	t_point	current;

	if (!img || !vector)
		return ;
	current = vector->start;
	while (current.x != vector->end.x || current.y != vector->end.y)
	{
		if (ft_is_point_in_image(&current, img))
			ft_render_point(img, &current, options);
		if (ft_collision(&current, &vector->end))
			break ;
		error = vector->delta.content * 2;
		if (error >= vector->delta.y)
		{
			vector->delta.content += vector->delta.y;
			current.x += vector->x_direction;
		}
		if (error <= vector->delta.x)
		{
			vector->delta.content += vector->delta.x;
			current.y += vector->y_direction;
		}
	}
}
