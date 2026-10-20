/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:39:18 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/09 17:00:33 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	x;
	int	raiz;

	x = 1;
	while (x < nb && x < 46340)
	{
		raiz = x * x;
		if (raiz == nb)
			return (x);
		else
			x++;
	}
	return (0);
}

/*int	main(void)
{
	printf("La raiz es: %i\n", ft_sqrt(16));
	return (0);
}*/
