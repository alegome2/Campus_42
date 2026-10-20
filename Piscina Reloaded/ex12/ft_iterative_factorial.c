/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:02:35 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/09 16:27:04 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		while (nb > 0)
		{
			result = result * nb;
			nb--;
		}
		return (result);
	}
}

/*int	main(int argc, char **argv)
{
	int	nb;

	printf("Result: %i\n", ft_iterative_factorial(atoi(argv[1])));
	return (0);
}*/
