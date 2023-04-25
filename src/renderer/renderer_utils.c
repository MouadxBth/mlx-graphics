/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:21:01 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/25 17:39:18 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_renderer.h"
#include "cub3d_color.h"

# define ft_abs(x) x < 0 ? x * -1 : x

/**
 * Check if given options are valid.
 *
 * @param options Pointer to the options to be validated
 * @return 1 if the options are valid, 0 otherwise.
 */
int	ft_is_valid_options(t_options *options)
{
	return (options && ft_is_valid_rgb(options->color)
		&& options->scale >= 0
		&& options->row_gap >= 0
		&& options->column_gap >= 0);
}
/*
void	ft_rotate_point(t_point *point, float angle)
{
	int	x;
	int	y;

	if (!point)
		return ;
	angle = angle * M_PI / 180.0;
	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = ft_abs(x * sin(angle) + y * cos(angle));
} */
