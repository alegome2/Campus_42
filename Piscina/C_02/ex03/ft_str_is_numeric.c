/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:06:45 by alegome2          #+#    #+#             */
/*   Updated: 2026/06/30 13:12:58 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0') && (str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	int	is_numeric;

	is_numeric = ft_str_is_numeric("0123+45689");
	printf("%i\n", is_numeric);
	return (0);
}*/
