/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:12:20 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/25 10:40:47 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				index;
}	t_node;

typedef enum strategy
{
	ADAPTIVE = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_data
{
	t_node		*stack_a;
	t_node		*stack_b;
	int			size_a;
	int			size_b;
	int			total_count;
	int			ra_count;
	int			rb_count;
	int			rr_count;
	int			rra_count;
	int			rrb_count;
	int			rrr_count;
	int			pa_count;
	int			pb_count;
	int			sa_count;
	int			sb_count;
	int			ss_count;
	t_strategy	strategy;
	double		disorder;
	int			bench;
	int			has_strategy;
}	t_data;

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);
void	ra(t_data *s_data);
void	rb(t_data *s_data);
void	rr(t_data *s_data);
void	rra(t_data *s_data);
void	rrb(t_data *s_data);
void	rrr(t_data *s_data);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	free_stack(t_node **stack);
int		is_valid_number(char *str);
long	ft_atol(char *str);
void	parse_args(t_data *data, int argc, char **argv);
void	handle_error(t_data *data);
int		check_duplicate(t_node *a, int num);
t_node	*node_new(int num);
void	node_add_back(t_node **a, t_node *new_node);
void	*free_split(char **str);
char	**ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	sort_simple(t_data *data);
void	sort_complex(t_data *data);
int		ft_strcmp(char *s1, char *s2);
int		is_flag(char *str);
int		parse_flag(t_data *data, char *str);
int		handle_flag(t_data *data, char *token);

double	disorder(t_node *a);
void	index_stack(t_node *stack);
void	start_to_zero(t_data *s_data);
void	bench(t_data *s_data);
void	router(t_data *s_data);
void	sort_small(t_data *s_data);
void	sort_medium(t_data *s_data);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);

int	main(int argc, char **argv);

t_node	*create_mock_stack(int *arr, int size);

#endif
