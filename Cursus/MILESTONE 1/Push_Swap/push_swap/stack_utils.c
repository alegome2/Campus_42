/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 13:34:20 by joquinta         #+#    #+#              */
/*   Updated: 2026/11/24 12:36:14 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

t_node	*node_new(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	node_add_back(t_node **a, t_node *new_node)
{
	t_node	*curr;

	if (!new_node)
		return ;
	if (!a || !*a)
	{
		*a = new_node;
		return ;
	}
	curr = *a;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	new_node->prev = curr;
}
