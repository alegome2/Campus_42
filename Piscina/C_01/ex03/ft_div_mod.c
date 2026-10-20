/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:31:57 by alegome2          #+#    #+#             */
/*   Updated: 2026/06/24 14:13:01 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	var1;
	int	var2;
	int	*puntero_1;
	int	*puntero_2;

	var1 = 10;
	var2 = 2;
	puntero_1 = &var1;
	puntero_2 = &var2;
	ft_div_mod(var1, var2, puntero_1, puntero_2);
	printf("Division = %i, Modulo = %i\n", *puntero_1, *puntero_2);
}*/
