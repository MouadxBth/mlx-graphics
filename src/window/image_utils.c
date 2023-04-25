/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:43:48 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/25 17:55:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_renderer.h"

/**
 * Check if the given point is within the window bounds.
 *
 * @param point: A pointer to a t_point structure that represents
 * the point to check.
 * @param width: An integer value representing the width of the window.
 * @param height: An integer value representing the height of the window.
 *
 * @return 1 if the point is within the window bounds, otherwise 0.
 *
*/
int	ft_is_point_in_image(t_point *point, t_image *img)
{
	if (!point || !img || !ft_is_valid_image(img))
		return (0);
	return ((point->x > 0 && point->x < img->width)
		&& (point->y > 0 && point->y < img->height));
}

/**
 * Check if the two given points collide (have the same coordinates).
 *
 * @param first: A pointer to a t_point structure representing the first point.
 * @param second: A pointer to a t_point structure representing the second point.
 *
 * @return 1 if the points collide, otherwise 0.
*/
int	ft_collision(t_point *first, t_point *second)
{
	if (!first || !second)
		return (0);
	return (first->x == second->x && first->y == second->y);
}
