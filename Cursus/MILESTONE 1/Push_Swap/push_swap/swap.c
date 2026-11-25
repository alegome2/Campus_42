/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 13:47:00 by joquinta         #+#    #+#              */
/*   Updated: 2026/11/24 12:34:37 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = node1->next;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
	node2->prev = NULL;
	*stack = node2;
	return ;
}

void	sa(t_data *s_data)
{
	if (!s_data->stack_a || !s_data->stack_a->next)
		return ;
	swap(&s_data->stack_a);
	write(1, "sa\n", 3);
	s_data->total_count++;
	s_data->sa_count++;
	return ;
}

void	sb(t_data *s_data)
{
	if (!s_data->stack_b || !s_data->stack_b->next)
		return ;
	swap(&s_data->stack_b);
	write(1, "sb\n", 3);
	s_data->total_count++;
	s_data->sb_count++;
	return ;
}

void	ss(t_data *s_data)
{
	if (!s_data->stack_a || !s_data->stack_a->next
		|| !s_data->stack_b || !s_data->stack_b->next)
		return ;
	swap(&s_data->stack_a);
	swap(&s_data->stack_b);
	write(1, "ss\n", 3);
	s_data->total_count++;
	s_data->ss_count++;
	return ;
}
