/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: an-zue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 00:11:24 by an-zue            #+#    #+#             */
/*   Updated: 2020/10/05 01:24:29 by an-zue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	return ((*s == c) ? (char *)s : NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *s)
{
	char	*cpy;
	char	*ptr;

	if (!s)
		return (NULL);
	if (!(cpy = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ptr = cpy;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (cpy);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ptr = s3;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s3);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = str;
	while (s[start] && len--)
		*ptr++ = s[start++];
	*ptr = '\0';
	return (str);
}
