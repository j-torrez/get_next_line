/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:37:01 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/05/29 18:39:50 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*copy;

	size = (ft_strlen(s1) + 1);
	copy = (char *)malloc(sizeof(char) * size);
	if (!copy)
	{
		return (0);
	}
	i = 0;
	while (i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		if (s[i] == '\0')
		{
			if ((char)c == '\0')
				return ((char *)s + i);
			else
				break ;
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab))
		return (NULL);
	count = 0;
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
