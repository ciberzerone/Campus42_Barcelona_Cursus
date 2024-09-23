/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/07/10 16:17:48 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int main() {
    const char s1[] = "Hello, World!";
    const char s2[] = "Hello, World!";
    const char s3[] = "Hello, 42!";
    const char s4[] = "Hello, Zorld!";

    printf("Test 1: %d\n", ft_memcmp(s1, s2, 13));  // Expected: 0
    printf("Test 2: %d\n", ft_memcmp(s1, s3, 13));  // Expected: positive value
    printf("Test 3: %d\n", ft_memcmp(s1, s4, 13));  // Expected: negative value
    printf("Test 4: %d\n", ft_memcmp(s1, s4, 7));   // Expected: 0 (7 bytes)
    return (0);
}
*/
