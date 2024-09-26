# 💻📚 LIBFT 📚💻

![Banner](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/libft/img/libft.png)


## ¿Qué es Libft?

Programar en C puede ser complicado cuando no se tiene acceso a las funciones más comunes de la biblioteca estándar. **Libft** es un proyecto individual en 42 que nos desafía a recrear algunas de estas funciones. Este proyecto no solo es útil para futuros desafíos, sino que también profundiza nuestra comprensión de las estructuras de datos y algoritmos básicos.

En **42**, no se nos permite usar algunas bibliotecas estándar en nuestros proyectos, por lo que tenemos que crear nuestra propia biblioteca, que será muy útil en los siguientes proyectos de C.

---


# Implementación de Funciones

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
### ft_isalpha
**Descripción:** Comprueba si un carácter es alfabético (equivalente a ft_isupper o ft_islower).

**Parámetro:**
- c: El carácter a comprobar.
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
