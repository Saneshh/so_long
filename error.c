/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:37:46 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:29:36 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end(t_game *s)
{
	exit_error(s, "Window Closed\n");
	return (0);
}

static	void	free_struct(t_game *s)
{
	if (s->buf)
	{
		if (s->buf->buffer)
			free(s->buf->buffer);
		if (s->buf->str)
			free(s->buf->str);
		free(s->buf);
	}
	if (s->mlx_win)
		mlx_destroy_window(s->mlx, s->mlx_win);
	if (s->mlx)
	{
		mlx_destroy_display(s->mlx);
		free(s->mlx);
	}
	if (s)
		free(s);
	exit(1);
}

static	void	free_img(t_game	*s)
{
	if (s->img)
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
		free(s->img);
	}
	free_struct(s);
}

void	exit_error(t_game *s, char *str)
{
	int	i;

	ft_printf("%s", str);
	i = -1;
	if (s->map)
	{
		while (s->map[++i])
			if (s->map[i])
				free(s->map[i]);
		free(s->map);
	}
	i = -1;
	if (s->map_cpy)
	{
		while (s->map_cpy[++i])
			if (s->map_cpy[i])
				free(s->map_cpy[i]);
		free(s->map_cpy);
	}
	free_img(s);
}
