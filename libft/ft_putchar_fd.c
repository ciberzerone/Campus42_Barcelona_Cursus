/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:36:35 by ybeltran          #+#    #+#             */
/*   Updated: 2024/08/06 19:13:02 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
    // Ejemplo de uso de la función ft_putchar_fd
    ft_putchar_fd('A', 1); // Escribe 'A' en la salida estándar (stdout)
    ft_putchar_fd('\n', 1); // Escribe un salto de línea en la salida estándar

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    ft_putchar_fd('B', fd); // Escribe 'B' en el archivo output.txt
    ft_putchar_fd('\n', fd); // Escribe un salto de línea en el archivo

    close(fd); // Cierra el archivo

    return 0;
}
*/
