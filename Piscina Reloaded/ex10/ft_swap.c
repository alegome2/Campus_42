/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:05:11 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/08 11:17:15 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*puntero_a;
	int	*puntero_b;

	a = 10;
	b = 2;
	puntero_a = &a;
	puntero_b = &b;
	printf("Numeros antes del cambio: %i y %i\n", a, b);
	ft_swap(puntero_a, puntero_b);
	printf("Numeros despues del cambio: %i y %i\n", a, b);
	return (0);
}*/
