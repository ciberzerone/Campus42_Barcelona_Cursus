/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:48:12 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/06 19:15:43 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
int main()
{
	char str[] = "Hello, 42 Barcelona!";
	ft_putstr_fd(str, 1); // 1 es el file descriptor para stdout
	return 0;
}
*/
