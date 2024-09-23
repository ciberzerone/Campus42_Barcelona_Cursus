/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:56:44 by ybeltran          #+#    #+#             */
/*   Updated: 2024/09/21 23:09:32 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	handle_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base((unsigned long long)ptr, "0123456789abcdef");
	}
	return (count);
}

int	handle_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		count += handle_pointer(va_arg(args, void *));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
