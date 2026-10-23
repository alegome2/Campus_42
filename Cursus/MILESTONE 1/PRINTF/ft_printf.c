/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:36:56 by username          #+#    #+#             */
/*   Updated: 2026/10/20 19:09:38 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = counter + ft_print_char(va_arg(args, int));
	else if (c == 's')
		counter = counter + ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		counter = counter + ft_print_ptr(va_arg(args, void *));
	else if ((c == 'd') || (c == 'i'))
		counter = counter + ft_print_int(va_arg(args, int));
	else if (c == 'u')
		counter = counter + ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		counter += ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		counter += ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		counter = counter + ft_print_char('%');
	return (counter);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		total;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			total += check_format(str[++i], args);
		else
			total += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (total);
}
