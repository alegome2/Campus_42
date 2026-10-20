/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 09:51:25 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/14 12:35:32 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	range;
	int	*num;

	i = 0;
	if (min >= max)
		return (NULL);
	range = max - min;
	num = malloc((range) * sizeof(int));
	if (num == NULL)
		return (NULL);
	while (min < max)
	{
		num[i] = min;
		min++;
		i++;
	}
	return (num);
}

/*int	main(void)
{
	int	min;
	int	max;

	min = 1;
	max = 9;
	ft_range(min, max);
	return (0);
}*/
/* Añadir un printf dentro del while 
 (entre las dos lineas del bucle) para ver
 que recorre los numeros de forma correcta*/

// printf("%d", num[min-1]);
