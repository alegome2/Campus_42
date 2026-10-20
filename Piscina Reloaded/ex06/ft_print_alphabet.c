/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:01:37 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/07 16:35:45 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char abc);

void	ft_print_alphabet(void)
{
	char	abc;

	abc = 'a';
	while (abc <= 'z')
	{
		ft_putchar(abc);
		abc++;
	}
}
/*
int main(void)
{
	ft_print_alphabet();
	return(0);
}*/
