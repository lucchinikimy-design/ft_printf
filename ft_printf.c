/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:03:57 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/19 23:55:03 by klucchin         ###   ########.fr       */
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

int ft_printf(const char *format, ...)
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
		format++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
//
// int	main()
// {
// 	char *str;
// 	int	i;
// 	char c;
// 	int ret;
// 	int hex;
// 	unsigned int u;
// 	void *ptr;

// 	ptr = 	NULL;
// 	c = 'a';
// 	i = -2146;
// 	str = "hello world, how are you ?";
// 	hex = 26;
// 	u = -1309;
// 	ret = ft_printf("char is = %c\n", str);
// 	ft_printf("returned = %d\n", ret);
// 	printf("char is = %c\n", str);
// 	return (0);
// }
