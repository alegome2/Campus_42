/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alegome2 <alegome2@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 13:47:00 by alegome2         #+#    #+#              */
/*   Updated: 2026/11/03 19:54:28 by alegome2        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int print)
{
	t_node	*node1;
	t_node	*node2;

	// 1.Seguridad: salir si la pila está vacía o solo tiene 1 nodo
	if (!data->stack_a || !data->stack_a->next)
		return ;
	// 2.Guardar los dos primeros nodos en punteros auxiliares
	node1 = data->stack_a;
	// node1: la cima actual
	node2 = node1->next;
	// node2: el segundo elemento
	// 3.Reconectar los enlaces:
	// Paso A: node1 salta a node2 y agarra al tercer nodo (si existe)
	node1->next = node2->next;
	// Paso B: si hay un tercer nodo, su enlace 'prev' ahora debe apuntar a node1
	if (node1->next)
		node1->next->prev = node1;
	// Paso C: node2 agarra por abajo (next) a node1
	node2->next = node1;
	// Paso D: node1 agarra por arriba (prev) a node2
	node1->prev = node2;
	// Paso E: como node2 será la nueva cima, nadie queda por encima de él
	node2->prev = NULL;
	// 4.Actualizar la cabecera: node2 es ahora la nueva cima de la pila A
	data->stack_a = node2;
	// 5.Imprimir "sa\n" solo si se solicitó
	if (print != 0)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int print)
{
	t_node	*node1;
	t_node	*node2;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	node1 = data->stack_b;
	node2 = node1->next;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
	node2->prev = NULL;
	data->stack_b = node2;
	if (print != 0)
		write(1, "sb\n", 3);
}

void	ss(t_data *data, int print)
{
	sa(data, 0);
	sb(data, 0);
	if (print != 0)
		write(1, "ss\n", 3);
}
