/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:45:46 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/24 14:31:06 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_window.h"

/**
 * Frees the resources associated with the given window.
 *
 * @param window Pointer to the t_window structure to be freed.
 *
 * @return void
 */
int	ft_free_window(t_window *window)
{
	int	result;

	if (!window || !window->mlx || !window->id)
		return (0);
	result = mlx_destroy_window(window->mlx, window->id);
	free(window);
	return (result);
}

/**
 * Exits the program by freeing the allocated memory for the window and images.
 *
 * @param window Pointer to the window struct to be freed.
 *
 * @return The exit status of the program.
 */
int	ft_exit(t_window *window)
{
	int	result;

	if (window->images[0].id)
		ft_free_image(window->mlx, &window->images[0]);
	if (window->images[1].id)
		ft_free_image(window->mlx, &window->images[1]);
	result = ft_free_window(window);
	return (exit(result), result);
}

/**
 * Attaches the appropriate hooks to the given window to enable
 * the window to function properly.
 *
 * @param window The window to setup hooks for.
 */
void	ft_setup_hooks(t_window *window)
{
	if (!window || !window->id)
		return ;
	mlx_hook(window->id, 17, 0, ft_exit, window);
}

/**
 * Creates a new window with the specified width and height.
 *
 * @param width Width of the window to be created.
 * @param height Height of the window to be created.
 *
 * @return Pointer to the t_window structure representing the
 * newly created window.
 * Returns NULL if the creation of the window failed.
 */
t_window	*ft_new_window(int width, int height)
{
	t_window	*result;

	result = (t_window *)malloc(sizeof(t_window));
	if (!result)
		return (NULL);
	result->width = width;
	result->height = height;
	result->current_img = 0;
	result->mlx = mlx_init();
	if (!result->mlx)
		return (ft_free_window(result), NULL);
	result->id = mlx_new_window(result->mlx, width, height, "Cub3D");
	result->images[0].id = NULL;
	result->images[1].id = NULL;
	return (result);
}
