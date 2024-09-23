/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/07/30 11:34:30 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int main()
{
    char test_chars[] = {'A', 'z', '5', '?', 'm', 'Q'};
    int i;

    for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
    {
        if (ft_isalpha(test_chars[i]))
            printf("'%c' is an alphabetic character.\n", test_chars[i]);
        else
            printf("'%c' is not an alphabetic character.\n", test_chars[i]);
    }

    return 0;
}
*/
