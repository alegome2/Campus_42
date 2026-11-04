/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:03:45 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/04 13:21:02 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data, int print)
{
	t_node	*node_to_push;
	/*Cláusula de guarda: si la pila A no tiene elementos, no hay nada que mover */

	if (!data->stack_a)
		return ;
	/*Aislar el primer nodo de A para no perder su referencia en memoria */
	node_to_push = data->stack_a;
	/*Desconectar el nodo de la pila A */
	data->stack_a = data->stack_a->next;
	// El segundo nodo pasa a ser la nueva cima de A
	if (data->stack_a)
		data->stack_a->prev = NULL;
	// Si A aún tiene nodos, el nuevo primero no tiene nadie arriba
	/*Conectar el nodo en la cima de la pila B */
	node_to_push->next = data->stack_b;
	// El nodo apunta hacia abajo a la antigua cima de B
	if (data->stack_b)
		data->stack_b->prev = node_to_push;
	// Si B tenía nodos, su antigua cima apunta hacia arriba al nuevo nodo
	/*Fijar el nodo como la cabecera definitiva de B */
	node_to_push->prev = NULL;
	// Al estar arriba del todo, nadie está sobre él
	data->stack_b = node_to_push;
	// Actualizamos la cabecera de B hacia este nuevo elemento
	/*Imprimir la operación si el flag está activado */
	if (print)
		write(1, "pb\n", 3);
}

void	pa(t_data *data, int print)
{
	t_node	*node_to_push;

	if (!data->stack_b)
		return ;
	node_to_push = data->stack_b;
	data->stack_b = data->stack_b->next;
	if (data->stack_b)
		data->stack_b->prev = NULL;
	node_to_push->next = data->stack_a;
	if (data->stack_a)
		data->stack_a->prev = node_to_push;
	node_to_push->prev = NULL;
	data->stack_a = node_to_push;
	if (print)
		write(1, "pa\n", 3);
}

int	stack_size(t_node *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}
