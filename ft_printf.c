/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:03:57 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/24 17:41:26 by klucchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int dispatch(char c, va_list a)
{
	if (c == 'c')
		return ft_putchar(va_arg(a, int));
	if (c == 's')
		return ft_putstr(va_arg(a, char *));
	if (c == 'd' || c == 'i')
		return ft_putnbr(va_arg(a, int));
	if (c == 'u')
		return ft_putunsigned(va_arg(a, unsigned int));
	if (c == 'x' || c == 'X')
		return ft_print_hex(va_arg(a, unsigned int), c);
	if (c == 'p')
		return ft_print_ptr(va_arg(a, unsigned long));
	if (c == '%')
		return write(1, "%", 1);
	return (0);
}

int ft_printf(const char *format,...) 
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += dispatch(*format, args);
		}
		else
			count += write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main()
{
	char *str;
	int	i;
	int d;
	char c;
	int ret;
	int ret2;
	int hex;
	unsigned int u;
	void *ptr;

	ptr = "5";
	c = 'a';
	i = -42;
	d = 42;
	str = "hello world, how are you ?";
	hex = 26;
	u = -1309;
	ret = ft_printf("Hello world %i %d\n", d, i);
	ft_printf("returned = %d\n", ret);
	ret2 = printf("Hello World %i %d\n", i, d);
	printf("returned = %d\n", ret2);
	return (0);
}
