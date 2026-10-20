/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:26:39 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:41 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
Search character c and return memory adress where is it
*/

/*int main(void)
{
    char    *str = "Hello baby";
    printf("Caracter encontrado en: %p\n", ft_memchr(str, 'b', 8));
    printf("Caracter encontrado: %c\n", *(char *)ft_memchr(str, 'b', 8));
    printf("Resto de la cadena: %s\n", (char *)ft_memchr(str, 'b', 8));
    return (0);
}*/
