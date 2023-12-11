/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:07:16 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/11 16:46:40 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->x_player;
	new_y = data->y_player - 1;
	if (ft_is_valid_move(data, new_x, new_y))
	{
		data->count_moves++;
		ft_check_win(data, new_x, new_y);
		data->map->map[data->y_player][data->x_player] = '0';
		if (data->map->map[new_y][new_x] == 'C')
		{
			data->map->map[new_y][new_x] = '0';
			data->count_collect--;
		}
		if (data->map->map[new_y][new_x] == 'X')
			data->is_touched = 1;
		data->map->map[new_y][new_x] = 'P';
		ft_update_image(data);
		data->y_player = new_y;
	}
}

void	ft_move_down(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->x_player;
	new_y = data->y_player + 1;
	if (ft_is_valid_move(data, new_x, new_y))
	{
		data->count_moves++;
		ft_check_win(data, new_x, new_y);
		data->map->map[data->y_player][data->x_player] = '0';
		if (data->map->map[new_y][new_x] == 'C')
		{
			data->map->map[new_y][new_x] = '0';
			data->count_collect--;
		}
		if (data->map->map[new_y][new_x] == 'X')
			data->is_touched = 1;
		data->map->map[new_y][new_x] = 'P';
		ft_update_image(data);
		data->y_player = new_y;
	}
}

void	ft_move_left(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->x_player - 1;
	new_y = data->y_player;
	if (ft_is_valid_move(data, new_x, new_y))
	{
		data->count_moves++;
		ft_check_win(data, new_x, new_y);
		data->map->map[data->y_player][data->x_player] = '0';
		if (data->map->map[new_y][new_x] == 'C')
		{
			data->map->map[new_y][new_x] = '0';
			data->count_collect--;
		}
		if (data->map->map[new_y][new_x] == 'X')
			data->is_touched = 1;
		data->map->map[new_y][new_x] = 'P';
		ft_update_image(data);
		data->x_player = new_x;
	}
}

void	ft_move_right(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->x_player + 1;
	new_y = data->y_player;
	if (ft_is_valid_move(data, new_x, new_y))
	{
		data->count_moves++;
		ft_check_win(data, new_x, new_y);
		data->map->map[data->y_player][data->x_player] = '0';
		if (data->map->map[new_y][new_x] == 'C')
		{
			data->map->map[new_y][new_x] = '0';
			data->count_collect--;
		}
		if (data->map->map[new_y][new_x] == 'X')
			data->is_touched = 1;
		data->map->map[new_y][new_x] = 'P';
		ft_update_image(data);
		data->x_player = new_x;
	}
}

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_exit(data);
	if (keycode == KEY_W)
		ft_move_up(data);
	if (keycode == KEY_UP)
		ft_move_up(data);
	if (keycode == KEY_S)
		ft_move_down(data);
	if (keycode == KEY_DOWN)
		ft_move_down(data);
	if (keycode == KEY_A)
		ft_move_left(data);
	if (keycode == KEY_LEFT)
		ft_move_left(data);
	if (keycode == KEY_D)
		ft_move_right(data);
	if (keycode == KEY_RIGHT)
		ft_move_right(data);
	if (data->is_touched == 1)
		ft_game_over(data, 1);
	return (0);
}
