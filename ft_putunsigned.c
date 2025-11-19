/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:51:36 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/19 23:54:40 by klucchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int count;
	
	count = 0;

	if (n < 0)
	{
		write (1, "4294967294", 10);
		return (10);
	}
	if (n > 9)
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	else
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}
