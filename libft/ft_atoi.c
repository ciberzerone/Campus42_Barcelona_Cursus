/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:05:21 by ybeltran          #+#    #+#             */
/*   Updated: 2024/07/30 14:34:56 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
/*
int main() 
{
    const char *test1 = "42";
    const char *test2 = "   -1234";
    const char *test3 = "   +5678";
    const char *test4 = "   9876543210";
    const char *test5 = "   -9876543210";
    const char *test6 = "  2147483647";   // INT_MAX
    const char *test7 = "  -2147483648";  // INT_MIN
    const char *test8 = "abc123";
    const char *test9 = "123abc";
    const char *test10 = "";

    printf("Test 1: \"%s\" -> %d\n", test1, ft_atoi(test1));
    printf("Test 2: \"%s\" -> %d\n", test2, ft_atoi(test2));
    printf("Test 3: \"%s\" -> %d\n", test3, ft_atoi(test3));
    printf("Test 4: \"%s\" -> %d\n", test4, ft_atoi(test4));
    printf("Test 5: \"%s\" -> %d\n", test5, ft_atoi(test5));
    printf("Test 6: \"%s\" -> %d\n", test6, ft_atoi(test6));
    printf("Test 7: \"%s\" -> %d\n", test7, ft_atoi(test7));
    printf("Test 8: \"%s\" -> %d\n", test8, ft_atoi(test8));
    printf("Test 9: \"%s\" -> %d\n", test9, ft_atoi(test9));
    printf("Test 10: \"%s\" -> %d\n", test10, ft_atoi(test10));

    return (0);
}
*/
