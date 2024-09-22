char *get_next_line(int fd) {
    static char *remainder = NULL;
    char buffer[BUFFER_SIZE + 1];
    char *newline_pos;
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL;
    }

    // Limpiar el buffer antes de leer
    memset(buffer, 0, BUFFER_SIZE + 1);

    // Leer hasta encontrar una nueva línea o el final del archivo
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);  // Concatenar el buffer leído al restante

        // Verificar si encontramos un salto de línea en lo que hemos leído
        if ((newline_pos = ft_strchr(remainder, '\n'))) {
            *newline_pos = '\0';  // Terminar la línea
            line = ft_strdup(remainder);  // Copiar la línea completa

            // Mover el contenido restante al inicio de `remainder`
            char *temp = ft_strdup(newline_pos + 1);  // Lo que queda después del '\n'
            free(remainder);
            remainder = temp;

            return line;
        }
    }

    // Si llegamos al final del archivo o no hay más contenido
    if (remainder && *remainder) {
        line = ft_strdup(remainder);  // Copiar lo que queda
        free(remainder);
        remainder = NULL;
        return line;
    }

    return NULL;  // Nada más que leer
}
