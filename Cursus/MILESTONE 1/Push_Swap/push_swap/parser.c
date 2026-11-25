/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:18:53 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/25 10:42:00 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_number(t_data *data, char *tokens)
{
	long	num;
	t_node	*new_node;

	if (!is_valid_number(tokens))
		return (0);
	num = ft_atol(tokens);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (check_duplicate(data->stack_a, (int) num))
		return (0);
	new_node = node_new((int) num);
	if (!new_node)
		return (0);
	node_add_back(&data->stack_a, new_node);
	return (1);
}

static int	process_tokens(t_data *data, char **tokens)
{
	int	j;
	int	flag_status;

	j = 0;
	while (tokens[j])
	{
		flag_status = handle_flag(data, tokens[j]);
		if (flag_status == -1)
			return (0);
		if (flag_status == 0 && !add_number(data, tokens[j]))
			return (0);
		j++;
	}
	return (1);
}

void	parse_args(t_data *data, int argc, char **argv)
{
	int		i;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i]);
		if (!tokens || !tokens[0] || !process_tokens(data, tokens))
		{
			free_split(tokens);
			handle_error(data);
		}
		free_split(tokens);
		i++;
	}
	if (!data->stack_a)
		handle_error(data);
}
