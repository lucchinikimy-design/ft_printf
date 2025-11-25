/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:27:45 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:34 by klucchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_ptr(unsigned long n)
{
	int		count;
	char	*digits;
	char	c;

	count = 0;
	digits = "0123456789abcdef";
	if (n >= 16)
		count += find_ptr(n / 16);
	c = digits[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_ptr(unsigned long p)
{
	int	count;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	count += write(1, "0x", 2);
	count += find_ptr(p);
	return (count);
}
