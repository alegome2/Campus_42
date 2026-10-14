/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:36:56 by alegome2          #+#    #+#             */
/*   Updated: 2026/10/14 14:58:06 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = counter + ft_print_char(va_arg(args, int));
	else if (c == 's')
		else if (c == 'p')
		else if (c == 'd')
		else if (c == 'i')
		else if (c == 'u')
		else if (c == 'x')
		else if (c == 'X')
		else(c == '%')
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		total;
	va_list	args;

	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_format(str, args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			total++;
		}
		i++;
	}
	va_end(args);
	total = total + check_format(str[i + 1], args);
	return (total);
}
