/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:21:30 by alegome2          #+#    #+#             */
/*   Updated: 2026/07/03 11:47:33 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_lowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_lowcase(str);
	while (str[i] != '\0')
	{
		if ((str[i] >= 32 && str[i] <= 47)
			|| (str[i] >= 91 && str[i] <= 96)
			|| (str[i] >= 58 && str[i] <= 64))
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
				str[i] = str[i] - 32;
			i++;
			while (str[i] >= 'a' && str[i] <= 'z')
			{
				if (str[i] >= 48 && str [i] <= 57)
					i++;
				i++;
			}
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "¿hoLa c0mo es+tas?";
	printf("%s\n", str);
	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}*/
