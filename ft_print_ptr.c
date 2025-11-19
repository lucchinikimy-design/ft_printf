/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:27:45 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/19 23:55:08 by klucchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int find_ptr(unsigned long n)
{
    int count;

    count = 0;
    if (n >= 16)
        count += find_ptr(n / 16);
    {
        char *digits = "0123456789abcdef";
        char c = digits[n % 16];
        count += write(1, &c, 1);
    }
    return (count);
}

int ft_print_ptr(unsigned long p)
{
    int count;

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
