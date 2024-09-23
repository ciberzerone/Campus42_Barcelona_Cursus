/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:22:44 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 17:36:06 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main()
{
    int i = 'g';
    printf("dato: %d\n", ft_isprint(i));
    printf("dato: %c\n", i);
    printf("El valor ASCII de '%c' es: %d\n", i, i);
    printf("dato: %x\n", ft_isprint(i));
    printf("direccion de memoria: %p\n", (void*)&i);
    return 0;
}
*/
