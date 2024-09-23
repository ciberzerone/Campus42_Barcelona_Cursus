/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:31:46 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:00:11 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(total_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, s2, total_len);
	return (new_str);
}
/*
int main() {
    const char *s1 = "Hello, ";
    const char *s2 = "42 Barcelona!";
    char *joined_str;

    joined_str = ft_strjoin(s1, s2);

    if (joined_str != NULL) {
        printf("Joined String: %s\n", joined_str);
        free(joined_str); // No olvides liberar la memoria asignada
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
*/
