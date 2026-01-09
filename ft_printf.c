/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:28 by bokim             #+#    #+#             */
/*   Updated: 2026/01/09 17:48:13 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_format(char c) //function to check if the char is one of the formatt specifiers
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	add_prefix(void *arg)	//function that adds 0x prefix for address
{

	if (arg == 0)
		return(ft_putstr("(nil)"));
	ft_putstr("0x");
	return(ft_putadd((unsigned long)arg) + 2);
}

static int	sort_type(const char c, va_list arg)
{
	if (c == 'c')
		return(ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return(ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return(add_prefix(va_arg(arg, void *)));
	else if (c == 'd' || c == 'i')
		return(ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return(ft_putunbr(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return(ft_puthex(c, va_arg(arg, unsigned int)));
	else if (c == '%')
		return(ft_putchar(c));
	return(0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && is_format(format[i + 1]))
		{
			count += sort_type(format[i + 1], arg);
			i = i + 2;
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(arg);
	return (count);
}
