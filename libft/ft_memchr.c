/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/04 17:57:44 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	c = (unsigned char)c;
	while (n && *ptr != c)
	{
		++ptr;
		--n;
	}
	if (n)
	{
		return ((void *)ptr);
	}
	else
	{
		return (NULL);
	}
}
/*
int main() {
    const char s[] = "Hello, World!";
    int c1 = 'W';
    int c2 = 'z';
    int c3 = '\0';

    char *result1 = ft_memchr(s, c1, 13);
    char *result2 = ft_memchr(s, c2, 13);
    char *result3 = ft_memchr(s, c3, 13);

    if (result1) {
        printf("Test 1: %s\n", result1); // Expected: "World!"
    } else {
        printf("Test 1: (null)\n");
    }

    if (result2) {
        printf("Test 2: %s\n", result2); // Expected: (null)
    } else {
        printf("Test 2: (null)\n");
    }

    if (result3) {
        printf("Test 3: %s\n", result3); // Expected: ""
    } else {
        printf("Test 3: (null)\n");
    }

    return 0;
}
*/
