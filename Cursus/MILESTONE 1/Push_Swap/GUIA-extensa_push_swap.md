# Guía Maestra Exhaustiva de Push_swap (42 Network)

*Documento técnico, conceptual y pedagógico diseñado para el desarrollo en pareja del proyecto Push_swap bajo el nuevo currículo de 42.*

---

## 1. Visión General del Proyecto y Objetivos

El reto fundamental de **Push_swap** es resolver un problema clásico de la algoritmia (ordenación de datos) bajo un conjunto estricto de restricciones físicas y mecánicas:
* Se dispone únicamente de **dos pilas (stacks)**: `a` y `b`.
* El stack `a` comienza con una colección arbitraria de números enteros (positivos y negativos) sin duplicados.
* El stack `b` comienza completamente vacío.
* El objetivo es dejar todos los números en el stack `a` ordenados de forma **ascendente** (el valor menor en la cima) y el stack `b` vacío.
* La única vía de manipulación permitida es un conjunto cerrado de **11 instrucciones atómicas**.
* La salida del programa **no son los números ordenados**, sino la secuencia mínima de instrucciones (`sa`, `pb`, `ra`...) impresa por la salida estándar (`stdout`) separada por saltos de línea (`\n`).

### Requisitos Específicos del Subject
1. **Proyecto en pareja:** Ambos estudiantes deben comprender e implementar el código al 100%. El repositorio debe reflejar la contribución equitativa y los logins en el `README.md`.
2. **Cálculo del Índice de Desorden:** Debe computarse matemáticamente antes de realizar cualquier movimiento.
3. **Cuatro Estrategias Algorítmicas:**
   * Simple: Complejidad $O(n^2)$.
   * Intermedia: Complejidad $O(n\sqrt{n})$.
   * Compleja: Complejidad $O(n \log n)$.
   * Adaptativa (por defecto): Selección dinámica según el índice de desorden.
4. **Selectores por línea de comandos:** Soporte de flags `--simple`, `--medium`, `--complex`, `--adaptive` y opcionalmente `--bench`.
5. **Cotas de rendimiento para superar la evaluación:**
   * 100 números: $< 2000$ operaciones (mínimo), $< 1500$ (bien), $< 700$ (excelente).
   * 500 números: $< 12000$ operaciones (mínimo), $< 8000$ (bien), $< 5500$ (excelente).

---

## 2. Las 11 Instrucciones: Explicación y Diagramas Visuales

En las representaciones siguientes, consideramos que la **cima (top)** del stack está arriba y el **fondo (bottom)** está abajo.

```
       Stack A                 Stack B
    ┌───────────┐           ┌───────────┐
TOP │     2     │       TOP │    VACÍO  │
    ├───────────┤           ├───────────┤
    │     1     │           │           │
    ├───────────┤           ├───────────┤
    │     3     │           │           │
BOT │     6     │       BOT │           │
    └───────────┘           └───────────┘
```

### 2.1 Swaps (Intercambio en la cima)
* **`sa` (swap a):** Intercambia los 2 primeros elementos en la cima del stack `a`. No hace nada si hay $\le 1$ elemento.
* **`sb` (swap b):** Intercambia los 2 primeros elementos en la cima del stack `b`. No hace nada si hay $\le 1$ elemento.
* **`ss`:** Ejecuta `sa` y `sb` simultáneamente.

```
      Antes de sa                   Después de sa
     ┌───────────┐                 ┌───────────┐
 TOP │     2     │  ─┐         TOP │     1     │
     ├───────────┤   ├─ Swap       ├───────────┤
     │     1     │  ─┘             │     2     │
     ├───────────┤                 ├───────────┤
     │     3     │                 │     3     │
 BOT │     6     │             BOT │     6     │
     └───────────┘                 └───────────┘
```

### 2.2 Pushes (Traspaso entre pilas)
* **`pa` (push a):** Toma el elemento de la cima de `b` y lo pone en la cima de `a`. No hace nada si `b` está vacío.
* **`pb` (push b):** Toma el elemento de la cima de `a` y lo pone en la cima de `b`. No hace nada si `a` está vacío.

```
            Antes de pb                                    Después de pb
    Stack A             Stack B                    Stack A             Stack B
 ┌───────────┐       ┌───────────┐              ┌───────────┐       ┌───────────┐
 │     2     │ ────> │   VACÍO   │              │     1     │   TOP │     2     │
 ├───────────┤       └───────────┘              ├───────────┤       └───────────┘
 │     1     │                                  │     3     │
 ├───────────┤                                  ├───────────┤
 │     3     │                              BOT │     6     │
 └───────────┘                                  └───────────┘
```

### 2.3 Rotates (Desplazamiento ascendente)
* **`ra` (rotate a):** Sube todos los elementos de `a` una posición. El que estaba en la cima pasa a ser el último.
* **`rb` (rotate b):** Sube todos los elementos de `b` una posición. El de la cima pasa al fondo.
* **`rr`:** Ejecuta `ra` y `rb` simultáneamente.

```
      Antes de ra                   Después de ra
     ┌───────────┐                 ┌───────────┐
 TOP │   [ 2 ] ──┼──┐          TOP │     1     │
     ├───────────┤  │              ├───────────┤
     │     1     │  │  ▲ Sube      │     3     │
     ├───────────┤  │  │           ├───────────┤
     │     3     │  │  │           │     6     │
     ├───────────┤  │  │           ├───────────┤
 BOT │     6     │  │  │       BOT │   [ 2 ]   │
     └───────────┘  └──┼─────────> └───────────┘
```

### 2.4 Reverse Rotates (Desplazamiento descendente)
* **`rra` (reverse rotate a):** Baja todos los elementos de `a` una posición. El del fondo pasa a ser la cima.
* **`rrb` (reverse rotate b):** Baja todos los elementos de `b` una posición. El del fondo pasa a ser la cima.
* **`rrr`:** Ejecuta `rra` y `rrb` simultáneamente.

```
      Antes de rra                  Después de rra
     ┌───────────┐                 ┌───────────┐
 TOP │     2     │  │          TOP │   [ 6 ]   │
     ├───────────┤  │  ▼ Baja  ┌─────────┼─────┘
     │     1     │  │          │   ├───────────┤
     ├───────────┤  │          │   │     2     │
     │     3     │  │          │   ├───────────┤
     ├───────────┤  │          │   │     1     │
 BOT │   [ 6 ] ──┼──┘          │   ├───────────┤
     └───────────┘             └──>│     3     │
                               BOT └───────────┘
```

---

## 3. Matriz de Decisiones Técnicas (La vía recomendada)

A lo largo del proyecto tendréis varias encrucijadas técnicas. A continuación se comparan las alternativas y se destaca la opción recomendada pedagógicamente.

### Decisión 1: Estructura de Datos para los Stacks

| Criterio | Arrays / Arreglos Contiguos | Lista Enlazada Simple | Lista Doblemente Enlazada Circular |
| :--- | :--- | :--- | :--- |
| **Operación `push`** | Costosa ($O(n)$): Desplaza memoria o exige buffers circulares con índices. | Rápida ($O(1)$) en la cima, pero lenta al fondo. | Rápida ($O(1)$) cambiando punteros. |
| **Operación `rotate`** | Requiere módulo o desplazamiento de índices. | Modificación de puntero head y tail ($O(n)$ sin cola guardada). | Conexión circular directa ($O(1)$). |
| **Operación `rrev_rotate`** | Modificación de índices circulares. | Costosa ($O(n)$): Recorrer hasta el penúltimo nodo. | Inmediata ($O(1)$) gracias al puntero `prev`. |
| **Gestión de Memoria** | Fácil asignación inicial, pero redimensionar es complejo. | Fácil con `malloc`/`free` por nodo. | Fácil con `malloc`/`free` por nodo. |
| **Dificultad conceptual** | Media | Baja | Media-Baja |

* **Recomendación para estudiantes de 42:** **Lista doblemente enlazada (no necesariamente circular cerrada si os lía, pero sí con punteros `next` y `prev` y control de `head` y `tail`).**  
  *¿Por qué?* Conectar `head` y `tail` o tener acceso con `prev` hace que `rra` y `rrb` sean triviales: no necesitas iterar toda la lista hasta el final cada vez que quieras rotar hacia atrás.

### Decisión 2: Entrada de Argumentos (`argv`)

Push_swap puede recibir los números de dos maneras:
1. Parámetros independientes: `./push_swap 4 67 3 87 23`
2. Un único string entrecomillado: `./push_swap "4 67 3 87 23"`
3. Mixto: `./push_swap --adaptive 4 "67 3" 87 23`

* **Alternativa A:** Hacer un parser rígido que falle si encuentra comillas. *(Mala práctica: suspende en las pruebas de pares).*
* **Alternativa B (Recomendada):** **Tratamiento homogéneo con `ft_split`.**  
  *¿Cómo funciona?*
  1. Itera desde `argv[1]` en adelante.
  2. Si el argumento empieza por `--`, se parsea como flag (`--simple`, etc.).
  3. Todo argumento numérico se procesa con `ft_split(argv[i], ' ')`.
  4. Se recorre cada subcadena generada, se valida sintácticamente y se añade al stack.
  5. Se libera la matriz devuelta por `ft_split`.  
  *Ventaja:* Maneja cualquier combinación de comillas y espacios de forma unificada sin código duplicado.

### Decisión 3: Normalización de Valores (Indexación)

* **Sin normalización:** El algoritmo trabaja con valores directos (ej. `-2147483648`, `0`, `999999`).  
  *Inconveniente:* Para algoritmos como Chunks o Radix es extremadamente difícil calcular rangos o manipular máscaras binarias cuando hay negativos y saltos grandes.
* **Con normalización (Recomendada):** Reemplazar cada valor por su índice ordenado relativo ($0, 1, 2, \dots, n-1$).
  * Ejemplo de entrada: `[ 40, -10, 100, 5 ]`
  * Asignación de índices: `-10 -> 0`, `5 -> 1`, `40 -> 2`, `100 -> 3`
  * Stack normalizado: `[ 2, 0, 3, 1 ]`  
  *Ventaja:* Radix sort pasa a funcionar de manera trivial examinando los bits de $0$ a $n-1$, y la estrategia de Chunks divide los rangos de forma exacta.

---

## 4. El Índice de Desorden (`disorder index`)

El enunciado establece que antes de realizar cualquier movimiento se debe calcular el desorden de la entrada:

### 4.1 Definición Matemática y Algoritmo

El índice de desorden mide la fracción de pares desordenados (inversiones) respecto al total posible de pares:

$$\text{total\_pairs} = \frac{n \times (n - 1)}{2}$$

$$\text{disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}$$

Donde un error (`mistake`) ocurre cada vez que para dos posiciones $i < j$, se cumple que $a[i] > a[j]$.

```c
// Ejemplo conceptual en C para calcular el desorden sobre un array o lista
double compute_disorder(t_node *stack_a, int size)
{
    long long mistakes = 0;
    long long total_pairs = ((long long)size * (size - 1)) / 2;
    t_node *current;
    t_node *checker;

    if (size <= 1)
        return (0.0);
    current = stack_a;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (current->value > checker->value)
                mistakes++;
            checker = checker->next;
        }
        current = current->next;
    }
    return ((double)mistakes / (double)total_pairs);
}
```

### 4.2 Umbrales y Selección Adaptativa
* $\text{desorden} = 0.0$: La lista ya está ordenada. El programa termina sin imprimir nada.
* $\text{desorden} < 0.2$ (Régimen Bajo): Debe resolverse en $O(n)$.
* $0.2 \le \text{desorden} < 0.5$ (Régimen Medio): Debe resolverse en $O(n\sqrt{n})$.
* $\text{desorden} \ge 0.5$ (Régimen Alto): Debe resolverse en $O(n \log n)$.

---

## 5. Diseño y Explicación de los 4 Algoritmos Requeridos

### 5.1 Casos Base Pequeños (Fundamentales para optimizar)
* **2 números:** Si el primero es mayor que el segundo $\rightarrow$ `sa`.
* **3 números:** Existen 6 permutaciones posibles ($3!$). El caso ya ordenado no hace nada, los 5 restantes se resuelven en un máximo de 2 movimientos (`sa`, `ra`, `rra` o combinaciones).

### 5.2 Estrategia 1: Algoritmo Simple ($O(n^2)$)
* **Idea:** Adaptación de *Selection Sort*.
* **Mecánica:**
  1. Busca el elemento con el valor mínimo en `a`.
  2. Rota el stack `a` (`ra` si está en la mitad superior, `rra` si está en la mitad inferior) hasta que el mínimo esté en la cima.
  3. Ejecuta `pb` para pasarlo a `b`.
  4. Repite el proceso hasta que en `a` queden solo 2 o 3 elementos.
  5. Ordena los restantes en `a` y luego devuelve todos con `pa`.
* **Análisis:** En el peor caso, para cada uno de los $n$ elementos se realizan hasta $n/2$ rotaciones. Complejidad en operaciones: $O(n^2)$.

### 5.3 Estrategia 2: Algoritmo Intermedio ($O(n\sqrt{n})$) — Chunks / Bloques
* **Idea:** Dividir los índices en $k$ bloques o ventanas deslizantes de tamaño proporcional a $\sqrt{n}$.
* **Mecánica:**
  1. Con los números indexados de $0$ a $n-1$, definimos un rango $[c_{\text{min}}, c_{\text{max}}]$.
  2. Si el elemento de la cima de `a` pertenece al rango:
     * Lo pasamos a `b` con `pb`.
     * Si además su índice está en la mitad inferior del bloque, ejecutamos `rb` para colocar los más pequeños al fondo de `b`.
     * Desplazamos el rango hacia adelante.
  3. Si no está en el rango, hacemos `ra` buscando elementos que sí pertenezcan.
  4. Una vez todo el stack `a` está en `b`, vaciamos `b` hacia `a` devolviendo siempre el elemento más grande con rotaciones optimizadas (`rb` o `rrb`).
* **Análisis:** Cada elemento se mueve a `b` en un número de pasos acotado por el tamaño del chunk ($\approx \sqrt{n}$), logrando un rendimiento cercano a $O(n\sqrt{n})$.

### 5.4 Estrategia 3: Algoritmo Complejo ($O(n \log n)$) — Radix Sort Binario
* **Idea:** Ordenación por dígitos binarios utilizando los índices normalizados.
* **Mecánica:**
  1. Si hay $n$ elementos, el índice máximo es $n-1$. Averiguamos cuántos bits se necesitan para representar $n-1$ (sea $B = \lceil \log_2(n) \rceil$).
  2. Iteramos desde el bit $0$ hasta el bit $B-1$:
     * Para cada elemento en `a`:
       * Si el bit actual de su índice es `0` $\rightarrow$ ejecutamos `pb` (lo apartamos a `b`).
       * Si el bit actual de su índice es `1` $\rightarrow$ ejecutamos `ra` (lo dejamos en `a`).
     * Cuando hemos recorrido todos los elementos del ciclo, devolvemos todo `b` a `a` con `pa`.
* **Análisis:** Se hacen exactamente $B$ pasadas. En cada pasada se procesan $n$ elementos. Total de movimientos: $O(n \cdot \log_2 n)$.

### 5.5 Estrategia 4: Algoritmo Adaptativo
* Lee la entrada y calcula `disorder`.
* Si desorden $< 0.2$: Aplica inserción directa de los pocos elementos fuera de orden ($O(n)$ movimientos si la lista está casi ordenada).
* Si $0.2 \le \text{desorden} < 0.5$: Invoca la estrategia de Chunks ($O(n\sqrt{n})$).
* Si desorden $\ge 0.5$: Invoca Radix sort ($O(n \log n)$).

---

## 6. Arquitectura de Archivos y Responsabilidades

Para asegurar modularidad y cumplimiento de la Norma de 42:

```
push_swap/
├── Makefile
├── README.md
├── libft/
│   ├── Makefile
│   └── srcs/ ...
├── includes/
│   ├── push_swap.h
│   └── operations.h
└── srcs/
    ├── main.c                  # Procesamiento de argv, flags y selector
    ├── parsing/
    │   ├── parse_input.c       # Manejo de strings y llamadas a split
    │   ├── validate.c          # Detección de no-números, desbordamientos de int
    │   ├── check_duplicates.c  # Comprobación de números repetidos
    │   └── clean_exit.c        # Liberación completa y salida con "Error\n"
    ├── stack/
    │   ├── stack_init.c        # Creación y enlace de nodos
    │   ├── stack_utils.c       # size, min, max, is_sorted
    │   ├── indexing.c          # Normalización de 0 a n-1
    │   └── disorder.c          # Cálculo matemático del índice de desorden
    ├── operations/
    │   ├── swap.c              # sa, sb, ss
    │   ├── push.c              # pa, pb
    │   ├── rotate.c            # ra, rb, rr
    │   └── reverse_rotate.c    # rra, rrb, rrr
    ├── algorithms/
    │   ├── sort_small.c        # 2 y 3 números
    │   ├── sort_simple.c       # Estrategia O(n^2)
    │   ├── sort_medium.c       # Estrategia O(n√n)
    │   ├── sort_complex.c      # Estrategia O(n log n)
    │   └── sort_adaptive.c     # Bifurcación según disorder
    └── benchmark/
        └── bench.c             # Impresión de estadísticas para flag --bench
```

---

## 7. Protocolo de Gestión de Errores y Edge Cases

En 42 un solo fallo de segmentación o leak en un caso límite supone un 0. Todo error debe escribir `Error\n` en `stderr` (descriptor de archivo `2`) y liberar absolutamente toda la memoria asignada.

### 7.1 Casos de Error Obligatorios
1. **No-numéricos:** `./push_swap 1 2 three 4` $\rightarrow$ `Error\n`
2. **Signos huérfanos o inválidos:** `./push_swap + - 4` o `./push_swap 1 2+3` $\rightarrow$ `Error\n`
3. **Overflow / Underflow de 32 bits:** `./push_swap 2147483648` o `./push_swap -2147483649` $\rightarrow$ `Error\n`  
   *(Solución: Parsear con `long long` y verificar antes del casteo a `int`).*
4. **Duplicados:** `./push_swap 1 5 3 5` $\rightarrow$ `Error\n`
5. **Cadena vacía o de solo espacios:** `./push_swap ""` o `./push_swap "   "` $\rightarrow$ `Error\n`
6. **Flag desconocida:** `./push_swap --invalid 1 2 3` $\rightarrow$ `Error\n`

### 7.2 Casos Especiales Silenciosos
* **Sin argumentos:** `./push_swap` $\rightarrow$ Devuelve el prompt inmediatamente sin imprimir nada.
* **Ya ordenado:** `./push_swap 1 2 3 4 5` $\rightarrow$ No imprime movimientos, sale limpio.
* **Un único elemento:** `./push_swap 42` $\rightarrow$ No imprime nada, sale limpio.

---

## 8. Batería de Pruebas y Validación de Rendimiento

### 8.1 Comandos de Terminal para Verificación

```bash
# 1. Comprobar que no genera operaciones si ya está ordenado
./push_swap 1 2 3 4 5

# 2. Comprobar casos pequeños
ARG="2 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

# 3. Comprobar conteo con 100 números aleatorios (Objetivo: < 700 ops)
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

# 4. Comprobar conteo con 500 números aleatorios (Objetivo: < 5500 ops)
ARG=$(shuf -i 0-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(shuf -i 0-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

# 5. Comprobar modo benchmark con stderr redirigido
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt

# 6. Comprobar fugas de memoria con Valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 5 2 3 1 4
```

---

## 9. Requisitos del `README.md` y Reparto en Pareja

El `README.md` es evaluado formalmente en este proyecto y debe incluir obligatoriamente:
1. **Primera línea en cursiva obligatoria:**  
   *`Este proyecto ha sido creado como parte del currículo de 42 por <login1> y <login2>.`*
2. **Descripción:** Resumen del proyecto, motivación y restricciones.
3. **Instrucciones:** Compilación (`make`), ejecución y flags disponibles.
4. **Justificación algorítmica y de umbrales:**
   * Por qué se eligió $0.2$ y $0.5$ como puntos de corte del desorden.
   * Análisis de complejidad de tiempo y espacio de cada una de las 4 estrategias.
5. **Sección de Recursos y Uso de IA:** Declaración explícita de cómo y para qué se utilizó la IA durante el desarrollo.
6. **Reparto de Tareas (Contribución equitativa):** Detalle de qué módulos desarrolló o testeó cada miembro del equipo.

---

## 10. Preparación para la Evaluación y Live-Coding

Durante la defensa con vuestros pares:
* **Evaluación cruzada:** El evaluador preguntará indistintamente a cualquiera de los dos cómo funciona un algoritmo, cómo se enlazan los nodos o cómo se calcula el desorden. Ambos debéis dominar cada línea.
* **Prueba de Live-Coding:** Es muy probable que se os pida una pequeña modificación en directo (por ejemplo: invertir el orden para que ordene de mayor a menor, añadir una instrucción de depuración que cuente cuántos `pb` se ejecutaron, o cambiar el umbral de desorden de $0.2$ a $0.15$).  
  *Consejo:* Mantened el código limpio, bien modularizado con nombres de funciones autoexplicativos (`ft_sa()`, `sort_three()`, `push_to_b()`) para encontrar cualquier punto en cuestión de segundos.