/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:24:52 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/15 17:45:11 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int	main(void)
{
	int	*a;
	int	*b;
	
	*a = 5;
	*b = 4;

	ft_putchar('a');
	ft_putstr("HOLA");
	printf("Resultado: %i\n",ft_strcmp("hola", "Hola caracola"));
	printf("Longitud string: %i\n", ft_strlen("Alejandro"));
	ft_swap(a, b);
	printf("Cambio 5 por 4: %i y %i\n", *a, *b);
	return (0);
}
