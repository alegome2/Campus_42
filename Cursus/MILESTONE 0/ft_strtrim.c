/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/29 18:23:48 by alegome2         #+#    #+#              */
/*   Updated: 2026/10/02 17:16:04 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while ((end >= start) && ft_strchr(set, s1[end]))
		end--;
	trim = ft_substr(s1, start, (end - start + 1));
	return (trim);
}

/*
Trim a string removing the specified characters
leaving everything in between intact
*/

/*int	main(void)
{
char	*res1;
char	*res2;
char	*res3;

// Caso 1: Espacios y caracteres al inicio y final
res1 = ft_strtrim("...hola mundo...", ".");
printf("Test 1: [%s]\n", res1);
free(res1);

// Caso 2: La cadena solo contiene caracteres del set
res2 = ft_strtrim("xxxx", "x");
printf("Test 2: [%s]\n", res2);
free(res2);

// Caso 3: Nada que recortar
res3 = ft_strtrim("42 Malaga", "x");
printf("Test 3: [%s]\n", res3);
free(res3);

return (0);
}*/
