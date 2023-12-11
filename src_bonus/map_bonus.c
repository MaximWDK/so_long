/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:54 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/11 10:46:25 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_path(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (data->map->height / 32))
	{
		j = -1;
		while (++j < (data->map->width / 32))
		{
			ft_strlen_check_blanks(data->map->map[i], data);
			if (i == 0 || i == (data->map->height - 1) / 32)
			{
				if (data->map->map[i][j] != '1')
					ft_error("Error: Map is not surrounded by walls\n", data);
			}
			else if (j == 0 || j == (data->map->width - 1) / 32)
			{
				if (data->map->map[i][j] != '1')
					ft_error("Error: Map is not surrounded by walls\n", data);
			}
		}
	}
	ft_check_is_perfect_rectangle(data);
	ft_check_minimum_requirements(data);
}

void	ft_check_is_perfect_rectangle(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < (data->map->height / 32))
	{
		j = 0;
		while (j < (data->map->width / 32))
		{
			if (ft_strlen_check_blanks(data->map->map[i], data)
				!= data->map->width / 32)
				ft_error("Error: Map is not a perfect rectangle\n", data);
			if (data->map->map[i][j] != '1' && data->map->map[i][j] != '0'
				&& data->map->map[i][j] != 'C' && data->map->map[i][j] != 'E'
				&& data->map->map[i][j] != 'P' && data->map->map[i][j] != 'X')
				ft_error("Error: Map contains invalid characters\n", data);
			if (data->map->map[i][j] == 'P')
			{
				data->x_player = j;
				data->y_player = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_strlen_check_blanks(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (!str)
		ft_error("Error: Map has blank lines\n", data);
	while (str[i])
		i++;
	return (i);
}

void	ft_check_minimum_requirements(t_data *data)
{
	int	i;
	int	j;
	int	count_exit;
	int	count_start;

	i = -1;
	count_exit = 0;
	count_start = 0;
	while (++i < (data->map->height / 32))
	{
		j = -1;
		while (++j < (data->map->width / 32))
		{
			if (data->map->map[i][j] == 'C')
				data->count_collect++;
			if (data->map->map[i][j] == 'E')
				count_exit++;
			if (data->map->map[i][j] == 'P')
				count_start++;
		}
	}
	if (data->count_collect <= 0 || count_exit != 1 || count_start != 1)
		ft_error("Error: Map does not respects requirements\n", data);
	data->check->map = ft_arraycopy(data->map->map, data);
	ft_algo(data);
}

void	ft_backtracking(t_data *data, int x, int y)
{
	if (data->check->map[y][x] == 'P')
		data->check->map[y][x] = '0';
	if (data->check->map[y][x] == 'C')
	{
		data->check->count_collect++;
		data->check->map[y][x] = '0';
	}
	if (data->check->map[y][x] == 'E')
	{
		data->check->count_exit++;
		data->check->map[y][x] = '1';
	}
	if (data->check->map[y][x] == 'X')
		data->check->map[y][x] = '1';
	if (data->check->map[y][x] == '0')
	{
		data->check->map[y][x] = 'K';
		ft_backtracking(data, x - 1, y);
		ft_backtracking(data, x, y - 1);
		ft_backtracking(data, x + 1, y);
		ft_backtracking(data, x, y + 1);
	}
}
