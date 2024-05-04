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
	if (s->mlx_win)
		mlx_destroy_window(s->mlx, s->mlx_win);
	if (s->buffer)
		free(s->buffer);
	if (s->str)
		free(s->str);
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
}

void	exit_error(t_game *s, char *str)
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
	free_img(s);
	free_struct(s);
}

void	parsing(t_game *s)
{
	s->fd = open(s->folder, O_RDONLY);
	s->map = ft_calloc(s->line + 1, sizeof(char *));
	if (!(s->map))
		exit_error(s, "Error\nAlloc error\n");
	s->map_cpy = ft_calloc(s->line + 1, sizeof(char *));
	if (!s->map_cpy)
		exit_error(s, "Error\nAlloc error\n");
	s->i = 0;
	while (s->i < s->line)
	{
		s->map[s->i] = ft_strtrim(get_next_line(s->fd), "\n");
		if (s->map[s->i] == NULL)
			exit_error(s, "Error\nAlloc error\n");
		s->map_cpy[s->i] = ft_strdup(s->map[s->i]);
		if (!s->map_cpy[s->i])
			exit_error(s, "Error\nAlloc error\n");
		s->i++;
	}
	free(get_next_line(s->fd));
	close(s->fd);
	if (ft_strlen(s->map[0]) > 500 || s->line > 500)
		exit_error(s, "Error\nMap is too big\n");
}
