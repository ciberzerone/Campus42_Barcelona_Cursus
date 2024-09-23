/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 18:15:36 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
/*
int main() {
    char c1 = 'a';
    char c2 = 'z';
    char c3 = 'A';
    char c4 = 'Z';
    char c5 = '1';

    printf("Test 1: %c -> %c\n", c1, ft_toupper(c1)); // Expected: a -> A
    printf("Test 2: %c -> %c\n", c2, ft_toupper(c2)); // Expected: z -> Z
    printf("Test 3: %c -> %c\n", c3, ft_toupper(c3)); // Expected: A -> A
    printf("Test 4: %c -> %c\n", c4, ft_toupper(c4)); // Expected: Z -> Z
    printf("Test 5: %c -> %c\n", c5, ft_toupper(c5)); // Expected: 1 -> 1

    return 0;
}
*/
