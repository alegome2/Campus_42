*Este proyecto ha sido creado como parte del currículo de 42 por alegome2.*

# ft_printf

## Descripción

**ft_printf** es un proyecto del cursus de 42 cuyo objetivo principal es recrear el comportamiento de la función estándar `printf` de la biblioteca estándar de C (`libc`). La realización de este proyecto permite profundizar en el uso de funciones variádicas mediante las macros de `<stdarg.h>`, la gestión segura de memoria dinámica (`malloc`/`free`) y el formateo de datos a bajo nivel empleando la llamada al sistema `write`.

La biblioteca estática resultante (`libftprintf.a`) sirve como herramienta reutilizable para proyectos posteriores del cursus donde las funciones estándar de salida están restringidas.

## Descripción Detallada de la Biblioteca

La función principal `ft_printf` analiza una cadena de formato e imprime la salida correspondiente según los especificadores encontrados, devolviendo el número total de caracteres impresos (o `-1` en caso de recibir una cadena nula).

### Funciones Variádicas y `<stdarg.h>`

Una función variádica es aquella que puede recibir un número variable de argumentos. En C, esto se indica en el prototipo mediante puntos suspensivos (`...`) tras al menos un parámetro fijo (en este caso, `char const *str`). Para gestionar estos argumentos indeterminados, se emplean las macros provistas por la cabecera `<stdarg.h>`:

* **`va_list`:** Tipo de dato utilizado como puntero/estado para iterar sobre la lista de argumentos variables.
* **`va_start(args, str)`:** Inicializa la variable `va_list` posicionándola en el primer argumento variable inmediatamente posterior al parámetro fijo `str`.
* **`va_arg(args, tipo)`:** Recupera el valor del argumento actual interpretándolo según el `tipo` especificado y avanza automáticamente el puntero hacia el siguiente argumento en la lista.
* **`va_end(args)`:** Limpia y finaliza el acceso a la lista de argumentos variádicos, garantizando un retorno seguro de la función.

### Especificadores de Formato Soportados

**`%c`** - Imprime un único carácter.

* *Retorna:* `1` (el byte del carácter emitido).

**`%s`** - Imprime una cadena de caracteres (`char *`).

* *Comportamiento especial:* Si el puntero recibido es `NULL`, imprime `(null)`.

* *Retorna:* La cantidad total de caracteres impresos (o `6` si el puntero es nulo).

**`%p`** - Imprime una dirección de memoria en formato hexadecimal en minúsculas precedida del prefijo `0x`.

* *Comportamiento especial:* Si el puntero recibido es `NULL` / `0`, imprime `(nil)`.

* *Retorna:* La cantidad total de caracteres impresos (incluyendo el prefijo `0x` o la cadena `(nil)`).

**`%d` / `%i`** - Imprime un número entero con signo en base 10 (`int`).

* *Implementación:* Emplea `ft_itoa` para convertir el entero a cadena dinámica y libera la memoria con `free` sin generar fugas de memoria (*memory leaks*).

* *Retorna:* La cantidad total de caracteres y signos impresos.

**`%u`** - Imprime un número decimal sin signo en base 10 (`unsigned int`).

* *Implementación:* Algoritmo recursivo en base 10 que descompone el número e imprime cada dígito.

* *Retorna:* La cantidad total de dígitos impresos.

**`%x`** - Imprime un número en formato hexadecimal en minúsculas (`0123456789abcdef`).

* *Implementación:* Descomposición recursiva en base 16.

* *Retorna:* La cantidad de caracteres impresos.

**`%X`** - Imprime un número en formato hexadecimal en mayúsculas (`0123456789ABCDEF`).

* *Implementación:* Descomposición recursiva en base 16 con alfabeto en mayúsculas.

* *Retorna:* La cantidad de caracteres impresos.

**`%%`** - Imprime el símbolo de porcentaje literal (`%`).

* *Retorna:* `1`.

### Módulos Internos del Proyecto

* **`ft_printf.c`:** Contiene la función principal `ft_printf` que itera sobre la cadena de formato, gestiona la lista variádica `va_list` (`va_start`, `va_end`) y delega las conversiones en la función estática `check_format`.

* **`ft_print_char.c`:** Emite un carácter individual a la salida estándar mediante `write`.

* **`ft_print_str.c`:** Emite cadenas de caracteres protegiendo de desreferenciaciones en caso de punteros nulos.

* **`ft_print_ptr.c`:** Formatea punteros emitiendo el prefijo `0x` y convirtiendo la dirección con `ft_print_hex`.

* **`ft_print_int.c`:** Gestiona la conversión numérica con `ft_itoa` y garantiza la liberación de memoria dinámica.

* **`ft_print_unsigned.c`:** Algoritmo recursivo para números enteros sin signo.

* **`ft_print_hex.c`:** Algoritmo genérico recursivo en base 16 para minúsculas y mayúsculas.

* **`ft_itoa.c`:** Función auxiliar que convierte enteros a cadenas de texto reservando memoria mediante `malloc`.

## Instrucciones

### Requisitos Previos

* Un compilador de C (`gcc` o `clang`)

* Herramienta de compilación `make`

* Utilidad de archivo `ar`

### Compilación

El proyecto incluye un `Makefile` configurado con los flags obligatorios `-Wall -Wextra -Werror` que compila todos los archivos fuente y empaqueta la biblioteca estática `libftprintf.a`.

Ejecuta los siguientes comandos en la raíz del repositorio:

* **`make`** (o **`make all`**) - Compila los archivos fuente y genera `libftprintf.a`.

* **`make clean`** - Elimina los archivos objeto (`.o`).

* **`make fclean`** - Elimina los archivos objeto y la biblioteca `libftprintf.a`.

* **`make re`** - Limpia y recompila toda la biblioteca desde cero.

### Uso

Para compilar y enlazar `libftprintf.a` con un programa en C:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_printf
```

Ejemplo de uso en un archivo `main.c`:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hola %s! Número: %d, Hex: %x, Ptr: %p\n", "42", 42, 42, &count);
	ft_printf("Total de caracteres impresos: %d\n", count);
	return (0);
}
```

## Recursos

### Referencias Clásicas

* **Páginas del Manual de Linux (`man 3 printf`, `man 3 stdarg`):** Referencia estándar para el comportamiento de especificadores de formato y el ciclo de vida de argumentos variádicos.

* **Norma de 42 (Norminette v4):** Cumplimiento riguroso de estilo y estructura (máximo de 25 líneas por función, funciones estáticas locales y declaración de una variable por línea).

### Uso de IA

La Inteligencia Artificial se empleó como herramienta de soporte analítico y aseguramiento de calidad:

* **Análisis de Casos Límite (*Edge Cases*):** Detección y blindaje ante cadenas de formato nulas (`ft_printf(NULL)`), punteros nulos en `%s` (`(null)`), punteros nulos en `%p` (`(nil)`) y prevención de desbordamiento en caracteres `%` al final del formato.

* **Optimización y Cumplimiento Normativo:** Refactorización y reducción del cuerpo de `ft_printf.c` para mantenerse holgadamente por debajo del límite de 25 líneas sin comprometer legibilidad ni funcionalidad.