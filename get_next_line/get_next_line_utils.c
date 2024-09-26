/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:12:12 by ybeltran          #+#    #+#             */
/*   Updated: 2024/09/24 18:53:08 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;

	len1 = strlen(s1);
	len2 = strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	strcpy(joined, s1);
	strcat(joined, s2);
	return (joined);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	return (memcpy(dup, s, len));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
