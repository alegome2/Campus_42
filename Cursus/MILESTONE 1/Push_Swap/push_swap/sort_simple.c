/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 12:06:49 by joquinta         #+#    #+#              */
/*   Updated: 2026/11/24 10:45:34 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_node *stack)
{
	int	min_val;
	int	min_pos;
	int	pos;

	min_val = stack->value;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

static void	move_to_top(t_data *data, int pos)
{
	int	i;

	i = 0;
	if (pos <= data->size_a / 2)
	{
		while (i < pos)
		{
			ra(data);
			i++;
		}
	}
	else
	{
		while (i < (data->size_a - pos))
		{
			rra(data);
			i++;
		}
	}
}

void	sort_simple(t_data *data)
{
	int	pos;

	if (!data || !data->stack_a || is_sorted(data->stack_a))
		return ;
	while (data->size_a > 0)
	{
		pos = find_min_pos(data->stack_a);
		move_to_top(data, pos);
		pb(data);
	}
	while (data->size_b > 0)
		pa(data);
}
