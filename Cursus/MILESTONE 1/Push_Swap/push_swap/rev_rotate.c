/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rev_rotate.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/02 17:52:44 by joquinta         #+#    #+#              */
/*   Updated: 2026/11/24 10:26:51 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack = last;
	return ;
}

void	rra(t_data *s_data)
{
	if (!s_data->stack_a || s_data->stack_a->next == NULL)
		return ;
	reverse_rotate(&s_data->stack_a);
	write(1, "rra\n", 4);
	s_data->total_count++;
	s_data->rra_count++;
	return ;
}

void	rrb(t_data *s_data)
{
	if (!s_data->stack_b || s_data->stack_b->next == NULL)
		return ;
	reverse_rotate(&s_data->stack_b);
	write(1, "rrb\n", 4);
	s_data->total_count++;
	s_data->rrb_count++;
	return ;
}

void	rrr(t_data *s_data)
{
	if (!s_data->stack_a || s_data->stack_a->next == NULL
		|| !s_data->stack_b || s_data->stack_b->next == NULL)
	{
		return ;
	}
	reverse_rotate(&s_data->stack_a);
	reverse_rotate(&s_data->stack_b);
	write(1, "rrr\n", 4);
	s_data->total_count++;
	s_data->rrr_count++;
	return ;
}
