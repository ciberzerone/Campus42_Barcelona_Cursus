/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:40:32 by ybeltran          #+#    #+#             */
/*   Updated: 2024/09/21 23:10:51 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int				count;
	unsigned long	base_len;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= (unsigned int)base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}
