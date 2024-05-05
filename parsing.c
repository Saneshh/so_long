
#include "so_long.h"

static void    count_element(t_game    *s, int i, int j)
{
        i = 0;
        while (s->map[i])
        {
                j = 0;
                while (s->map[i][j])
                {
                        if (s->map[i][j] == '0')
                                s->ground += 1;
                        else if (s->map[i][j] == '1')
                                s->wall += 1;
                        else if (s->map[i][j] == 'P')
                                s->player += 1;
                        else if (s->map[i][j] == 'E')
                                s->ext += 1;
                        else if (s->map[i][j] == 'C')
                                s->col += 1;
                        j++;
                }
                i++;
        }
        if (s->col == 0 || s->player != 1 || s->ext != 1)
                exit_error(s, "Error\nNeed 1 Player, 1 Exit and 1+ Collectible\n");
}

void    parsing(t_game *s, int i, int j)
{
        s->fd = open(s->folder, O_RDONLY);
        s->map = ft_calloc(s->line + 1, sizeof(char *));
        if (!(s->map))
                exit_error(s, "Error\nAlloc error\n");
        s->map_cpy = ft_calloc(s->line + 1, sizeof(char *));
        if (!s->map_cpy)
                exit_error(s, "Error\nAlloc error\n");
        i = 0;
        while (i < s->line)
        {
                s->map[i] = ft_strtrim(get_next_line(s->fd), "\n");
                if (s->map[i] == NULL)
                        exit_error(s, "Error\nAlloc error\n");
                s->map_cpy[i] = ft_strdup(s->map[i]);
                if (!s->map_cpy[i])
                        exit_error(s, "Error\nAlloc error\n");
                i++;
        }
        free(get_next_line(s->fd));
        close(s->fd);
        if (ft_strlen(s->map[0]) > 500 || s->line > 500)
                exit_error(s, "Error\nMap is too big\n");
        count_element(s, i, j);
}
