/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:03:45 by joquinta          #+#    #+#             */
/*   Updated: 2026/11/24 12:50:41 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	t_node	*node_to_push;

	if (!data->stack_a)
		return ;
	node_to_push = data->stack_a;
	data->stack_a = data->stack_a->next;
	if (data->stack_a)
		data->stack_a->prev = NULL;
	node_to_push->next = data->stack_b;
	if (data->stack_b)
		data->stack_b->prev = node_to_push;
	node_to_push->prev = NULL;
	data->stack_b = node_to_push;
	data->size_a--;
	data->size_b++;
	write(1, "pb\n", 3);
	data->total_count++;
	data->pb_count++;
	return ;
}

void	pa(t_data *data)
{
	t_node	*node_to_push;

	if (!data->stack_b)
		return ;
	node_to_push = data->stack_b;
	data->stack_b = data->stack_b->next;
	if (data->stack_b)
		data->stack_b->prev = NULL;
	node_to_push->next = data->stack_a;
	if (data->stack_a)
		data->stack_a->prev = node_to_push;
	node_to_push->prev = NULL;
	data->stack_a = node_to_push;
	data->size_a++;
	data->size_b--;
	write(1, "pa\n", 3);
	data->total_count++;
	data->pa_count++;
	return ;
}

int	stack_size(t_node *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}
