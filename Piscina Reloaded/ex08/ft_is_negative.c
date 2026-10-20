/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:28:35 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/08 12:51:49 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char num);

void	ft_is_negative(int num)
{
	if (num >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

/*int	main(void)
{
	int	num;

	num = 4;
	ft_is_negative(num);
	return (0);
}*/
