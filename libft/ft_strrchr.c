/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/07/16 18:10:51 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h> */
#include "libft.h"
#include <stddef.h>
/*
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s && s[count] != '\0')
	{
		count++;
	}
	return (count);
}
*/
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*
int main(void)
{
    const char str[] = "te ";
    int ch = '\0';
    char *result;

    result = ft_strrchr(str, ch);
    if (result != NULL)
        printf("The last occurrence of '\\0' in \"%s\" 
                is at position: %ld\n", str, result - str);
    else
        printf("Character '\\0' not found in \"%s\"\n", str);

    return 0;
}
*/
