/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:21:50 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/28 16:46:05 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if ((nptr[i + 1] == '+') || (nptr[i + 1] == '-'))
			return (0);
		else if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		res = (res * 10) + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

/*
Convert initial portion of string pointer to str
to an interger representation.
Ignore tabulator and sign, if two sign together 
return 0
*/

/*int main(void)
{
    //char    *str = " --42a";
    printf("Res: %i\n", ft_atoi("-a42a"));
    printf("Res: %i\n", ft_atoi(" -+42a"));
    printf("Res: %i\n", ft_atoi(" 42a"));
    printf("Res: %i\n", ft_atoi(" --42a"));
    return (0);
}*/
