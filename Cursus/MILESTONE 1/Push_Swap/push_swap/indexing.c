/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:29:09 by joquinta          #+#    #+#             */
/*   Updated: 2026/11/19 13:29:32 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_node *stack)
{
	t_node	*current;
	t_node	*runner;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		runner = stack;
		while (runner)
		{
			if (current->value > runner->value)
				count++;
			runner = runner->next;
		}
		current->index = count;
		current = current->next;
	}
}
