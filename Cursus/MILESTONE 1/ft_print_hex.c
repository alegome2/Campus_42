/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_hex.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/17 13:06:46 by username         #+#    #+#              */
/*   Updated: 2026/10/19 18:20:47 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long nb, char *base)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
		counter += ft_print_hex(nb / 16, base);
	counter += write(1, &base[nb % 16], 1);
	return (counter);
}
