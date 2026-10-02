/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_toupper.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/24 17:18:39 by alegome2         #+#    #+#              */
/*   Updated: 2026/10/02 17:16:16 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	else
		return (c);
}

/*
Receive a character like an int doing de upcase
and return it
*/

/*int main(void)
{
char    c;

c = 'b';
printf("Letra: %c\n", ft_toupper(c));
return (0);
}*/
