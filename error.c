/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:46 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/25 15:55:26 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int end(t_game *s)
{
	exit_error(s, "Window Closed");
	return (0);
}

static void free_struct(t_game *s)
{
	if (s->img->player)
		mlx_destroy_image(s->mlx, s->img->player);
	if (s->img->exit)
		mlx_destroy_image(s->mlx, s->img->exit);
	if (s->img->col)
		mlx_destroy_image(s->mlx, s->img->col);
	if (s->img->ground)
		mlx_destroy_image(s->mlx, s->img->ground);
	if (s->img->wall)
		mlx_destroy_image(s->mlx, s->img->wall);
	if (s->img)
		free(s->img);
	if (s->mlx_win)
		mlx_destroy_window(s->mlx, s->mlx_win);
	if (s->buffer)
		free(s->buffer);
	if (s->str)
		free(s->str);
	if (s->coord)
		free(s->coord);
	if (s->mlx)
	{
		mlx_destroy_display(s->mlx);
		free(s->mlx);
	}
	if (s)
		free(s);
	exit(1);
}

void exit_error(t_game *s, char *str)
{
	ft_printf("%s", str);
	s->i = 0;
	if (s->map)
	{
		while (s->map[s->i])
		{
			if (s->map[s->i])
				free(s->map[s->i]);
			s->i++;
		}
		free(s->map);
	}
	s->i = 0;
	if (s->map_cpy)
	{
		while (s->map_cpy[s->i])
		{
			if (s->map_cpy[s->i])
				free(s->map_cpy[s->i]);
			s->i++;
		}
		free(s->map_cpy);
	}
	free_struct(s);
	exit(1);
}
