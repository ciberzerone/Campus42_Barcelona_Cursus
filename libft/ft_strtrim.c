/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:30:02 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:22:09 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*mem;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]))
		len--;
	mem = ft_substr(s1, 0, len + 1);
	return (mem);
}
/*
int main() {
    const char *s1 = "  Hello, 42 Barcelona!  ";
    const char *set = " ";
    char *trimmed_str;

    trimmed_str = ft_strtrim(s1, set);

    if (trimmed_str != NULL) {
        printf("Original String: '%s'\n", s1);
        printf("Trimmed String: '%s'\n", trimmed_str);
        free(trimmed_str); // No olvides liberar la memoria asignada
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
*/
