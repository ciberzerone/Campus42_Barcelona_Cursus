/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:45:03 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:19:14 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
/*
char my_function(unsigned int i, char c)
{
    return c + i;
}
int main()
{
    char const *str = "abc";
    char *result = ft_strmapi(str, my_function);

    if (result)
    {
        printf("Original: %s\n", str);
        printf("Modified: %s\n", result);
        free(result); 
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}
*/
