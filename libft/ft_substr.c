/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:42:04 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:23:12 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
// Declaración de la función ft_substr
char	*ft_substr(const char *s, unsigned int start, size_t len);

int main() {
    const char str[] = "Hello, 42 Barcelona!";
    char *substr;

    // Extraer una subcadena desde la posición 7 con longitud 2
    substr = ft_substr(str, 10, 4);

    if (substr != NULL) {
        printf("Original: %s\n", str);
        printf("Substring: %s\n", substr);
        free(substr); // No olvides liberar la memoria asignada
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
*/
