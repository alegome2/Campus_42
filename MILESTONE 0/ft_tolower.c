/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_tolower.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/24 17:30:04 by alegome2         #+#    #+#              */
/*   Updated: 2026/10/02 17:16:15 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c = c + 32);
	else
		return (c);
}

/*
Receive a character like an int doing de lowcase
and return it
*/

/*int main(void)
{
char    c;

c = 'H';
printf("Letra: %c\n", ft_tolower(c));
return (0);
}*/
