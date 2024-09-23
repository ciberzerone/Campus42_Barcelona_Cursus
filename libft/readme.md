# 💻📚 LIBFT 📚💻

![Banner](https://github.com/DanielEspanadero/libft-42/blob/master/docs/banner%20libft.png)

> **NOTA**  
> Este es el primer proyecto como estudiante de 42. Consiste en programar algunas funciones de la librería estándar de C, así como otras funciones que serán útiles a lo largo del cursus.

## ¿Qué es Libft?

Programar en C puede ser complicado cuando no se tiene acceso a las funciones más comunes de la biblioteca estándar. **Libft** es un proyecto individual en 42 que nos desafía a recrear algunas de estas funciones. Este proyecto no solo es útil para futuros desafíos, sino que también profundiza nuestra comprensión de las estructuras de datos y algoritmos básicos.

En **42**, no se nos permite usar algunas bibliotecas estándar en nuestros proyectos, por lo que tenemos que crear nuestra propia biblioteca, que será muy útil en los siguientes proyectos de C.

---

## ¿En qué consiste?

Libft se divide en 4 secciones:

1. **Funciones de Libc:** Implementación de funciones estándar de la biblioteca C.
2. **Funciones adicionales:** Funciones adicionales que serán útiles en proyectos posteriores.
3. **Parte Bonus:** Funciones útiles para la manipulación de listas.
4. **Funciones personales:** Funciones creadas para facilitar proyectos futuros.

---

## Conceptos clave para completar Libft

> **IMPORTANTE**  
> A continuación, una serie de videos que te ayudarán a entender los conceptos básicos de Libft y sentar unas bases sólidas para futuros proyectos.

### Punteros en C

<a href='https://www.youtube.com/watch?v=y3K3jb3wv2I' target='_blank'>
  <img width='30%' src='https://github.com/DanielEspanadero/libft-42/blob/master/docs/Punteros%20en%20c.jpg' alt='Punteros en C' />
</a>

### Struct en C

<a href='https://www.youtube.com/watch?v=plTYF-btLuU' target='_blank'>
  <img width='30%' src='https://github.com/DanielEspanadero/libft-42/blob/master/docs/estructuras%20en%20c.jpg' alt='Struct en C' />
</a>

### Makefile

<a href='https://www.youtube.com/watch?v=BD0giwqBbm0' target='_blank'>
  <img width='30%' src='https://github.com/DanielEspanadero/libft-42/blob/master/docs/makefile.png' alt='Makefile' />
</a>

### Listas enlazadas

PRÓXIMAMENTE

---

# Implementación de Funciones

A continuación, se presentan algunas de las funciones más comunes implementadas en el proyecto **Libft**.

## ft_is

### ft_isalnum
**Descripción:** Comprueba si un carácter es alfanumérico (equivalente a `ft_isalpha` o `ft_isdigit`).

**Parámetro:**  
- `c`: El carácter a comprobar.

**Valor de retorno:**  
- `1` si el carácter es alfanumérico, `0` en caso contrario.

```c
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
```
ft_isalpha
Descripción: Comprueba si un carácter es alfabético (equivalente a ft_isupper o ft_islower).

Parámetro:

c: El carácter a comprobar.
Valor de retorno:

1 si el carácter es alfabético, 0 en caso contrario.
```c
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
```

ft_isascii
Descripción: Comprueba si un carácter pertenece al conjunto ASCII.

Parámetro:

c: El carácter a comprobar.
Valor de retorno:

1 si el carácter es ASCII, 0 en caso contrario.
c
Copy code
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
ft_lst
ft_lstadd_back
Descripción: Añade un nuevo elemento al final de una lista enlazada.

Parámetros:

lst: Puntero al primer elemento de la lista.
new: Nuevo elemento a añadir.
Valor de retorno:

Ninguno.

```c
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	new->next = last->next;
	last->next = new;
}
```
ft_lstadd_front
Descripción: Añade un nuevo elemento al principio de una lista enlazada.

Parámetros:

lst: Puntero al primer elemento de la lista.
new: Nuevo elemento a añadir.
Valor de retorno:

Ninguno.
c
Copy code
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
ft_lstclear
Descripción: Elimina y libera la memoria de todos los elementos de una lista enlazada.

Parámetros:

lst: Puntero al primer elemento de la lista.
del: Función para eliminar los datos de cada elemento.
Valor de retorno:

Ninguno.
c
Copy code
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	while (curr)
	{
		next = curr->next;
		ft_lstdelone(curr, del);
		curr = next;
	}
	*lst = NULL;
}
ft_lstdelone
Descripción: Elimina y libera un elemento específico de una lista enlazada.

Parámetros:

lst: Puntero al elemento de la lista.
del: Función para eliminar los datos del elemento.
Valor de retorno:

Ninguno.
c
Copy code
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
(El contenido del README.md sigue con las funciones adicionales como ft_mem, ft_put, ft_str, ft_to, etc.)

## 🧑‍💻 Autor
<a href='https://github.com/ciberzerone/'>ciberzerone
GitHub </a>
