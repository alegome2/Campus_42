/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:33:44 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:53 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!(unsigned char *)dest && !(unsigned char *)src) || n == 0)
		return ((unsigned char *)dest);
	if ((unsigned char *)dest > (unsigned char *)src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	if ((unsigned char *)src > (unsigned char *)dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return ((unsigned char *)dest);
}

/*
Copy a adress memory in other avoiding overlap
Copy n bytes in (str + X)position
*/

/*int	main(void)
{
	char s1[20] = "123456789";
	char s2[20] = "123456789";

	// Prueba solapamiento a la derecha
	ft_memmove(s1 + 2, s1, 5);
	printf("Solapamiento derecha: %s (esperado: 121234589)\n", s1);

	// Prueba solapamiento a la izquierda
	ft_memmove(s2, s2 + 2, 5);
	printf("Solapamiento izquierda: %s (esperado: 345676789)\n", s2);

	return (0);
}*/