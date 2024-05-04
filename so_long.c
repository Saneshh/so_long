/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:39:43 by hsolet            #+#    #+#             */
/*   Updated: 2024/05/04 17:31:10 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static	void	check_line(t_game *s)
{
	if (ft_strlen(s->str) < 2)
		exit_error(s, "Error\nMap too short\n");
	while (s->i++ < (int)ft_strlen(s->str))
	{
		if (s->str[s->i] == '\n' && s->str[s->i - 1]
			&& s->str[s->i - 1] != '\n')
			s->line++;
		else if (s->str[s->i] == '\n' && s->str[s->i - 1] == '\n')
			exit_error(s, "Error\nToo much line return\n");
	}
}

void	init_map(t_game *s)
{
	s->fd = open(s->folder, O_RDONLY);
	if (s->fd <= 0)
		exit_error(s, "Error\nFd can't be open\n");
	s->i = 0;
	s->str = ft_strdup("");
	if (!s->str)
		exit_error(s, "Error\nAlloc error\n");
	s->buffer = ft_calloc(1025, sizeof(char));
	if (!s->buffer)
		exit_error(s, "Error\nAlloc error\n");
	while (s->read_size > 0)
	{
		s->read_size = read(s->fd, s->buffer, 1024);
		s->buffer[s->read_size] = 0;
		if (s->read_size > 0)
			s->str = ft_strjoin(s->str, s->buffer);
		if (!s->str)
			exit_error(s, "Error\nAlloc error\n");
	}
	check_line(s);
	close(s->fd);
	if (s->str[s->i - 2] != '\n')
		exit_error(s, "Error\nNo return at the end\n");
}

static	int	str_r_search(char *str, char *search, t_game *s)
{
	s->i = ft_strlen(str) - 1;
	s->j = ft_strlen(search) - 1;
	while (s->j >= 0 && s->i >= 0)
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
	s->img_width = 64;
	s->img_height = 64;
	s->read_size = 1;
	s->img = ft_calloc(1, sizeof(*s->img));
	if (!s->img)
		exit_error(s, "Error\nAlloc error\n");
	if (!str_r_search(s->folder, ".ber", s))
		exit_error(s, "Error\nNot a .ber\n");
}

int	main(int argc, char **argv)
{
	t_game	*s;

	s = ft_calloc(1, sizeof(t_game));
	if (s == NULL)
		exit_error(s, "Error\nAlloc error\n");
	if (argc != 2)
		exit_error(s, "Error\n./so_long <MAP_NAME>.ber\n");
	s->folder = argv[1];
	init_struct(s);
	init_map(s);
	parsing(s);
	check_map(s);
	count_element(s);
	check_map_format(s);
	s->mlx = mlx_init();
	if (s->mlx == NULL)
		exit_error(s, "Error\nSet display...\n");
	set_img(s);
	s->mlx_win = mlx_new_window(s->mlx,
			ft_strlen(s->map[0]) * 64, s->line * 64, "So_long");
	put_decor(s);
	mlx_hook(s->mlx_win, 2, (1L << 0), key_bind, s);
	mlx_hook(s->mlx_win, 17, (1L << 17), end, s);
	mlx_loop(s->mlx);
}
