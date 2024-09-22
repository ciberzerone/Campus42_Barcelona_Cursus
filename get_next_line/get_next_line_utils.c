#include "get_next_line.h"
#include <string.h>  // Para el uso de memcpy y otras funciones de manejo de cadenas
		     //
char *ft_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while (*src) {
        *ptr++ = *src++;
    }
    *ptr = '\0';  // Asegura que la cadena esté terminada en NULL
    return dest;
}

size_t ft_strlen(const char *s) {
    size_t len = 0;
    while (s[len]) {
        len++;
    }
    return len;
}

char *ft_strdup(const char *s) {
    char *dup;
    size_t len = ft_strlen(s) + 1;

    dup = (char *)malloc(len);
    if (!dup) {
        return NULL;
    }
    return (char *)memcpy(dup, s, len);
}

char *ft_strchr(const char *s, int c) {
    while (*s) {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}

char *ft_strjoin(char *s1, char *s2) {
    char *joined;
    size_t len1 = s1 ? ft_strlen(s1) : 0;
    size_t len2 = s2 ? ft_strlen(s2) : 0;

    joined = (char *)malloc(len1 + len2 + 1);
    if (!joined) {
        return NULL;
    }
    if (s1) {
        ft_strcpy(joined, s1);
    }
    if (s2) {
        ft_strcpy(joined + len1, s2);
    }
    free(s1);
    return joined;
}

