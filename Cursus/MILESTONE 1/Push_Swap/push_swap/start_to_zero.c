/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_to_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:57:29 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/23 11:00:35 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_to_zero(t_data *s_data)
{
	s_data->stack_a = NULL;
	s_data->stack_b = NULL;
	s_data->size_a = 0;
	s_data->size_b = 0;
	s_data->total_count = 0;
	s_data->ra_count = 0;
	s_data->rb_count = 0;
	s_data->rr_count = 0;
	s_data->rra_count = 0;
	s_data->rrb_count = 0;
	s_data->rrr_count = 0;
	s_data->pa_count = 0;
	s_data->pb_count = 0;
	s_data->sa_count = 0;
	s_data->sb_count = 0;
	s_data->ss_count = 0;
	s_data->strategy = ADAPTIVE;
	s_data->disorder = 0.0;
	s_data->bench = 0;
	s_data->has_strategy = 0;
}
