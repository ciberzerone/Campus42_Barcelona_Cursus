#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

// Definición del tamaño del buffer
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

// Declaraciones de funciones
char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strcpy(char *dest, const char *src);

#endif
