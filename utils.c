/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:40:11 by mleonet           #+#    #+#             */
/*   Updated: 2023/11/23 17:03:17 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid_move(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == '1')
		return (0);
	else if (data->map->map[y][x] == 'E')
	{
		if (data->count_collect == 0)
			return (1);
		else
			return (0);
	}
	return (1);
}

void	ft_check_win(t_data *data, int x, int y)
{
	if (data->count_collect == 0 && data->map->map[y][x] == 'E')
		ft_game_over(data);
}

void	ft_game_over(t_data *data)
{
	mlx_destroy_window(data->window->mlx, data->window->win);
	free(data->map);
	free(data->img);
	free(data->window);
	ft_printf("You won!\n");
	exit(EXIT_SUCCESS);
}
