/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:23:50 by username          #+#    #+#             */
/*   Updated: 2026/10/02 10:56:26 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst_rest;
	size_t	len_src;
	size_t	size_dst;

	i = 0;
	while (i < size && dst[i])
		i++;
	size_dst = i;
	j = 0;
	if (size == i)
		return (size + ft_strlen(src));
	len_dst_rest = (size - size_dst - 1);
	len_src = ft_strlen(src);
	while ((j < len_dst_rest) && (src[j]))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (size_dst + len_src);
}

/* Join src to the end of dst no overflowing size
add '\0' and return total size of full phrase if
needed space */

/*int	main(void)
{
char	dst1[20] = "Hola";
char	dst2[10] = "Hola";
char	dst3[10] = "Hola";
size_t	ret;

// Caso 1: Espacio suficiente
ret = ft_strlcat(dst1, " mundo", 20);
printf("--- Caso 1: Normal ---\n");
printf("dst: \"%s\" | ret: %zu (esperado: 10)\n\n", dst1, ret);
// Caso 2: Truncamiento (cabe parte de src y el '\\0')
ret = ft_strlcat(dst2, " mundo", 8);
printf("--- Caso 2: Truncado ---\n");
printf("dst: \"%s\" | ret: %zu (esperado: 10)\n\n", dst2, ret);
// Caso 3: size <= longitud inicial de dst (size = 0 o menor que strlen(dst))
ret = ft_strlcat(dst3, " mundo", 0);
printf("--- Caso 3: size = 0 ---\n");
printf("dst: \"%s\" | ret: %zu (esperado: 6)\n", dst3, ret);
return (0);
}*/
