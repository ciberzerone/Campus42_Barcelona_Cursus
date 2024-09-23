/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:20:13 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n && ptr1[i] && ptr1[i] == ptr2[i])
	{
		i++;
	}
	if (i < n)
	{
		return (ptr1[i] - ptr2[i]);
	}
	return (0);
}
/*
int main() {
    const char *s1 = "Hello, World!";
    const char *s2 = "Hello, World!";
    const char *s3 = "Hello, 42!";
    const char *s4 = "Hello, Zorld!";
    const char *s5 = "Hello, Wor";

    printf("Test 1: %d\n", ft_strncmp(s1, s2, 13)); // Expected: 0
    printf("Test 2: %d\n", ft_strncmp(s1, s3, 13)); // Expected: positive value
    printf("Test 3: %d\n", ft_strncmp(s1, s4, 13)); // Expected: negative value
    printf("Test 4: %d\n", ft_strncmp(s1, s5, 13)); // Expected: positive value
    printf("Test 5: %d\n", ft_strncmp(s1, s5, 8));  // Expected: 0

    return 0;
}
*/
