/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:26:59 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/17 22:27:25 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}
/*
int main() {
    const char str[] = "Hello, 42 Barcelona!";
    char ch = '2';
    char *result;

    result = ft_strchr(str, ch);

    if (result != NULL)
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    else
        printf("Character '%c' not found in the string.\n", ch);

    return 0;
}
*/
