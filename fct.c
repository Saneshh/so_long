void parsing(int fd, t_game *s)
{
	s->i = 0;
	while (s->i < s->line)
	{
		s->map[s->i] = ft_split(get_next_line(fd), ' ');
		s->map_cpy[s->i] = ft_strdup[s->i];
		s->i++;
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

void init_struct(t_game *s, int fd)
{
	int read_size;
	char *buffer;

	s->i = 0;
	buffer = ft_calloc(SSIZE_MAX, sizeof(char));
	if (!buffer)
		return ;
	s->ground = 0;
	s->wall = 0;
	s->P = 0;
	s->E = 0;
	s->C = 0;
	s->line = 0;
	read_size = read(fd, buffer, SSIZE_MAX);
	while (buffer[i])
	{
		if (buffer[s->i] == '\n' && buffer[s->i - 1] && buffer[s->i - 1] != '\n')
			s->line += 1;
		s->i++;
	}
	free(buffer);
	s->map = ft_calloc(s->line, sizeof(char *));
	if (!(s->map))
		return ;
}
int check_map(t_game *s)
{
	s->i = 0;
	s->j = 0;
	int k;

	while (s->map[s->i])
	{
		s->j = 0;
		while (s->map[s->i][s->j])
		{
			if (!ft_strncmp(s->map[s->i][s->j], "01PEC", 5))
			exit_error();
			if (ft_strncmp(s->map[s->i][s->j], "P", 1))
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
		}
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
				exit_error();
			s->j++;
		}
		s->i++;
	}
	if (s->C == 0 || s->P != 1 || s-> E != 1)
		exit_error(s, "Missing Player, Collectible or Exit");
}

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
