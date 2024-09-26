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
* get_next_line_utils.c: Contiene las funciones auxiliares (ft_strlen, ft_strjoin, etc.) que ayudan a get_next_line.
* get_next_line.h: El archivo de cabecera que contiene las declaraciones de las funciones.
