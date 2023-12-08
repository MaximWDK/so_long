/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:07:20 by mleonet           #+#    #+#             */
/*   Updated: 2023/12/08 23:16:21 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->window->mlx, data->window->win);
	ft_free_tab(data->map->map);
	ft_free_tab(data->check->map);
	free(data->map);
	free(data->img);
	free(data->window);
	free(data->check);
	exit(EXIT_SUCCESS);
}

void	ft_game_over(t_data *data)
{
	mlx_destroy_window(data->window->mlx, data->window->win);
	ft_free_tab(data->map->map);
	ft_free_tab(data->check->map);
	free(data->map);
	free(data->img);
	free(data->window);
	free(data->check);
	ft_printf("You won!\n");
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str, t_data *data)
{
	ft_printf("%s", str);
	if (data->read)
		free(data->read);
	if (data->img)
		free(data->img);
	if (data->window)
		free(data->window);
	if (data->map)
		free(data->map);
	if (data->check)
		free(data->check);
	exit(EXIT_SUCCESS);
}

void ft_free_tab(char **tab)
{
    if (!tab)
        return;

    int i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}
