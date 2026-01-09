/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:48:40 by bokim             #+#    #+#             */
/*   Updated: 2025/11/25 12:34:48 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	tmp;

	if (n < 0)
	{
		ft_putchar('-');
		ft_putunbr(-n);
	}
	if (n >= 0)
	{
		tmp = n % 10 + '0';
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(tmp);
	}
	return (ft_numlen(n));
}

int	ft_putunbr(unsigned int n)
{
	int	tmp;

	tmp = n % 10 + '0';
	if (n > 9)
		ft_putunbr(n / 10);
	ft_putchar(tmp);
	return (ft_numlen(n));
}

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}
