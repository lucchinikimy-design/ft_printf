/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:13:00 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/13 18:44:00 by klucchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		ft_putstr(format[i]);
		i++;
	}
	
	va_end(args);
}
