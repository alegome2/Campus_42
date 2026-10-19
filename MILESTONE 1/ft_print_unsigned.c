/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_unsigned.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 17:43:14 by username         #+#    #+#              */
/*   Updated: 2026/10/19 18:14:59 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nb)
{
	int		counter;
	char	c;

	counter = 0;
	if (nb >= 10)
		counter += ft_print_unsigned(nb / 10);
	c = (nb % 10) + '0';
	counter += write(1, &c, 1);
	return (counter);
}
