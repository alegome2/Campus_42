/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:44:05 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:50 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

/*
Copy n bytes of src and rewrite in dest
*/

/*int main(void)
{
    char    s1[8] = "Mundo";
    char    s2[8] = "Hola!";
    printf("Result: %s\n", (char *)ft_memcpy(s2, s1, 4));
}*/
