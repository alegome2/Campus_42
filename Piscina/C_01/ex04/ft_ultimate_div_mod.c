/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:28:34 by alegome2          #+#    #+#             */
/*   Updated: 2026/06/25 12:08:16 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
/*
int	main(void)
{
	int	var1;
	int	var2;
	int	*a;
	int	*b;

	var1 = 16;
	var2 = 3;
	a = &var1;
	b = &var2;
	ft_ultimate_div_mod(a, b);
	printf("Division = %i y Modulo = %i\n", *a, *b);
	ft_ultimate_div_mod(a, b);
	printf("Division2 = %i y Modulo2 = %i\n", *a, *b);
}*/
