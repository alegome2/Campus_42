/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:31:51 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/24 14:01:33 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_metric(char *label, int count)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(count, 2);
	write(2, "\n", 1);
}

void	bench(t_data *s_data)
{
	if (!s_data)
		return ;
	print_metric("[bench] total_ops: ", s_data->total_count);
	print_metric("ra: ", s_data->ra_count);
	print_metric("rb: ", s_data->rb_count);
	print_metric("rr: ", s_data->rr_count);
	print_metric("rra: ", s_data->rra_count);
	print_metric("rrb: ", s_data->rrb_count);
	print_metric("rrr: ", s_data->rrr_count);
	print_metric("pa: ", s_data->pa_count);
	print_metric("pb: ", s_data->pb_count);
	print_metric("sa: ", s_data->sa_count);
	print_metric("sb: ", s_data->sb_count);
	print_metric("ss: ", s_data->ss_count);
}
