/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_int.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/16 14:10:37 by username         #+#    #+#              */
/*   Updated: 2026/10/19 19:25:11 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	*str;
	int		counter;

	str = ft_itoa(n);
	if (!str)
		return (0);
	counter = ft_print_str(str);
	free(str);
	return (counter);
}
