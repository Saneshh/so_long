/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:00:18 by hsolet            #+#    #+#             */
/*   Updated: 2024/04/13 13:37:24 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	new_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	free(s);
	str[i] = '\0';
	return (str);
}
