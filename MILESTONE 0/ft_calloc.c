/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:09:29 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:13 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_bytes;
	char	*memory;
	size_t	i;

	total_bytes = nmemb * size;
	if (nmemb == 0 || size == 0)
		memory = (char *)malloc(0);
	else
		memory = (char *)malloc(total_bytes * sizeof(char));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < total_bytes)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}

/*
Reserve memory with malloc and write 0 in this
*/

/*int	main(void)
{
	int	*array;

	// Solo llamamos a ft_calloc (él se encarga de pedir la memoria)
	array = ft_calloc(3, sizeof(int));
	if (!array)
		return (1);
	printf("Casilla 0: %d\n", array[0]);
	printf("Casilla 1: %d\n", array[1]);
	printf("Casilla 2: %d\n", array[2]);

	free(array);
	return (0);
}*/
