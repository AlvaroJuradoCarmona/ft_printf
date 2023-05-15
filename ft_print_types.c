/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:05:44 by ajurado-          #+#    #+#             */
/*   Updated: 2023/01/27 13:29:19 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unslen(unsigned int n)
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

static char	*ft_itoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = ft_unslen(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_printstring(char *str)
{
	int	len;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		len = 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}

int	ft_printunsig(unsigned int n)
{
	int		len;
	char	*num;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		len = 1;
	}
	else
	{
		num = ft_itoa(n);
		len = ft_printstring(num);
		free(num);
	}
	return (len);
}
