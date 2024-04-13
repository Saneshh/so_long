/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:18:09 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/13 12:02:22 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*stcat;
	size_t	len1;

	i = 0;
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	stcat = ft_calloc((len1 + ft_strlen(s2) + 1), sizeof(char));
	if (stcat == NULL)
		return (NULL);
	while (i < len1)
	{
		stcat[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		stcat[len1 + i] = s2[i];
		i++;
	}
	free(s1);
	return (stcat);
}
