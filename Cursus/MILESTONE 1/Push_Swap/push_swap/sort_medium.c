/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:21:01 by joquinta          #+#    #+#             */
/*   Updated: 2026/11/19 14:41:01 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_medium(t_data *s_data);
static void	push_chunks_to_b(t_data *s_data, int range);
static void	push_back_to_a(t_data *s_data);
static int	find_max_pos(t_node *stack, int max_index);

void	sort_medium(t_data *s_data)
{
	int	range;

	if (s_data->size_a <= 100)
		range = 20;
	else
		range = 40;
	push_chunks_to_b(s_data, range);
	push_back_to_a(s_data);
}

static void	push_chunks_to_b(t_data *s_data, int range)
{
	int	i;

	i = 0;
	while (s_data->size_a > 0)
	{
		if (s_data->stack_a->index <= i)
		{
			pb(s_data);
			rb(s_data);
			i++;
		}
		else if (s_data->stack_a->index <= (i + range))
		{
			pb(s_data);
			i++;
		}
		else
			ra(s_data);
	}
}

static int	find_max_pos(t_node *stack, int max_index)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != max_index)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	push_back_to_a(t_data *s_data)
{
	int	pos;

	while (s_data->size_b > 0)
	{
		pos = find_max_pos(s_data->stack_b, s_data->size_b - 1);
		if (pos <= s_data->size_b / 2)
		{
			while (pos-- > 0)
				rb(s_data);
		}
		else
		{
			while (pos++ < s_data->size_b)
				rrb(s_data);
		}
		pa(s_data);
	}
}
