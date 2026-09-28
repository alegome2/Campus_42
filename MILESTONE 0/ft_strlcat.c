/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:23:50 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 17:38:41 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while ((j < size - 1) && (src[j]))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (i);
}

/* Copy size characters from src continue to dst

/*int	main(void)
{
	char	dst[20] = "Hola ";
	char	src[] = "12345678910abcdefghijklmnñopqrstuvwxyz";

	ft_strlcat(dst, src, 20);

	printf("%s\n", dst);

	return (0);
}*/
