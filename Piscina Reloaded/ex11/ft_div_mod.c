/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:21:52 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/08 11:49:38 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*puntero_a;
	int	*puntero_b;

	a = 20;
	b = 7;
	puntero_a = &a;
	puntero_b = &b;
	ft_div_mod(a, b, puntero_a, puntero_b);
	printf("Resultado division = %i\n", *puntero_a);
	printf("Resultado modulo = %i\n", *puntero_b);
}*/
