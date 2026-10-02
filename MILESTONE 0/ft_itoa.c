/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/01 12:23:36 by alegome2         #+#    #+#              */
/*   Updated: 2026/10/02 17:15:04 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getLen(long nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb = -nb;
		counter++;
	}
	if (nb == 0)
		counter = 1;
	else
	{
		while (nb > 0)
		{
			nb = nb / 10;
			counter++;
		}
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = getLen(nb);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len > (n < 0))
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

/*
Convert a int to a char
*/

/*int	main(void)
{
printf("Itoa: %s\n", ft_itoa(12547));
return (0);
}*/
