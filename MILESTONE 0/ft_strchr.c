/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/23 13:58:35 by alegome2         #+#    #+#              */
/*   Updated: 2026/10/02 17:15:35 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *) & s[i]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	return (0);
}
/*
Read string searching first 'c' when find it return
this position until the end. If c='\0' return it
*/

/*int	main(void)
{
char	*str = "holalampara";

printf("Cadena copiada: %s", strchr(str, 'l'));
return (0);
}*/
