/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:32:03 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/23 15:26:06 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void check_map(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (ft_strchr("01PEC", s->map[s->i][s->j]) == NULL)
				exit_error(s, "Error2\n");
			//ft_printf("bug 1");
			if (s->map[s->i][s->j] == 'P')
			{
				s->coord->x = s->i;
				s->coord->y = s->j;
			}
			s->j++;
		//	ft_printf("s->j = %d, max = %d\ns->i = %d, max = %d\n", s->j, ft_strlen(s->map[s->i]), s->i, s->line);
		}
		s->i++;
	}
	s->i = 0;
	//ft_printf("\n\n\n\n\n%d\n\n\n\n\n", s->line);
	while (s->i < s->line - 1)
	{
		//ft_printf("BUG DE FOU : %s", s->map[s->i]);
		//ft_printf("\n i = %d et line = %d\n", s->i, s->line);
		if (ft_strlen(s->map[s->i]) != ft_strlen(s->map[s->i + 1]))
			exit_error(s, "Error3\n");
		s->i++;

	}

}

void count_element(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if(s->map[s->i][s->j] == '0')
				s->ground += 1;
			else if(s->map[s->i][s->j] == '1')
				s->wall += 1;
			else if(s->map[s->i][s->j] == 'P')
				s->player += 1;
			else if(s->map[s->i][s->j] == 'E')
				s->ext += 1;
			else if(s->map[s->i][s->j] == 'C')
				s->col += 1;
			s->j++;
		}
		s->i++;
	}
}

static void check_map_possible(t_game *s, int i, int j)
{
	if (s->map_cpy[i - 1][j] != '1')
	{
		s->map_cpy[i - 1][j] = '1';
		check_map_possible(s, i - 1, j);
	}
	if (s->map_cpy[i + 1][j] != '1')
	{
		s->map_cpy[i + 1][j] = '1';
		check_map_possible(s, i + 1, j);
	}
	if (s->map_cpy[i][j - 1] != '1')
	{
		s->map_cpy[i][j - 1] = '1';
		check_map_possible(s, i, j - 1);
	}
	if (s->map_cpy[i][j + 1] != '1')
	{
		s->map_cpy[i][j + 1] = '1';
		check_map_possible(s, i, j + 1);
	}
}

static void check_map_final(t_game *s)
{
	s->i = 0;
	while (s->map_cpy[s->i])
	{
		s->j = 0;
		while (s->map_cpy[s->i][s->j])
		{
			if (s->map_cpy[s->i][s->j] != '1' && s->map_cpy[s->i][s->j] != 'P')
				{
			//	ft_printf("x = %d\n y = %d\n charactere = %c", s->i, s->j, s->map_cpy[s->i][s->j]);
				exit_error(s, "Map not winnable");
					}
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
			if ((s->map[s->i][s->j]) != '1' && (s->j == 0 || s->i == s->line
				|| s->i == 0 || s->j == (int)ft_strlen(s->map[s->i])))
				exit_error(s, "");
			s->j++;
		}
		s->i++;
	}
	if (s->col == 0 || s->player != 1 || s->ext != 1)
		exit_error(s, "Missing Player, Collectible or Exit");
	check_map_possible(s, s->coord->x, s->coord->y);
	check_map_final(s);
}
