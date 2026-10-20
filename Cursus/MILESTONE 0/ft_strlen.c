/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:17:24 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 17:39:05 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
%zu -> due to size_t
Read string to '\0' and return number of characters
*/

/*int	main(void)
{
	char	*str = "Hola";

	printf("%zu\n", ft_strlen(str));
	return (0);
}*/
