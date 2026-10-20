/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:19:15 by alegome2          #+#    #+#             */
/*   Updated: 2026/07/09 11:28:57 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nb)
{
	long	number; // Para salvar el problema del numero maximo
	char	c;

	number = nb;
	if (number > 0)
	{
		if (number >= 10)
		{
			ft_putnbr(number/10);
		}
		c = number % 10 + '0';
		write(1, &c, 1);
	}
	if (number == 0)
	{
		c = number + '0';
		write(1, &c, 1);
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number = number * (-1);
		if (number >= 10)
		{
			ft_putnbr(number/10);
		}
		c = number % 10 + '0';
		write(1, &c, 1);
	}
}

int	main(void)
{
	int	nb;
	nb = 1450;
	ft_putnbr(nb);
	write(1, "\n", 1);
	return(0);
}
