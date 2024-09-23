![image](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/printf/img/bannesup.png)

# ft_printf

## Descripción

`ft_printf` es una implementación personalizada de la función estándar `printf` de la biblioteca C. Este proyecto forma parte del currículo de la escuela 42, y tiene como objetivo profundizar en conceptos de manipulación de cadenas, conversión de tipos y gestión de formatos de salida, al tiempo que se respetan las normativas de la escuela.

## Características

- Maneja los siguientes especificadores de formato: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, y `%%`.
- Soporta los modificadores de ancho y precisión para especificar el formato de salida.
- Gestión adecuada de las cadenas de formato, incluso en casos de errores y entradas inesperadas.
- No se permiten variables globales, siguiendo la Norme de 42.

## Requisitos

- El proyecto debe compilarse usando `gcc` con los flags `-Wall -Wextra -Werror`.
- El código debe seguir la Norme de 42.
- La memoria debe gestionarse correctamente sin fugas.

## Instalación

Clona este repositorio en tu máquina local:

```bash
git clone https://github.com/tuusuario/ft_printf.git
cd ft_printf
# Compila el proyecto usando el Makefile:
make
```
## Uso
Para usar ft_printf en tu propio código, simplemente incluye el archivo de cabecera ft_printf.h y compila tu proyecto con la librería generada:


```bash
#include "ft_printf.h"

int main(void) {
    ft_printf("Hola, %s!\n", "mundo");
    return 0;
}
```
## gcc main.c ft_printf.a -o programa
./programa 

Compila y ejecuta tu código:


## Estructura del Proyecto
src/: Contiene los archivos fuente de la implementación de ft_printf.
include/: Contiene el archivo de cabecera ft_printf.h.
Makefile: Archivo para automatizar la compilación del proyecto.
Especificadores Soportados
%c: Caracter.
%s: Cadena de caracteres.
%p: Dirección de memoria (puntero).
%d/%i: Entero con signo.
%u: Entero sin signo.
%x/%X: Número hexadecimal (minúsculas y mayúsculas).
%%: Imprime el símbolo %.

## Autor
Este proyecto fue desarrollado por Gianmarco Beltran como parte del currículo de la escuela 42.

## Licencia
Este proyecto no tiene licencia específica y se proporciona con fines educativos.

