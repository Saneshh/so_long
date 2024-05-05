/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:32:03 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:06:01 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_map(t_game	*s, int i, int j)
{
	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (ft_strchr("01PEC", s->map[i][j]) == NULL)
				exit_error(s, "Error\nWrong characters\n");
			if (s->map[i][j] == 'P')
			{
				s->coord.y = i;
				s->coord.x = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < s->line - 1)
	{
		if (ft_strlen(s->map[i]) != ft_strlen(s->map[i + 1]))
			exit_error(s, "Error\nMap is not rectangular\n");
		i++;
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

static	void	check_map_final(t_game *s, int i, int j)
{
	i = 0;
	while (s->map_cpy[i])
	{
		j = 0;
		while (s->map_cpy[i][j])
		{
			if (s->map_cpy[i][j] != '1' && s->map_cpy[i][j] != 'P'
				&& s->map_cpy[i][j] != '0')
			{
				exit_error(s, "Error\nMap not winnable\n");
			}
			j++;
		}
		i++;
	}
}

void	check_map_format(t_game *s, int i, int j)
{
	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if ((s->map[i][j]) != '1' && (j == 0 ||
				i == (s->line - 1) || i == 0
				|| j == ((int)ft_strlen(s->map[i]) - 1)))
				exit_error(s, "Error\nSurround the map with '1'\n");
			j++;
		}
		i++;
	}
	check_map_possible(s, s->coord.y, s->coord.x);
	check_map_final(s, i, j);
}
