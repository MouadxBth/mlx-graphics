/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:07:05 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/22 19:24:48 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"

/**
 * Mixes the given color components to create a color value.
 *
 * @param r The red component of the color value.
 * @param g The green component of the color value.
 * @param b The blue component of the color value.
 * @param a The opacity component of the color value. (DEPRACATED)
 * @return The color value created from the given color components.
 */
int	ft_mix_color(int r, int g, int b, int a)
{
	(void) a;
	return (r << 16 | g << 8 | b);
}

/**
 * Calculates the percentage placement of a value
 * between a start and end point.
 *
 * @param start The starting value of the range.
 * @param end The ending value of the range.
 * @param current The value to calculate the percentage for.
 * @return The percentage placement of the given value between
 * the start and end points.
 *         Returns 1.0 if the start and end points are the same.
 */
float	ft_percentage(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

/**
 * Calculates a linear interpolation between two values based
 * on a given percentage.
 *
 * @param start The starting value of the range.
 * @param end The ending value of the range.
 * @param percentage The percentage placement between the start
 * and end points to interpolate.
 * @return The interpolated value between the start and end points
 * based on the given percentage.
 */
int	ft_lerp(int start, int end, float percentage)
{
	return ((int)(start + (end - start) * percentage));
}
