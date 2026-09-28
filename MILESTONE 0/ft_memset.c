/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:42:49 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:47:05 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
Rewrite first n bytes with a character in space
of memory
*/

/*int	main(void)
{
	char	str[10] = "abcdefghi";

	printf("Antes:  %s\n", str);
	ft_memset(str, 'X', 3);
	printf("Despues: %s\n", str);
	return (0);
}*/