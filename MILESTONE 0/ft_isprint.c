/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:04:35 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:38 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if ((a >= 32 && a <= 126))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("Devuelve: %i", ft_isascii('a'));
	return (0);
}*/