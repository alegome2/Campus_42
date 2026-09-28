/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:47:36 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:47:34 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < len && big[j])
	{
		i = 0;
		while ((j + i < len) && big[j + i] != '\0' && little[i] == big[j + i])
		{
			i++;
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
		j++;
	}
	return (0);
}

/*
Search little string inside big string and return first 
coincidence to the end of big string
*/

/*int main(void)
{
    const char *big = "FooBa Barra Baz";
    const char *little = "Barra";
    printf("Coincidencia: %s", ft_strnstr(big, little, 12));
    return(0);
}*/
