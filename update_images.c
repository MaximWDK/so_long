/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:40:00 by mleonet           #+#    #+#             */
/*   Updated: 2023/11/23 16:22:51 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height / 32)
	{
		x = 0;
		while (x < data->map->width / 32)
		{
			ft_update_sprite(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_update_sprite(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->collectible, x * 32, y * 32);
	if (data->count_collect == 0 && data->is_exit_open == 0)
	{
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->background,
			data->x_exit * 32, data->y_exit * 32);
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->exit_open,
			data->x_exit * 32, data->y_exit * 32);
		data->is_exit_open = 1;
	}
	if (data->map->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->background,
			data->x_player * 32, data->y_player * 32);
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->player, x * 32, y * 32);
	}
}
