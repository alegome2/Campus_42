/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:45:17 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:45 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((i < n) && (str1[i] == str2[i]))
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

/*
Compare memory adress in n bytes and 
return character different
*/

/*int main(void)
{
    char    *s1 = "Hola";
    char    *s2 = "Hoja";
    printf("Result: %i\n",ft_memcmp(s1, s2, 4));    
}*/
