/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_complex.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: joquinta <joquinta@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 09:58:09 by joquinta         #+#    #+#              */
/*   Updated: 2026/11/24 10:41:32 by joquinta        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_data *data)
{
	int	max_num;
	int	max_bits;

	max_num = data->size_a - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_data *data)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	if (!data || !data->stack_a || is_sorted(data->stack_a))
		return ;
	i = -1;
	size = data->size_a;
	max_bits = get_max_bits(data);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((data->stack_a->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
		}
		while (data->size_b > 0)
			pa(data);
	}
}
