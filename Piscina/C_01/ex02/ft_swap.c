/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:01:42 by alegome2          #+#    #+#             */
/*   Updated: 2026/06/24 13:30:57 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	save;

	save = *a;
	*a = *b;
	*b = save;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	*puntero_a;
	int	*puntero_b;

	a = 1;
	b = 2;
	puntero_a = &a;
	puntero_b = &b;
	ft_swap(puntero_a, puntero_b);
	printf("El valor de a es: %i y el de b es: %i\n", a, b);
}*/
