/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:24:25 by bokim             #+#    #+#             */
/*   Updated: 2026/01/09 17:36:00 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes
# include <stdarg.h>
# include <unistd.h>

//ft_printf.c
int	ft_printf(const char *format, ...);

//utils
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(char c, unsigned int n);
int	ft_putadd(unsigned long n);
int	ft_numlen(long n);

#endif