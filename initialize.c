/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:42:10 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/08 23:49:11 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_window(t_data *data)
{
	data->window->mlx = mlx_init();
	if (!data->window->mlx)
		ft_error("Error: Initializing MiniLibX Failed\n", data);
	data->window->win = mlx_new_window(data->window->mlx,
			data->map->width, data->map->height, "So_Long");
	if (!data->window->win)
	{
		free(data->map);
		free(data->img);
		free(data->window);
		ft_error("Error: Initializing Window Failed\n", data);
	}
}

void	ft_init_images(t_data *data)
{
	data->img->background = mlx_xpm_file_to_image(data->window->mlx,
			"./images/background.xpm",
			&data->img->width_img, &data->img->height_img);
	data->img->wall = mlx_xpm_file_to_image(data->window->mlx,
			"./images/wall.xpm",
			&data->img->width_img, &data->img->height_img);
	data->img->collectible = mlx_xpm_file_to_image(data->window->mlx,
			"./images/collectible.xpm",
			&data->img->width_img, &data->img->height_img);
	data->img->exit_open = mlx_xpm_file_to_image(data->window->mlx,
			"./images/exit_open.xpm",
			&data->img->width_img, &data->img->height_img);
	data->img->exit_close = mlx_xpm_file_to_image(data->window->mlx,
			"./images/exit_close.xpm",
			&data->img->width_img, &data->img->height_img);
	data->img->player = mlx_xpm_file_to_image(data->window->mlx,
			"./images/perso.xpm",
			&data->img->width_img, &data->img->height_img);
	if (!data->img->background || !data->img->wall || !data->img->collectible
		|| !data->img->exit_close || !data->img->exit_open
		|| !data->img->player)
		ft_error("Error: Intializing Images Failed\n", data);
}

void	ft_init_data(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	data->img = malloc(sizeof(t_img));
	data->window = malloc(sizeof(t_window));
	data->check = malloc(sizeof(t_check));
	if (!data->map || !data->img || !data->window || !data->check)
		ft_error("Error: Initializing Data Failed\n", data);
	data->check->map = NULL;
	data->count_moves = 0;
	data->is_exit_open = 0;
	data->count_collect = 0;
	data->check->count_collect = 0;
	data->check->count_exit = 0;
}
