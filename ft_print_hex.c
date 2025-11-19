/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klucchin <klucchin@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:41:08 by klucchin          #+#    #+#             */
/*   Updated: 2025/11/19 23:55:12 by klucchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int find_hex(unsigned int n, const char *digits)
{
    int count;

    count = 0;
    if (n >= 16)
        count += find_hex(n / 16, digits);
    char c = digits[n % 16];
    count += write(1, &c, 1);
    return (count);
}

int ft_print_hex(unsigned int n, const char spec)
{
    if (spec == 'x')
        return (find_hex(n, "0123456789abcdef"));
    return (find_hex(n, "0123456789ABCDEF"));
}
