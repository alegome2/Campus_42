*Este proyecto ha sido creado como parte del currículo de 42 por alegome2.*

# get_next_line

## Descripción

**get_next_line** es un proyecto del cursus de 42 cuyo propósito primordial es desarrollar una función en C capaz de leer y devolver, línea por línea, el contenido de un descriptor de archivo (*file descriptor*, `fd`).

La realización de este proyecto permite asimilar en profundidad la gestión de llamadas al sistema de bajo nivel (`read`), la preservación de estado en tiempo de ejecución mediante **variables estáticas**, el dimensionamiento dinámico de memoria en el *heap* (`malloc`/`free`) y la prevención absoluta de fugas de memoria (*memory leaks*), garantizando un comportamiento determinista independientemente del tamaño de lectura configurado en compilación (`BUFFER_SIZE`).

---

## Descripción Detallada del Funcionamiento

El prototipo normativo de la función es:

```c
char	*get_next_line(int fd);
```

Cada invocación sucesiva a `get_next_line` retorna un puntero a una cadena terminada en `\0` que contiene los caracteres leídos desde el archivo hasta el primer salto de línea (`\n`) inclusive (o hasta el fin de archivo, `EOF`). Cuando no quedan más líneas por leer o si ocurre un error de lectura o reserva de memoria, la función retorna `NULL`.

### Conceptos Fundamentales

#### 1. La Variable Estática (`static char *stash`)
A diferencia de las variables automáticas locales que se destruyen al salir del ámbito de ejecución (*stack frame*), una variable declarada con el especificador `static` se almacena en el segmento de memoria permanente del programa (**Data / BSS**) y **conserva su valor entre llamadas consecutivas**.
* Actúa como almacén o acumulador temporal (`stash`).
* Permite retener los bytes leídos por `read()` que sobrepasan el delimitador `\n` actual para que queden disponibles en la siguiente invocación a la función.

#### 2. Llamada al Sistema `read()` y Descriptores de Archivo
La interacción con el archivo se realiza mediante el system call `read(fd, buffer, BUFFER_SIZE)`:
* **`> 0`:** Número exacto de bytes leídos y volcados en el búfer temporal.
* **`0`:** Fin de archivo alcanzado (`EOF`).
* **`-1`:** Error de entrada/salida (descriptor inválido, permisos insuficientes, etc.).
* `read()` no coloca un terminador nulo `'\0'` al final del bloque transferido; el código gestiona explícitamente la terminación de cada cadena antes de cualquier operación.

---

## Arquitectura y Flujo de Ejecución

El diseño modular del proyecto desacopla el ciclo de vida de la lectura en tres etapas secuenciales estrictas:

```text
               ┌───────────────────────┐
               │  get_next_line(fd)    │
               └──────────┬────────────┘
                          │
                          ▼
            ┌────────────────────────────┐
            │ 1. read_and_stash(fd, s)   │
            │ Lee del archivo y acumula  │
            │ hasta encontrar '\n' o EOF │
            └─────────────┬──────────────┘
                          │
                          ▼
            ┌────────────────────────────┐
            │ 2. extract_line(stash)     │
            │ Extrae la subcadena desde  │
            │ 0 hasta '\n' (inclusive)   │
            └─────────────┬──────────────┘
                          │
                          ▼
            ┌────────────────────────────┐
            │ 3. clean_stash(stash)      │
            │ Descarta la línea enviada, │
            │ duplica el sobrante y      │
            │ libera la memoria vieja    │
            └─────────────┬──────────────┘
                          │
                          ▼
                 [ Retorna line ]
```

### Módulos y Funciones

* **`get_next_line.c`:**
  * **`get_next_line`:** Punto de entrada. Valida los parámetros (`fd >= 0`, `BUFFER_SIZE > 0`), coordina la lectura, extrae la línea, actualiza la variable estática y retorna el resultado.
  * **`read_and_stash`:** Bucle de lectura que llama a `read()`, añade terminadores nulos y concatena el búfer leído a `stash` mediante `ft_strjoin` hasta encontrar un salto de línea o llegar al final del archivo.
  * **`extract_line`:** Reserva el tamaño exacto con `malloc` (hasta el `\n` y su `\0`), copiando los caracteres correspondientes a la línea lista para ser entregada al usuario.
  * **`clean_stash`:** Localiza el salto de línea, duplica el sobrante posterior mediante `ft_strdup`, libera la memoria anterior del `stash` con `free()` y retorna el nuevo puntero residual (o `NULL` si no quedaron caracteres pendientes).

* **`get_next_line_utils.c`:**
  * **`ft_strlen`:** Calcula la longitud de una cadena de texto.
  * **`ft_strchr`:** Localiza la primera ocurrencia del carácter delimitador `\n` en el acumulador.
  * **`ft_strjoin`:** Concatena el contenido del acumulador actual con el nuevo búfer leído, liberando la memoria previa para evitar fugas.
  * **`ft_strdup`:** Duplica cadenas en memoria dinámica para salvaguardar el remanente en `clean_stash`.

---

## Gestión de Memoria y Prevención de Fugas (Leaks)

Cada bloque reservado en memoria dinámica (`heap`) está sujeto a un estricto ciclo de vida:

| Escenario Crítico | Riesgo Potencial | Mecanismo de Control |
| :--- | :--- | :--- |
| Error en `read` (`-1`) | El `stash` previo quedaría inaccesible en el heap. | Se libera `stash` con `free()` explícito y se retorna `NULL`. |
| Duplicación de remanente | Sobreescritura del puntero original de `stash`. | `clean_stash` ejecuta siempre `free(stash)` tras la copia con `ft_strdup`. |
| Fin de archivo (`EOF`) | Puntero estático retendría un bloque sin uso. | `clean_stash` libera y devuelve `NULL`, reseteando el estado base. |
| Consumo de línea | Toda línea devuelta fue asignada con `malloc`. | El llamante (`main`) es responsable de invocar `free(line)` por cada línea procesada. |

---

## Instrucciones

### Requisitos Previos

* Un compilador de C (`gcc` o `clang`).
* Archivos fuente del proyecto: `get_next_line.c`, `get_next_line_utils.c` y `get_next_line.h`.

### Compilación

El proyecto se compila junto con el programa de prueba especificando el tamaño de búfer deseado mediante la macro `-D BUFFER_SIZE=n`:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Ejemplo de Uso

Ejemplo de implementación en un archivo `main.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_num;

	fd = open("archivo.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir archivo");
		return (1);
	}
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[Línea %d]: %s", line_num, line);
		free(line);
		line_num++;
	}
	close(fd);
	return (0);
}
```

---

## Casos de Prueba Esenciales (*Edge Cases*)

1. **Variación de `BUFFER_SIZE`:**
   * `BUFFER_SIZE = 1`: Obliga a realizar llamadas mínimas y maximiza la concatenación continua.
   * `BUFFER_SIZE = 10000000`: Verifica la estabilidad frente a reservas de gran tamaño sin desbordar memoria.
2. **Líneas vacías consecutivas (`\n\n`):** Retorno de cadenas compuestas únicamente por el salto de línea `\n\0`.
3. **Archivos sin salto de línea final:** Comprobación de que la última secuencia de texto se emita completa y que la llamada inmediata posterior devuelva `NULL`.
4. **Descriptores inválidos:** Verificación de retorno de `NULL` inmediato ante `fd < 0` (por ejemplo, `-1` o descriptores no inicializados).

---

## Recursos

### Referencias Clásicas

* **Páginas del Manual de Linux (`man 2 read`, `man 3 malloc`, `man 3 free`, `man 2 open`):** Documentación del estándar POSIX para operaciones de entrada/salida y memoria dinámica.
* **Norma de 42 (Norminette v4):** Cumplimiento riguroso de estilo (funciones limitadas a un máximo de 25 líneas, hasta 4 parámetros, variables declaradas al inicio y prohibición del operador coma `,`).

### Aprendizaje Peer-to-Peer

* **Evaluaciones entre pares (*peer-evaluations*):** Puesta en común del código con otros estudiantes de la escuela para validar la solidez del flujo lógico, contrastar alternativas en la gestión de memoria dinámica y verificar el cumplimiento riguroso de la Norminette.
* **Defensa y argumentación técnica:** Discusión y resolución de dudas sobre casos límite (*edge cases*) —como la gestión de descriptores cerrados, líneas vacías consecutivas o desbordamientos con `BUFFER_SIZE` extremos—, consolidando el dominio del proyecto al explicar y justificar cada decisión de diseño frente a un compañero.

### Uso de IA

La Inteligencia Artificial se empleó como herramienta de soporte analítico y aseguramiento de calidad:

* **Auditoría de Gestión de Memoria:** Análisis estricto de bifurcaciones en `clean_stash` para garantizar la liberación de memoria en fallos de `ft_strdup` o en condiciones terminales de fin de archivo.
* **Refactorización Normativa:** Ajuste y simplificación del flujo principal de `get_next_line` y sus funciones auxiliares para respetar holgadamente los límites de la Norminette sin recurrir a sentencias comprimidas.