# 🗺️ Guía de Arquitectura: Parser para *push_swap*

## 🎯 1. Objetivo General
El **parser** actúa como filtro de entrada 🛂. Su función es tomar los argumentos de la línea de comandos (`char **argv`), validar rigurosamente su formato numérico y construir la lista enlazada inicial (`stack_a`).

Si ocurre un fallo en cualquier argumento:
1. 🧹 Liberar la memoria acumulada con `free_stack(&stack_a)`.
2. 📢 Escribir `Error\n` en el descriptor de salida de error (`stderr` o fd `2`).
3. 🚪 Finalizar el programa inmediatamente con código de error.

---

## ⚠️ 2. Casos Límite y Errores (*Edge Cases*)
* 🔤 **Caracteres inválidos:** Caracteres alfabéticos o símbolos (`"3 a 5"`, `"12-3"`).
* ➕ **Signos aislados:** Argumentos con solo signos (`"+"`, `"-"`).
* 📏 **Desbordamiento (*Overflow*):** Valores fuera del rango de enteros de 32 bits:
  * Menor que `INT_MIN` (`-2147483648`).
  * Mayor que `INT_MAX` (`2147483647`).
* 👥 **Números repetidos:** Argumentos con valores idénticos (`"1 2 3 2"`).
* 📦 **Entrada en un solo string:** Múltiples números dentro de comillas (`./push_swap "3 2 1"`).

---

## 🧱 3. Módulos y Funciones

| Función | Tipo de Retorno | Responsabilidad |
| :--- | :--- | :--- |
| `is_valid_number` | `int` | Comprueba sintaxis: solo dígitos y signo inicial opcional. |
| `ft_atol` | `long` | Convierte texto a número detectando desbordamiento de `int`. |
| `has_duplicate` | `int` | Recorre la lista para confirmar que el valor no exista previamente. |
| `node_new` | `t_node *` | Reserva memoria e inicializa un nuevo nodo con el valor dado. |
| `node_add_back` | `void` | Engancha un nuevo nodo al final de la lista enlazada. |
| `handle_error` | `void` | Libera la memoria con `free_stack` y escribe el mensaje de error. |

---

## 🪜 4. Flujo de Ejecución Paso a Paso

1. 📥 **Normalización:**
   * Si los números vienen agrupados en una sola cadena (`argc == 2`), separar con `ft_split`.
   * Si vienen en argumentos separados (`argc > 2`), iterar directamente sobre `argv`.
2. ✍️ **Validación sintáctica:**
   * Ejecutar `is_valid_number` sobre cada elemento antes de convertirlo.
3. ⚖️ **Conversión y rango:**
   * Convertir la cadena con `ft_atol`.
   * Verificar si el resultado está dentro de `[INT_MIN, INT_MAX]`.
4. 🔎 **Unicidad:**
   * Consultar `has_duplicate` con la pila actual.
5. 🔗 **Inserción:**
   * Si supera los filtros, crear el nodo con `node_new` y enlazarlo con `node_add_back`.