/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:32:03 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/12 15:03:58 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int check_map(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (!ft_strchr("01PEC", s->map[s->i][s->j]))
			exit_error();
			if (s->map[s->i][s->j] == "P")
			{
				s->coord->x = s->i;
				s->coord->y = s->j;
			}
			s->j++;
			s->count += 1;
		}
		s->i++;
		while (s->i > 0)
		{
			if (strlen(s->map[s->i] != strlen(s->map[s->i - 1])))
				exit_error(s);
			i--;
		}
	}
}

int count_element(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if(s->map[s->i][s->j] == '0')
				s->count->ground += 1;
			else if(s->map[s->i][s->j] == '1')
				s->count->wall += 1;
			else if(s->map[s->i][s->j] == 'P')
				s->count->P += 1;
			else if(s->map[s->i][s->j] == 'E')
				s->count->E += 1;
			else if(s->map[s->i][s->j] == 'C')
				s->count->C += 1;
			s->j++;
		}
		s->i++;
	}
}

void check_map_format(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if ((s->map[s->i][s->j] != '1' && (s->j == 0 || s->j == ft_strlen(s->j)))
				|| (s->map[s->i][s->j] != '1' && (s->i == 0 || s->i == ft_strlen(s->i)))
				exit_error(s, "");
			s->j++;
		}
		s->i++;
	}
	if (s->c == 0 || s->p != 1 || s->e != 1)
		exit_error(s, "Missing Player, Collectible or Exit");
	check_map_possible(s, s->coord->x, s->coord->y);
	check_map_final(s);
}

static void check_map_possible(t_game *s, int i, int j)
{
	if (s->map_cpy[i - 1] != '1')
	{
		s->map_cpy[i - 1] = '1';
		check_map_possible(s, i - 1, j);
	}
	if (s->map_cpy[i + 1] != '1')
	{
		s->map_cpy[i + 1] = '1';
		check_map_possible(s, i + 1, j);
	}
	if (s->map_cpy[j - 1] != '1')
	{
		s->map_cpy[j - 1] = '1';
		check_map_possible(s, i, j - 1);
	}
	if (s->map_cpy[j - 1] != '1')
	{
		s->map_cpy[j - 1] = '1';
		check_map_possible(s, i, j + 1);
}

static void check_map_final(t_game *s)
{
	s->i = 0;
	while (s->map_cpy[s->i])
	{
		s->j = 0;
		while (s->map_cpy[s->i][s->j])
		{
			if (s->map_cpy[s->i][s->j] != '1')
				exit_error(s, "Map not winnable");
			s->j++;
		}
		s->i++;
	}
}
