/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:46:16 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:45:54 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*duplicate;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	duplicate = (char *)malloc((len + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (i < len)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
/*
Reserve memory with malloc of string size +1('\0') 
and copy the char string. Then free memory
*/

/*int main(void)
{
    char    *str = "Hola";
    char    *dup;

    dup = ft_strdup(str);
    printf("Duplicado: %s\n", dup);
    free(dup);
    return (0);
}*/
