/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:09:51 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/04 14:08:48 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				index;
}	t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
}	t_data;

void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	pb(t_data *data, int print);
void	pa(t_data *data, int print);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);

#endif
