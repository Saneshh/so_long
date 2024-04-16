/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:35:57 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/16 12:10:39 by hsolet           ###   ########.fr       */
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
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->w, 90, 90);
			else if (s->map[s->i][s->j] >= '0'
					&& (s->map[s->i][s->j] != 'E' || s->map[s->i][s->j] != (char)(69 + 80)))
			{	
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->g, 90, 90);
			}
			else if (s->map[s->i][s->j] == (char)(69 + 80))
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->e, 90, 90);
			if (s->map[s->i][s->j] == 'P' || s->map[s->i][s->j] == (char)(69 + 80)
				|| s->map[s->i][s->j] == (char)(48 + 80))
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->p, 90, 90);
			if (s->map[s->i][s->j] == 'C')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->c, 90, 90);
			s->j++;
		}
		s->i++;
	}
}

void set_img(t_game *s)
{
	s->img->p = mlx_xpm_file_to_image(s->mlx,
		"./image/player.xpm", &s->img_width, &s->img_height);
		if (s->img->p == 0)
			exit_error(s, "Image can't be load");
	s->img->c = mlx_xpm_file_to_image(s->mlx,
		"./image/collectible.xpm", &s->img_width, &s->img_height);
		if (s->img->c == 0)
			exit_error(s, "Image can't be load");
	s->img->e = mlx_xpm_file_to_image(s->mlx,
		"./image/exit.xpm", &s->img_width, &s->img_height);
		if (s->img->e == 0)
			exit_error(s, "Image can't be load");
	s->img->w = mlx_xpm_file_to_image(s->mlx,
		"./image/wall.xpm", &s->img_width, &s->img_height);
		if (s->img->w == 0)
			exit_error(s, "Image can't be load");
	s->img->g = mlx_xpm_file_to_image(s->mlx,
		"./image/ground.xpm", &s->img_width, &s->img_height);
		if (s->img->g == 0)
			exit_error(s, "Image can't be load");
}
