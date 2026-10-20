/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:05:53 by alegome2          #+#    #+#             */
/*   Updated: 2026/10/05 10:32:09 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list && new)
	{
		new->next = *list;
		*list = new;
	}
}

/*void	ft_lstadd_front(t_list **list, t_list *new)
{
if (!new || !list)
return ;
new->next = *list;
*list = new;
}*/
//Compruebo que no esten vacios
//engancho new.next al inicio de la siguiente lista
//el inicio de la lista lo igual a la que tengo que poner delante
