/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:43:48 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:12:45 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;	
	char	*dup;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}
/*
// Declaración de ft_strdup
char	*ft_strdup(const char *s);

int main() {
    const char str[] = "Hello, 42 Barcelona!";
    char *dup_str;

    dup_str = ft_strdup(str);

    if (dup_str != NULL) {
        printf("Original: %s\n", str);
        printf("Duplicate: %s\n", dup_str);
        free(dup_str); // No olvides liberar la memoria asignada
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
*/
