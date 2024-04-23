/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:35:57 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/23 16:19:14 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void put_img(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (s->map[s->i][s->j] == '1')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->wall, s->i * 90, s->j * 90);
			else if (s->map[s->i][s->j] >= '0' && (s->map[s->i][s->j] != 'E'
				|| s->map[s->i][s->j] != (char)(69 + 80)))
			{	
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->ground, s->i * 90, s->j * 90);
			}
			else if (s->map[s->i][s->j] == (char)(69 + 80))
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->exit, s->i * 90, s->j * 90);
			if (s->map[s->i][s->j] == 'P' || s->map[s->i][s->j] == (char)(69 + 80)
				|| s->map[s->i][s->j] == (char)(48 + 80))
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->player, s->i * 90, s->j * 90);
			if (s->map[s->i][s->j] == 'C')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->col, s->i * 90, s->j * 90);
			s->j++;
		}
		s->i++;
	}
}

void set_img(t_game *s)
{
	s->img->player = mlx_xpm_file_to_image(s->mlx,
		"./image/player.xpm", &s->img_width, &s->img_height);
		if (s->img->player == 0)
			exit_error(s, "Image can't be load");
	s->img->col = mlx_xpm_file_to_image(s->mlx,
		"./image/collectible.xpm", &s->img_width, &s->img_height);
		if (s->img->col == 0)
			exit_error(s, "Image can't be load");
	s->img->exit = mlx_xpm_file_to_image(s->mlx,
		"./image/exit.xpm", &s->img_width, &s->img_height);
		if (s->img->exit == 0)
			exit_error(s, "Image can't be load");
	s->img->wall = mlx_xpm_file_to_image(s->mlx,
		"./image/wall.xpm", &s->img_width, &s->img_height);
		if (s->img->wall == 0)
			exit_error(s, "Image can't be load");
	s->img->ground = mlx_xpm_file_to_image(s->mlx,
		"./image/ground.xpm", &s->img_width, &s->img_height);
		if (s->img->ground == 0)
			exit_error(s, "Image can't be load");
}
