/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:27:40 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/10 20:03:38 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
/*
int main()
{
int g=  'T';
printf("si es deciminal %d\n",ft_isascii(g));
printf("%c en decimial en ASCII es:  %d\n",g, g);
return 0;
}
*/
