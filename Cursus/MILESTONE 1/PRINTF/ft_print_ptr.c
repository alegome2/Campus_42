/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:04:12 by username          #+#    #+#             */
/*   Updated: 2026/10/19 19:22:25 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				counter;

	if (!ptr)
		return (write(1, "(nil)", 5));
	counter = write(1, "0x", 2);
	addr = (unsigned long) ptr;
	counter += ft_print_hex(addr, "0123456789abcdef");
	return (counter);
}
