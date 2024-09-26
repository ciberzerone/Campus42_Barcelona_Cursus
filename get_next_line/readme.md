![image](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/get_next_line/img/getsup.png)


# Get Next Line

## Descripción

El proyecto **Get Next Line** tiene como objetivo implementar una función que lea una línea de un archivo, sin importar el tamaño de la línea o el tamaño del archivo. Esta función debe funcionar tanto para descriptores de archivos (fd) como para la entrada estándar (`stdin`).

La función `get_next_line` puede ser llamada de manera repetitiva para obtener cada línea del archivo hasta llegar al final.

## Prototipo

```c
char *get_next_line(int fd);
fd: Es el descriptor de archivo del que se desea leer la línea.
```
##Valor Devuelto
La función devuelve la línea leída, incluyendo el carácter de salto de línea (\n), si es que existe.
Si no hay más líneas por leer o se encuentra un error, devuelve NULL.

## Archivos 
El proyecto incluye los siguientes archivos:

**get_next_line.c:** Contiene la implementación de la función get_next_line.
**get_next_line_utils.c:** Contiene las funciones auxiliares (ft_strlen, ft_strjoin, etc.) que ayudan a get_next_line.
**get_next_line.h:** El archivo de cabecera que contiene las declaraciones de las funciones.

## Funciones Autorizadas
Para completar el proyecto, solo están permitidas las siguientes funciones estándar de C:

read
malloc
free

## Ejemplo de Uso
A continuación se muestra un ejemplo de cómo utilizar la función get_next_line:
main.c 

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
## Explicación
* La función get_next_line lee el archivo descriptor (fd) hasta encontrar un salto de línea o el final del archivo.
* Se almacena el contenido leído en una variable estática llamada remainder para asegurar que se puedan concatenar los datos leídos entre distintas llamadas a get_next_line.
* Si se encuentra un salto de línea, la función devuelve la línea leída, y el resto del contenido (si existe) se almacena para la siguiente llamada.

## Cómo Compilar
Puedes compilar el proyecto utilizando un Makefile con el siguiente contenido:
```c
NAME = get_next_line

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```
Para compilar el proyect, simplemente ejecuta el siguiente comando:

```c
make
```

## Como ejecutar

Una vez que hayas compilado el proyecto, puedes ejecutar el programa con un archivo de prueba:

```c

./get_next_line test.txt


```


el programa imprimira cada linea del archivo en la salida estandar.



## Consideraciones

* La función debe manejar archivos de cualquier tamaño y líneas de cualquier longitud.
* Es importante manejar adecuadamente la memoria, liberando los bloques asignados por malloc cuando ya no se necesitan.
* El comportamiento de get_next_line debe ser consistente, independientemente del valor de BUFFER_SIZE que se utilice en la compilación.

##  Pruebas
Algunas pruebas que puedes realizar para verificar el correcto funcionamiento de get_next_line:

**1. Archivo vacío:** Asegúrate de que el programa devuelva NULL si el archivo está vacío.
**2. Archivo sin saltos de línea:** Verifica que se devuelva la línea completa si no hay saltos de línea.
**3. Varios BUFFER_SIZE:** Compila el programa con diferentes tamaños de BUFFER_SIZE para asegurar que el comportamiento sea consistente.

## Autor
Este proyecto fue desarrollado por Gianmarco Beltran como parte del currículo de la escuela 42.

## Licencia
Este proyecto no tiene licencia específica y se proporciona con fines educativos.
