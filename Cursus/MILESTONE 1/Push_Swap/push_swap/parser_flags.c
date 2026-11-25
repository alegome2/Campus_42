/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 10:52:56 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/23 10:55:29 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *str)
{
	if (!str)
		return (0);
	if ((str[0] == '-') && (str[1] == '-'))
		return (1);
	return (0);
}

static int	set_strategy(t_data *data, t_strategy strat)
{
	if (data->has_strategy == 1)
		return (0);
	data->strategy = strat;
	data->has_strategy = 1;
	return (1);
}

int	parse_flag(t_data *data, char *str)
{
	if (ft_strcmp(str, "--bench") == 0)
	{
		if (data->bench == 1)
			return (0);
		data->bench = 1;
		return (1);
	}
	else if (ft_strcmp(str, "--simple") == 0)
		return (set_strategy(data, SIMPLE));
	else if (ft_strcmp(str, "--medium") == 0)
		return (set_strategy(data, MEDIUM));
	else if (ft_strcmp(str, "--complex") == 0)
		return (set_strategy(data, COMPLEX));
	else if (ft_strcmp(str, "--adaptive") == 0)
		return (set_strategy(data, ADAPTIVE));
	return (0);
}

int	handle_flag(t_data *data, char *token)
{
	if (!is_flag(token))
		return (0);
	if (parse_flag(data, token) == 0)
		return (-1);
	return (1);
}
