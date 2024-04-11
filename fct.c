//---3---
void parsing(int fd, t_game *s)
{
	s->map = ft_calloc(s->line, sizeof(char *));
	if (!(s->map))
		return ;
	s->i = 0;
	while (s->i < s->line)
	{
		s->map[s->i] = get_next_line(fd);
		s->map_cpy[s->i] = ft_strdup[s->i];
		s->i++;
	}
}
//---5---
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


 //---1---
void init_struct(t_game *s) 
{
	s->ground = 0;
	s->wall = 0;
	s->P = 0;
	s->E = 0;
	s->C = 0;
	s->line = 0;
	s->move = 0;
}
//---2---
void init_map(t_game *s)
{
	int read_size;

	read_size = 1;
	s->i = 0;
	s->str = ft_strdup("");
	s->buffer = ft_calloc(2048, sizeof(char));
	if (!buffer)
		return ;
	while (read_size > 0)
	{
		read_size = read(fd, s->buffer, 2048);
		s->str = ft_strjoin(str, s->buffer);
		free(s->buffer);
	}
	while (s->str[s->i++])
	{
		if (s->str[s->i] == '\n' && s->str[s->i - 1] && s->str[s->i - 1] != '\n')
			s->line += 1;
		else 
			exit_error();
	}
	free(s->buffer);
}
//---4---
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
				exit_error();
			i--;
		}
	}
}
//---6---
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
				exit_error();
			s->j++;
		}
		s->i++;
	}
	if (s->C == 0 || s->P != 1 || s-> E != 1)
		exit_error(s, "Missing Player, Collectible or Exit");
}
//---7---
void check_map_possible(t_game *s, int i, int j)
{
	//int i = s->coord->x;
	//int j = s->coord->y;
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
}
//---8---
void check_map_final(t_game *s)
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

void exit_error()
{

	exit(1);
}

int main(int argc, char **argv)
{
	t_game *s;

	s->mlx = mlx_init();
	s->mlx_win = mlx_new_window(s->mlx, 1920, 1080, "So_long");

	mlx_loop(mlx);
}
//---1*---
void set_img(t_game *s)
{
	int	img_width;
	int	img_height;

	img_width = 90;
	img_height = 90;
	s->img->P = mlx_xpm_file_to_image(mlx,
		"./image/player.xpm", &img_width, &img_height)
	s->img->C = mlx_xpm_file_to_image(mlx,
		"./image/collectible.xpm", &img_width, &img_height)
	s->img->E = mlx_xpm_file_to_image(mlx,
		"./image/exit.xpm", &img_width, &img_height)
	s->img->W = mlx_xpm_file_to_image(mlx,
		"./image/wall.xpm", &img_width, &img_height)
	s->img->G = mlx_xpm_file_to_image(mlx,
		"./image/ground.xpm", &img_width, &img_height)
}

void set_key_bind()
{
	mlx_hook(s->mlx_win, 2, (1L<<0), key_bind, s);
	mlx_hook(s->mlx_win, 8, (1L<<5), end, s);
}
//---9---
void key_bind(int keybind, t_game *s)
{
	if (keybind == 87)
		move_up(s);
	else if (keybind == 83)
		move_down(s);
	else if (keybind == 65)
		move_left(s);
	else if (keybind == 68)
		move_right(s);
	else if (keybind = 27)
		end(s);
}

void move_up(t_game *s)
{
	if (s->map[s->coord->x][s->coord->y + 1] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x][s->coord->y + 1]))
		s->map[s->coord->x][s->coord->y + 1] += 'P' ;
	else
		s->map[s->coord->x][s->coord->y + 1] = ('P' + '0') ;
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->y += 1
	s->move += 1;
	ft_printf("move : %d", s->move);
}

void move_down(t_game *s)
{
	if (s->map[s->coord->x][s->coord->y - 1] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x][s->coord->y - 1]))
		s->map[s->coord->x][s->coord->y - 1] += 'P' ;
	else
		s->map[s->coord->x][s->coord->y - 1] = ('P' + '0') ;
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->y -= 1;
	s->move += 1;
	ft_printf("move : %d", s->move);
}

void move_left(t_game *s)
{
	if (s->map[s->coord->x - 1][s->coord->y] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x - 1][s->coord->y]))
		s->map[s->coord->x - 1][s->coord->y] += 'P' ;
	else
		s->map[s->coord->x - 1][s->coord->y] = ('P' + '0') ;
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->x -= 1
	s->move += 1;
	ft_printf("move : %d", s->move);
}

void move_right(t_game *s)
{
	if (s->map[s->coord->x + 1][s->coord->y] == "1")
		return ;
	else if (ft_strchr("0E", s->map[s->coord->x + 1][s->coord->y]))
		s->map[s->coord->x + 1][s->coord->y] += 'P' ;
	else
		s->map[s->coord->x + 1][s->coord->y] = ('P' + '0') ;
	if (s->map[s->coord->x][s->coord->y] == ('P' + 'E'))
		s->map[s->coord->x][s->coord->y] == 'E';
	else
		s->map[s->coord->x][s->coord->y] == '0';
	s->coord->x += 1;
	s->move += 1;
	ft_printf("move : %d", s->move);
}
void end(t_game *s)
{
	mlx_destroy_window(s->mlx, s->mlx_win);
	exit_error();
}
//---8---
void put_img(t_game *s)
{
	s->i = 0;
	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (s->map[s->i][s->j] == '1')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->W, 90, 90);
			else if (s->map[s->i][s->j] >= '0'
					&& (s->map[s->i][s->j] != 'E' || s->map[i][j] != ('E' + 'P'))
			{	
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->G, 90, 90);
				s->map[s->i][s->j] -= '0';
			}
			else if (s->map[s->i][s->j] == ('E' + 'P'))
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->E, 90, 90);
			if (s->map[s->i][s->j] == 'P')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->P, 90, 90);
			if (s->map[s->i][s->j] == 'C')
				mlx_put_image_to_window(s->mlx, s->mlx_win, s->img->C, 90, 90);
			s->j++;
		}
		s->i++;
	}
}
