/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 20:14:58 by joquinta          #+#    #+#             */
/*   Updated: 2026/11/19 14:05:35 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_adaptive(t_data *s_data)
{
	if (s_data->disorder < 0.2)
		sort_simple(s_data);
	else if (s_data->disorder < 0.5)
		sort_medium(s_data);
	else
		sort_complex(s_data);
	return ;
}

void	router(t_data *s_data)
{
	if (!s_data || s_data->disorder == 0.0)
		return ;
	else if (s_data->size_a <= 5)
		sort_small(s_data);
	else if (s_data->strategy == SIMPLE)
		sort_simple(s_data);
	else if (s_data->strategy == MEDIUM)
		sort_medium(s_data);
	else if (s_data->strategy == COMPLEX)
		sort_complex(s_data);
	else
		sort_adaptive(s_data);
	return ;
}
