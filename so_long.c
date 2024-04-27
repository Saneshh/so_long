/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:39:43 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/27 19:48:06 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static	void	check_line(t_game *s)
{
	while (s->i++ < (int)ft_strlen(s->str))
	{
		if (s->str[s->i] == '\n' && s->str[s->i - 1]
			&& s->str[s->i - 1] != '\n')
			s->line++;
		else if (s->str[s->i] == '\n' && s->str[s->i - 1] == '\n')
			exit_error(s, "Bad Folder\n");
	}
}

void	init_map(t_game *s)
{
	s->fd = open(s->folder, O_RDONLY);
	if (s->fd <= 0)
		exit_error(s, "Bad folder");
	s->i = 0;
	s->str = ft_strdup("");
	s->buffer = ft_calloc(1025, sizeof(char));
	if (!s->buffer)
		return ;
	while (s->read_size > 0)
	{
		s->read_size = read(s->fd, s->buffer, 1024);
		s->buffer[s->read_size] = 0;
		if (s->read_size > 0)
			s->str = ft_strjoin(s->str, s->buffer);
	}
	check_line(s);
	close(s->fd);
	if (s->str[s->i - 2] != '\n')
		exit_error(s, "Bad folder");
}

static	int	str_r_search(char *str, char *search, t_game *s)
{
	s->i = ft_strlen(str) - 1;
	s->j = ft_strlen(search) - 1;
	while (s->j >= 0 && s->i > 0)
	{
		if (str[s->i] != search[s->j])
			return (0);
		s->i--;
		s->j--;
	}
	return (1);
}

void	init_struct(t_game	*s)
{
	s->ground = 0;
	s->wall = 0;
	s->player = 0;
	s->ext = 0;
	s->col = 0;
	s->line = 0;
	s->move = 0;
	s->img_width = 90;
	s->img_height = 90;
	s->read_size = 1;
	s->img = ft_calloc(1, sizeof(*s->img));
	if (!s->img)
		exit_error(s, "Error\n");
	s->coord = ft_calloc(1, sizeof(*s->coord));
	if (!s->coord)
		exit_error(s, "Error\n");
	if (!str_r_search(s->folder, ".ber", s))
		exit_error(s, "Not a .ber");
}

int	main(int argc, char **argv)
{
	t_game	*s;

	s = ft_calloc(1, sizeof(t_game));
	if (s == NULL)
		exit_error(s, "Error\n");
	if (argc != 2)
		exit_error(s, "./so_long <MAP_NAME>.ber");
	s->folder = argv[1];
	init_struct(s);
	init_map(s);
	parsing(s);
	check_map(s);
	count_element(s);
	check_map_format(s);
	s->mlx = mlx_init();
	if (s->mlx == NULL)
		exit_error(s, "Error\n");
	set_img(s);
	s->mlx_win = mlx_new_window(s->mlx,
			ft_strlen(s->map[0]) * 90, s->line * 90, "So_long");
	put_decor(s);
	mlx_hook(s->mlx_win, 2, (1L << 0), key_bind, s);
	mlx_hook(s->mlx_win, 17, (1L << 17), end, s);
	mlx_loop(s->mlx);
}
