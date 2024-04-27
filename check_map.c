/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:32:03 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/27 20:11:36 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_map(t_game	*s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (ft_strchr("01PEC", s->map[s->i][s->j]) == NULL)
				exit_error(s, "Error\n");
			if (s->map[s->i][s->j] == 'P')
			{
				s->coord->y = s->i;
				s->coord->x = s->j;
			}
			s->j++;
		}
		s->i++;
	}
	s->i = 0;
	while (s->i < s->line - 1)
	{
		if (ft_strlen(s->map[s->i]) != ft_strlen(s->map[s->i + 1]))
			exit_error(s, "Error\n");
		s->i++;
	}
}

void	count_element(t_game	*s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (s->map[s->i][s->j] == '0')
				s->ground += 1;
			else if (s->map[s->i][s->j] == '1')
				s->wall += 1;
			else if (s->map[s->i][s->j] == 'P')
				s->player += 1;
			else if (s->map[s->i][s->j] == 'E')
				s->ext += 1;
			else if (s->map[s->i][s->j] == 'C')
				s->col += 1;
			s->j++;
		}
		s->i++;
	}
}

static	void	check_map_possible(t_game	*s, int i, int j)
{
	if (s->map_cpy[i - 1][j] != '1' && s->map[i - 1][j])
	{
		s->map_cpy[i - 1][j] = '1';
		check_map_possible(s, i - 1, j);
	}
	if (s->map_cpy[i + 1][j] != '1' && s->map_cpy[i + 1][j])
	{
		s->map_cpy[i + 1][j] = '1';
		check_map_possible(s, i + 1, j);
	}
	if (s->map_cpy[i][j - 1] != '1' && s->map_cpy[i][j - 1])
	{
		s->map_cpy[i][j - 1] = '1';
		check_map_possible(s, i, j - 1);
	}
	if (s->map_cpy[i][j + 1] != '1' && s->map_cpy[i][j + 1])
	{
		s->map_cpy[i][j + 1] = '1';
		check_map_possible(s, i, j + 1);
	}
}

static	void	check_map_final(t_game *s)
{
	s->i = 0;
	while (s->map_cpy[s->i])
	{
		s->j = 0;
		while (s->map_cpy[s->i][s->j])
		{
			if (s->map_cpy[s->i][s->j] != '1' && s->map_cpy[s->i][s->j] != 'P'
				&& s->map_cpy[s->i][s->j] != '0')
			{
				exit_error(s, "Map not winnable");
			}
			s->j++;
		}
		s->i++;
	}
}

void	check_map_format(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if ((s->map[s->i][s->j]) != '1' && (s->j == 0 || s->i == s->line
				|| s->i == 0 || s->j == (int)ft_strlen(s->map[s->i])))
				exit_error(s, "Error\n");
			s->j++;
		}
		s->i++;
	}
	if (s->col == 0 || s->player != 1 || s->ext != 1)
		exit_error(s, "Missing Player, Collectible or Exit");
	check_map_possible(s, s->coord->y, s->coord->x);
	check_map_final(s);
}
