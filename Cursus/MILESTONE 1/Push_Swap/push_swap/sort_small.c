/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:46:53 by joquinta          #+#    #+#             */
/*   Updated: 2026/11/19 14:30:44 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *s_data)
{
	t_node	*first;
	t_node	*second;

	if (!s_data || !s_data->stack_a || is_sorted(s_data->stack_a))
		return ;
	first = s_data->stack_a;
	second = first->next;
	if (first->index > second->index)
		sa(s_data);
}

static void	sort_three(t_data *s_data)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!s_data || !s_data->stack_a || is_sorted(s_data->stack_a))
		return ;
	first = s_data->stack_a;
	second = first->next;
	third = second->next;
	if (first->index > second->index && first->index > third->index)
		ra(s_data);
	else if (second->index > first->index && second->index > third->index)
		rra(s_data);
	first = s_data->stack_a;
	second = first->next;
	if (first->index > second->index)
		sa(s_data);
}

static void	push_min_to_b(t_data *s_data, int target)
{
	int		pos;
	t_node	*current;

	current = s_data->stack_a;
	pos = 0;
	while (current->index != target)
	{
		current = current->next;
		pos++;
	}
	if (pos <= s_data->size_a / 2)
	{
		while (pos-- > 0)
			ra(s_data);
	}
	else
	{
		while (pos++ != s_data->size_a)
			rra(s_data);
	}
	pb(s_data);
}

static void	sort_four_five(t_data *s_data)
{
	if (!s_data || !s_data->stack_a || is_sorted(s_data->stack_a))
		return ;
	if (s_data->size_a == 5)
	{
		push_min_to_b(s_data, 0);
		push_min_to_b(s_data, 1);
		sort_three(s_data);
		pa(s_data);
		pa(s_data);
	}
	else
	{
		push_min_to_b(s_data, 0);
		sort_three(s_data);
		pa(s_data);
	}
}

void	sort_small(t_data *s_data)
{
	if (s_data->size_a == 2)
		sort_two(s_data);
	else if (s_data->size_a == 3)
		sort_three(s_data);
	else if (s_data->size_a > 3)
		sort_four_five(s_data);
}
