/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:44:40 by alegome2          #+#    #+#             */
/*   Updated: 2026/06/26 11:19:02 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	i = 0;
	while (tab[i] <= size)
	{
		while(tab[size] >= tab[0])
			{
				printf("%i", *tab);
				size--;
			}
		i++;
	}
}

int	main(void)
{
	int	size;
	int	tab[] = {0, 1, 2, 3, 4};
	size = 5;

	ft_rev_int_tab(tab, size);
	return (0);
}

