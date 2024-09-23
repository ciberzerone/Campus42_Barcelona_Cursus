/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:55:51 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:27:03 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
int main(void)
{
    char src[] = "Hello, 42!";
    char dst[20];
    size_t len;

    len = ft_strlcpy(dst, src, sizeof(dst));
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);
    printf("Length of source: %zu\n", len);

    return 0;
}
*/
