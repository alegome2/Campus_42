/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intento.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:22:51 by alegome2          #+#    #+#             */
/*   Updated: 2026/07/03 12:49:40 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	printer_char(int n)
{
	char	num;
	if (n >= 10)
	{
		printer_char(n/10);
	}
	num = n % 10 + '0'; 
	write(1, &num, 1);
	return (0);
}

int	main(void)
{
	int	counter;

	counter = 1;
	while (counter <= 100)
	{
		if (counter % 4 == 0 && counter % 7 == 0)
			write(1, "fizzbuzz", 4);
		else if (counter % 4 == 0)
			write(1, "fizz", 4);
		else if (counter % 7 == 0)
			write(1, "buzz", 4);
		else
			printer_char(counter); 
		counter++;
		write(1, "\n", 1);
	}
	return(0);
}
