/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:07:20 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/08 18:00:30 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->window->mlx, data->window->win);
	free(data->map);
	free(data->img);
	free(data->window);
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_SUCCESS);
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
