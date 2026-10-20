/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:38:46 by alegome2          #+#    #+#             */
/*   Updated: 2026/09/21 17:18:07 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	abc;

	abc = 'a';
	while (abc <= 'z')
	{
		write(1, &abc, 1);
		abc++;
	}
}

/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/
