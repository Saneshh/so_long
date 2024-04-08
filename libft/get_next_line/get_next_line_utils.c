/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:45:05 by hsolet            #+#    #+#             */
/*   Updated: 2024/01/14 05:28:42 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s && !*s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (unsigned char)c && s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return (((char *)s) + i);
	else
		return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (nmemb != 0 && size != 0 && (size * nmemb) / nmemb != size)
		return (NULL);
	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

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
