/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:12:12 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/17 22:28:34 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_split_size(char const *str, char c)
{
	size_t	i;
	size_t	words;
	size_t	chars;
	char	prev;

	i = 0;
	prev = -1;
	chars = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			chars++;
		if (str[i] != c && (prev == c || prev == -1))
			words++;
		prev = str[i];
		i++;
	}
	if (words == 0 && chars > 0)
		words = 1;
	return (words);
}

static inline char	*ft_strdup_split(char const *src, char c, size_t *i)
{
	char	*dst;
	size_t	len;
	size_t	j;

	len = 0;
	while (src[*(i) + len] && src[*(i) + len] != c)
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	j = 0;
	while (j < len)
	{
		dst[j] = src[*(i)];
		j++;
		*(i) = *(i) + 1;
	}
	return (dst);
}

static void	ft_free_split(char **rst, size_t k)
{
	while (k > 0)
	{
		free(rst[k - 1]);
		k--;
	}
	free(rst);
}

static char	**ft_allocate_split(char const *s, char c)
{
	size_t	deep;
	char	**rst;

	deep = ft_split_size(s, c);
	rst = (char **)malloc(sizeof(char *) * (deep + 1));
	if (rst == NULL)
		return (NULL);
	return (rst);
}

char	**ft_split(char const *s, char c)
{
	char	**rst;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	rst = ft_allocate_split(s, c);
	if (rst == NULL)
		return (NULL);
	while (k < ft_split_size(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		rst[k] = ft_strdup_split(s, c, &i);
		if (rst[k] == NULL)
		{
			ft_free_split(rst, k);
			return (NULL);
		}
		k++;
	}
	rst[k] = NULL;
	return (rst);
}
