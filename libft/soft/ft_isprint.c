#include <stdio.h>
int isprint(int c)
{
if (c>=32 && c<=126)
    return 1;
return 0;
}
int main()
{
    int i = 'g';
    printf("dato: %d\n", isprint(i));
    printf("dato: %c\n", i);
    printf("El valor ASCII de '%c' es: %d\n", i, i);
    printf("dato: %x\n", isprint(i));
    printf("direccion de memoria: %p\n", (void*)&i);
    return 0;
}