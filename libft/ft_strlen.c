/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:17:40 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/17 22:23:49 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int main()
{
   char s[18] = "Hola todos";

   printf( "s=%s\n", s );
   printf( "ft_strlen(s) = %zu\n", ft_strlen(s));

   return 0;
}
*/
