/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:47:36 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/08 12:52:43 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_coord
{
	int	*x;
	int	*y;
}	t_coord

typedef struct s_count
{
	int C;
	int	P;
	int E;
	int wall;
	int ground;
}	t_count

typedef	struct s_player
{

} t_player

#endif
