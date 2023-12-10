/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:40 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/11 00:33:06 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < (data->map->height) / 32)
	{
		y = 0;
		while (y < (data->map->width) / 32)
		{
			ft_set_sprite(data, x, y);
			y++;
		}
		x++;
	}
}

void	ft_set_sprite(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->window->mlx,
		data->window->win, data->img->background, y * 32, x * 32);
	if (data->map->map[x][y] == '1')
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->wall, y * 32, x * 32);
	else if (data->map->map[x][y] == 'C')
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->collectible, y * 32, x * 32);
	else if (data->map->map[x][y] == 'X')
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->enemy, y * 32, x * 32);
	else if (data->map->map[x][y] == 'E')
	{
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->exit_close, y * 32, x * 32);
		data->x_exit = y;
		data->y_exit = x;
	}
	if (data->map->map[x][y] == 'P')
		mlx_put_image_to_window(data->window->mlx,
			data->window->win, data->img->player, y * 32, x * 32);
}

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
