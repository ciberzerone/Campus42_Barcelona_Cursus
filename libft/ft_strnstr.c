/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:21:18 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[h] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[h] && h < len)
	{
		n = 0;
		while (haystack[h + n] && needle[n] && (h + n) < len
			&& haystack[h + n] == needle[n])
		{
			n++;
		}
		if (needle[n] == '\0')
		{
			return ((char *)haystack + h);
		}
		h++;
	}
	return (0);
}
/*
int main() {
    const char *haystack1 = "Hello, World!";
    const char *needle1 = "World";
    const char *haystack2 = "42 is the answer to life, everything.";
    const char *needle2 = "life";
    const char *haystack3 = "Find the needle in the haystack";
    const char *needle3 = "needle";
    const char *haystack4 = "This is a simple test";
    const char *needle4 = "simple";
    const char *haystack5 = "Another test case";
    const char *needle5 = "none";

    printf("Test 1: %s\n", ft_strnstr(haystack1, needle1, 13)); // "World!"
    printf("Test 2: %s\n", ft_strnstr(haystack2, needle2, 30)); // "everything."
    printf("Test 3: %s\n", ft_strnstr(haystack3, needle3, 25)); // "haystack"
    printf("Test 4: %s\n", ft_strnstr(haystack4, needle4, 20)); // "test"
    printf("Test 5: %s\n", ft_strnstr(haystack5, needle5, 20)); // (null)

    return 0;
}
*/
