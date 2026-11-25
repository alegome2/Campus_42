/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 13:47:31 by joquinta         #+#    #+#              */
/*   Updated: 2026/11/24 11:22:14 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	first->prev = last;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last->next = first;
	return ;
}

void	ra(t_data *s_data)
{
	if (!s_data->stack_a || s_data->stack_a->next == NULL)
		return ;
	rotate(&s_data->stack_a);
	write(1, "ra\n", 3);
	s_data->total_count++;
	s_data->ra_count++;
	return ;
}

void	rb(t_data *s_data)
{
	if (!s_data->stack_b || s_data->stack_b->next == NULL)
		return ;
	rotate(&s_data->stack_b);
	write(1, "rb\n", 3);
	s_data->total_count++;
	s_data->rb_count++;
	return ;
}

void	rr(t_data *s_data)
{
	if (!s_data->stack_a || s_data->stack_a->next == NULL
		|| !s_data->stack_b || s_data->stack_b->next == NULL)
	{
		return ;
	}
	rotate(&s_data->stack_a);
	rotate(&s_data->stack_b);
	write(1, "rr\n", 3);
	s_data->total_count++;
	s_data->rr_count++;
	return ;
}
