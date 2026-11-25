/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:20:50 by joquinta          #+#    #+#             */
/*   Updated: 2026/11/23 13:37:04 by joquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_data *data)
{
	write(2, "Error\n", 6);
	free_stack(&data->stack_a);
	exit(1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		else
			return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_node *a, int num)
{
	t_node	*curr;

	curr = a;
	while (curr)
	{
		if (curr->value == num)
			return (1);
		curr = curr->next;
	}
	return (0);
}
