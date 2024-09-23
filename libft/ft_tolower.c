/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 18:12:56 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
/*
int main() {
    char c1 = 'A';
    char c2 = 'Z';
    char c3 = 'a';
    char c4 = 'z';
    char c5 = '1';
    char c6 = '%';

    printf("Test 1: %c -> %c\n", c1, ft_tolower(c1)); // Expected: A -> a
    printf("Test 2: %c -> %c\n", c2, ft_tolower(c2)); // Expected: Z -> z
    printf("Test 3: %c -> %c\n", c3, ft_tolower(c3)); // Expected: a -> a
    printf("Test 4: %c -> %c\n", c4, ft_tolower(c4)); // Expected: z -> z
    printf("Test 5: %c -> %c\n", c5, ft_tolower(c5)); // Expected: 1 -> 1
    printf("Test 6: %c -> %c\n", c6, ft_tolower(c6)); // no cambia 	
    return 0;
}
*/
