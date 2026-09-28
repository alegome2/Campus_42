/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 09:39:14 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:47:37 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	return (0);
}
/*
Read string searching last 'c' when find it return 
this position until the end. If c='\0' return it
*/

/*int main (void)
{
    char *str = "holalampara";
    printf("Cadena copiada: %s", strrchr(str, 'l'));
    return (0);
}*/
