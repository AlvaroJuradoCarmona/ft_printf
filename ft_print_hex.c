/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:38:34 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/27 13:10:59 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned int n, const char c)
{
	int	len;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		len = 1;
	}
	else
	{
		if (n >= 16)
		{
			ft_printhex(n / 16, c);
			ft_printhex(n % 16, c);
		}
		else
		{
			if (c == 'x')
				ft_putchar_fd("0123456789abcdef"[n], 1);
			else
				ft_putchar_fd("0123456789ABCDEF"[n], 1);
		}
		len = ft_hex_len(n);
	}
	return (len);
}

static int	ft_ptr_len(unsigned long n)
{
	unsigned long	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_printptr(unsigned long n, const char c)
{
	unsigned long	len;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		len = 1;
	}
	else
	{
		if (n >= 16)
		{
			ft_printptr(n / 16, c);
			ft_printptr(n % 16, c);
		}
		else
		{
			if (c == 'x')
				ft_putchar_fd("0123456789abcdef"[n], 1);
			else
				ft_putchar_fd("0123456789ABCDEF"[n], 1);
		}
		len = ft_ptr_len(n);
	}
	return (len);
}

int	ft_print_pointer(unsigned long long ptr)
{
	unsigned long	len;

	len = 2;
	write(1, "0x", 2);
	len += ft_printptr(ptr, 'x');
	return (len);
}
