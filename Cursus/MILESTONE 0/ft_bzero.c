/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:47:29 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:09 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*
Rewrite n bytes with 0 or character \0
char *str = "hola"; -> Only read permission
char str[10] = "hola"; -> Read & write permission
*/

/*int	main(void)
{
	char str[10] = "Hola";

	printf("Antes: %s\n", str);
	ft_bzero(str, 2);
	printf("Despues: %s\n", str);
	printf("Tercera letra intacta: %c\n", str[2]);
	return (0);
}*/