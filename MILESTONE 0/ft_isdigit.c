/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:16:41 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:34 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (n >= 0 && n <= 9)
		return (1);
	return (0);
}

/*int	main(void)
{
	int num;

	num = 1;
	printf("Devuelve: %d", ft_isdigit(num));
	return (0);
}*/
