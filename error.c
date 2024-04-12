/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:46 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/12 15:00:51 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void end(t_game *s)
{
	exit_error(s, "Window Closed");
}
void exit_error(t_game *s, char *str)
{
	ft_printf("%s", str);
	s->i = 0;
	if (s->map)
	{
		while (s->map[i])
		{
			if (s->map[i])
				free(s->map[i]);
			i++;
		}
		free(s->map);
	}
	s->i = 0;
	if (s->map_cpy)
	{
		while (s->map_cpy[i])
		{
			if (s->map_cpy[i])
				free(s->map_cpy[i]);
			i++;
		}
		free(s->map_cpy);
	}
	free_struct(s);
	exit(1);
}

static void free_struct(t_game *s)
{
	if (s->img->p)
		mlx_destroy_image(s->mlx, s->img->p);
	if (s->img->e)
		mlx_destroy_image(s->mlx, s->img->e);
	if (s->img->c)
		mlx_destroy_image(s->mlx, s->img->c);
	if (s->img->g)
		mlx_destroy_image(s->mlx, s->img->g);
	if (s->img->w)
		mlx_destroy_image(s->mlx, s->img->w);
	if (s->mlx_win)
		mlx_destroy_window(s->mlx, s->mlx_win);
	if (s)
		free(s);
}

