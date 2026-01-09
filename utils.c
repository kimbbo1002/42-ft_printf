/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:00 by bokim             #+#    #+#             */
/*   Updated: 2026/01/09 17:44:01 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return(ft_putstr("(null)"));
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putadd(unsigned long n)
{
	int	tmp;
	int	count;

	count = 0;
	tmp = n % 16;
	if (n >= 16)
		count = ft_putadd(n / 16);
	count += ft_puthex('x', tmp);
	return (count);
}

int	ft_puthex(char c, unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(c, n / 16);
	ft_putchar(base[n % 16]);
	return (count + 1);
}
