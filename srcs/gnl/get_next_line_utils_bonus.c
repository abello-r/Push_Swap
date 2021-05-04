/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:25:40 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/03 18:49:54 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = ft_strlen(s1);
	s2 = malloc(i + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, i);
	s2[i] = '\0';
	return (s2);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*x;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	x = (char *)malloc(sizeof(char) * len + 1);
	if (!x)
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*x;
	size_t		c1;
	size_t		c2;
	size_t		i;

	i = 0;
	c2 = ft_strlen(s1);
	c1 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!x)
		return (NULL);
	while (c1 != c2)
	{
		x[i] = s1[c1];
		++i && ++c1;
	}
	c2 = 0;
	c1 = ft_strlen(s2);
	while (c2 != c1)
		x[i++] = s2[c2++];
	x[i] = '\0';
	return (x);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
