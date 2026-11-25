/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:01:46 by alegome2          #+#    #+#             */
/*   Updated: 2026/11/24 13:25:23 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	start_to_zero(&data);
	parse_args(&data, argc, argv);
	index_stack(data.stack_a);
	data.disorder = disorder(data.stack_a);
	data.size_a = stack_size(data.stack_a);
	router(&data);
	if (data.bench == 1)
		bench(&data);
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	return (0);
}

/* TESTEO */

/*
1. ⚪ No hacen nada (salida limpia sin operaciones en stdout)
./push_swap (sin argumentos)

./push_swap 42
(un solo número)

./push_swap 1 2 3 4 5
(lista ya ordenada)

./push_swap "   1   2   3  "
(ordenada en un solo string con espacios)

./push_swap --bench 1 2 3
(no imprime movimientos en stdout, pero sí muestra Total ops: 0 en stderr)

2. ✅ Casos válidos (ordenan e imprimen operaciones)
./push_swap 3 2 1
(caso pequeño con sort_small)

./push_swap "4 67 3 87 23"
(números dentro de un mismo argumento)

./push_swap 0 -42 2147483647 -2147483648
(límites exactos de INT_MAX e INT_MIN)

./push_swap --simple 5 4 3 2 1 0
(fuerza estrategia --simple)

./push_swap --medium 9 8 7 6 5 4 3 2 1
(fuerza estrategia --medium)

./push_swap --complex --bench 10 9 8 7 6 5 4 3 2 1
(combina estrategia y --bench)

3. ❌ Casos de error (deben imprimir Error\n en stderr y liberar memoria)
./push_swap 1 2 2 3
(números duplicados)

./push_swap 1 2a 3
(caracteres no numéricos)

./push_swap 1 "" 3
(argumento vacío)

./push_swap 2147483648 o ./push_swap -2147483649
(overflow de int)

./push_swap --invalid 3 2 1
(flag inexistente)

./push_swap --simple --medium 3 2 1
(dos estrategias a la vez)

./push_swap --bench --bench 3 2 1
(flag --bench duplicada)

./push_swap --bench
(solo flags, sin ningún número)

Para comprobar los leaks al mismo tiempo, recuerda lanzarlos con valgrind:
--leak-check=full ./push_swap ....
*/
