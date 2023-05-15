/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:03:00 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/27 13:12:44 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_printdec(int n)
{
	int	len;

	ft_putnbr_fd(n, 1);
	len = ft_numlen(n);
	return (len);
}

static int	ft_flaglength(va_list args, char c)
{
	int	length;

	length = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		length = ft_printstring(va_arg(args, char *));
	else if (c == 'p')
		length = ft_print_pointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		length = ft_printdec(va_arg(args, int));
	else if (c == 'u')
		length = ft_printunsig(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		length = ft_printhex(va_arg(args, unsigned int), c);
	else
		ft_putchar_fd(c, 1);
	return (length);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			len++;
			ft_putchar_fd(str[i], 1);
		}
		else
			len += ft_flaglength(args, str[++i]);
		i++;
	}
	va_end(args);
	return (len);
}
