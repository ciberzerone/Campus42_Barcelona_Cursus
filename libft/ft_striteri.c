/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:17:43 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:14:30 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, (s + i));
		++i;
	}
}
/*
void to_upper(unsigned int i, char *c)
{
    (void)i; 
    *c = toupper(*c);
}

int main()
{
    char str[] = "hello world";
    ft_striteri(str, to_upper);
    printf("%s\n", str);  
    return 0;
}
*/
