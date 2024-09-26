#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
		return (1);
	}

	// Abrir el archivo especificado por el usuario
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)  // Si el archivo no se pudo abrir
	{
		printf("Error al abrir el archivo: %s\n", argv[1]);
		return (1);
	}

	// Leer cada línea usando get_next_line
	line = get_next_line(fd);
	if (!line)  // Verificar si el archivo está vacío
	{
		printf("El archivo está vacío o se ha llegado al final.\n");
	}
	else
	{
		// Si el archivo no está vacío, mostrar las líneas
		do {
			printf("%s\n", line);
			free(line);
		} while ((line = get_next_line(fd)) != NULL);
	}

	// Cerrar el archivo
	close(fd);
	return (0);
}

