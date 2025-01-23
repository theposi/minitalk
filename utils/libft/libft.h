/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:37:19 by crizapat          #+#    #+#             */
/*   Updated: 2024/03/26 14:26:37 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Comprueba si un caracter es alfanumerico
 * @param charac caracter a comprobar
 * @return 1 si es alfanumerico, 0 si no lo es
 */
int					ft_isalpha(int charac);

/**
 * Comprueba si un caracter es numerico
 * @param numb caracter a comprobar
 * @return 1 si es numerico, 0 si no lo es
 */
int					ft_isdigit(int numb);

/**
 * Comprueba si un caracter es alfanumerico
 * @param alnum caracter a comprobar
 * @return 1 si es alfanumerico, 0 si no lo es
 */
int					ft_isalnum(int alnum);

/**
 * Comprueba si un caracter es imprimible
 * @param ascii caracter a comprobar
 * @return 1 si es imprimible, 0 si no lo es
 */
int					ft_isascii(int ascii);

/**
 * Comprueba si un caracter es imprimible
 * @param print caracter a comprobar
 * @return 1 si es imprimible, 0 si no lo es
 */
int					ft_isprint(int print);

/**
 * Calcula la longitud de una cadena
 * @param str cadena a calcular
 * @return longitud de la cadena
 */
size_t				ft_strlen(const char *str);

/**
 * Establece los primeros len bytes del área de memoria
 * apuntada por ptr al valor charac.
 * @param ptr Puntero al área de memoria a establecer.
 * @param charac Valor a establecer.
 * @param len Número de bytes a establecer.
 * @return Puntero a la cadena establecida
 */
void				*ft_memset(void *ptr, int charac, size_t len);

/**
 * Establece los primeros len bytes del área de memoria
 * apuntada por ptr al valor 0.
 * @param ptr Puntero al área de memoria a establecer.
 * @param len Número de bytes a establecer.
 */
void				ft_bzero(void *ptr, size_t len);

/**
 * Copia len bytes de src a dest
 * @param dst cadena destino
 * @param src cadena origen
 * @param len numero de bytes a copiar
 * @return puntero a la cadena destino
 */
void				*ft_memcpy(void *dst, const void *src, size_t len);

/**
 * Copia len bytes de src a dest
 * Si las cadenas se solapan, el comportamiento es indefinido
 * @param dst cadena destino
 * @param src cadena origen
 * @param len numero de bytes a copiar
 * @return puntero a la cadena destino
 */
void				*ft_memmove(void *dst, const void *src, size_t len);

/**
 * Copia una cadena en otra
 * @param dst cadena destino
 * @param src cadena origen
 * @param len numero de caracteres a copiar
 * @return longitud de la cadena copiada
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t len);

/**
 * Concatena dos cadenas
 * @param dst cadena destino
 * @param src cadena origen
 * @param len numero de caracteres a copiar
 * @return longitud de la cadena copiada
 */
size_t				ft_strlcat(char *dst, const char *src, size_t len);

/**
 * Convierte un caracter a mayusculas
 * @param charac caracter a convertir
 * @return caracter convertido
 */
int					ft_toupper(int charac);

/**
 * Convierte un caracter a minusculas
 * @param charac caracter a convertir
 * @return caracter convertido
 */
int					ft_tolower(int charac);

/**
 * Busca un caracter en una cadena
 * @param str Cadena en la que buscar.
 * @param charac Caracter a buscar.
 * @return Retorna un puntero a la primera aparición del carácter en la cadena.
 * Si no se encuentra el carácter se devuelve NULL
 */
char				*ft_strchr(const char *str, int charac);

/**
 * Busca un caracter en una cadena empezando por el final
 * @param str Cadena en la que buscar.
 * @param chr Caracter a buscar.
 * @return Retorna un puntero a la primera aparición del carácter en la cadena.
 * Si no se encuentra el carácter se devuelve NULL
 */
char				*ft_strrchr(const char *str, int charac);

/**
 * Compara dos cadenas
 * @param str1 cadena 1
 * @param str2 cadena 2
 * @param len numero de caracteres a comparar
 * @return 0 si son iguales, <0 si str1 es menor que str2,
 * >0 si str1 es mayor que str2
 */
int					ft_strncmp(const char *str1, const char *str2, size_t len);

/**
 * Busca la primera aparición de un carácter en un bloque de memoria
 * @param ptr puntero al inicio del bloque de memoria
 * @param charac carácter a buscar
 * @param len longitud del bloque de memoria en bytes
 * @return Retorna un puntero al primer byte donde se encuentra el carácter,
 * o NULL si el carácter no se encuentra en el bloque de memoria
 */
void				*ft_memchr(const void *ptr, int charac, size_t len);

/**
 * Compara dos bloques de memoria byte a byte.
 * @param str1 Puntero al primer bloque de memoria.
 * @param str2 Puntero al segundo bloque de memoria.
 * @param len El número de bytes a comparar.
 * @return 0 si los bloques son idénticos,
 * un valor menor que 0 si str1 es menor que str2,
 * un valor mayor que 0 si str1 es mayor que str2.
 */
int					ft_memcmp(const void *str1, const void *str2, size_t len);

/**
 * Encuentra la primera aparición de la subcadena to_find en la cadena str.
 * @param haystack Cadena en la que buscar.
 * @param needle Subcadena a buscar.
 * @param len Numero de caracteres a comparar
 * @return Retorna la posición de la primera aparición de str_to_find en str.
 * Si no se encuentra la subcadena se devuelve NULL
 */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

/**
 * Convierte una cadena str a un entero
 * Puede contener caracteres del isspace antes del numero
 * y un signo + o - antes del numero
 * Si el numero es mayor que el maximo entero devuelve el maximo entero
 * @param str cadena a convertir
 * @return entero convertido
 */
int					ft_atoi(const char *str);

/**
 * Reserva memoria con malloc y la inicializa a 0
 * @param items numero de elementos
 * @param size tamaño de cada elemento
 * @return puntero a la memoria reservada
 */
void				*ft_calloc(size_t items, size_t size);

/**
 * Reserva memoria con malloc y copia una cadena en ella
 * @param str cadena a copiar
 * @return puntero a la cadena copiada
 */
char				*ft_strdup(const char *str);

/**
 * Reserva (con malloc(3)) y devuelve una substring de la string ’str’.
 * La subcadena comienza en la posición 'start' y tiene una longitud
 * máxima de 'len'.
 * Si 'start' es mayor que la longitud de la cadena, devuelve una cadena vacía.
 * Si 'len' especifica una longitud mayor que la longitud restante de la
 * cadena después de 'start',
 * la subcadena contendrá solo los caracteres restantes de la cadena.
 * @param s La cadena de la cual se extraerá la subcadena.
 * @param start La posición inicial desde la cual se extraerá la subcadena.
 * @param len La longitud máxima de la subcadena a extraer.
 * @return Un puntero a la subcadena extraída, o NULL si falla la
 * asignación de memoria.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Reserva (con malloc(3)) y devuelve una nueva string,
 * formada por la concatenación de ’s1’ y ’s2’.
 * @param s1 Primera cadena
 * @param s2 Segunda cadena
 * @return Cadena concatenada
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * Elimina todos los caracteres de la string ’set’
 * desde el principio y desde el final de ’s1’,
 * hasta encontrar un caracter no perteneciente a ’set’.
 * @param str Cadena a recortar
 * @param set Caracteres a recortar
 * @return String resultante se devuelve con una reserva de malloc(3)
 */
char				*ft_strtrim(char const *str, char const *set);

/**
 * Reserva (con malloc(3)) y devuelve un array de strings
 * obtenidas al separar ’str’ mediante el carácter ’chr’,
 * El array debe terminar con NULL.
 * @param str Cadena a separar
 * @param charac Caracter separador
 * @return Array de strings resultante
 */
char				**ft_split(char const *str, char charac);

/**
 * Convierte un entero a una cadena y reserva memoria con malloc(3)
 * Se contemplan los numeros negativos
 * @param num Entero a convertir
 * @return Cadena resultante
 */
char				*ft_itoa(int num);

/**
 * Aplica la función ’f’ a cada caracter de la cadena ’str’
 * para crear una nueva cadena (con malloc(3))
 * que resulte de las aplicaciones sucesivas de ’f’.
 * @param str Cadena sobre la que aplicar la función
 * @param f Función a aplicar
 * @return Cadena resultante
*/
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));

/**
 * Aplica la función 'f' a cada carácter de la cadena 'str' junto con
 * su índice correspondiente.
 * La función 'f' toma dos argumentos: el índice del carácter y
 * una referencia al carácter actual.
 * Si 'str' o 'f' son NULL, la función no hace nada.
 * @param str La cadena a iterar.
 * @param f La función a aplicar a cada carácter.
 */
void				ft_striteri(char *str, void (*f)(unsigned int, char*));

/**
 * Escribe el carácter 'charac' en el descriptor de archivo dado 'fd'.
 * @param charac el carácter a escribir.
 * @param fd el descriptor de archivo donde se escribirá el carácter.
 */
void				ft_putchar_fd(char charac, int fd);

/**
 * Escribe la cadena de caracteres 'str' en el descriptor de archivo dado 'fd'.
 * @param str La cadena de caracteres a escribir.
 * @param fd El descriptor de archivo donde se escribirá la cadena.
 */
void				ft_putstr_fd(char *str, int fd);

/**
 * Escribe la cadena de caracteres 's' seguida de un salto de línea en el
 * descriptor de archivo dado 'fd'.
 * @param s La cadena de caracteres a escribir.
 * @param fd El descriptor de archivo donde se escribirá la cadena
 * y el salto de línea.
 */
void				ft_putendl_fd(char *str, int fd);

/**
 * Escribe el número entero 'num' en el descriptor de archivo dado 'fd'.
 * @param num El número entero a escribir.
 * @param fd El descriptor de archivo donde se escribirá el número.
 */
void				ft_putnbr_fd(int num, int fd);

/**
 * Crea un nuevo nodo utilizando malloc(3).
 * La variable miembro ’content’ se inicializa con el
 * contenido del parámetro ’content’. La variable ’next’, con NULL
 * @param content Contenido del nodo nuevo
 * @return Nuevo nodo
 */
t_list				*ft_lstnew(void *content);

/**
 * Añade el nodo ’new’ al principio de la lista ’lst’
 * @param lst  dirección de un puntero al primer nodo de una lista.
 * @param new  un puntero al nodo que añadir al principio de la lista.
 */
void				ft_lstadd_front(t_list **lst, t_list *new_node);

/**
 * Cuenta el número de nodos de una lista.
 * @param lst  inicio de la lista.
 * @return número de nodos.
 */
int					ft_lstsize(t_list *lst);

/**
 * Devuelve el último nodo de la lista.
 * @param lst  inicio de la lista.
 * @return último nodo de la lista.
*/
t_list				*ft_lstlast(t_list *lst);

/**
 * Añade el nodo ’new’ al final de la lista.
 * @param lst  dirección de un puntero al primer nodo de una lista.
 * @param new  un puntero al nodo que añadir al final de la lista.
*/
void				ft_lstadd_back(t_list **lst, t_list *new_node);

/**
 * Libera la memoria del nodo pasado como argumento
 * utilizando la función ’del’ y después libera el nodo.
 * @param lst  dirección de un puntero al nodo que hay que liberar.
 * @param del  función que permite liberar el contenido
*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * Libera la memoria de ’lst’ y de todos sus nodos.
 * @param lst  dirección de un puntero al primer nodo de la lista a liberar.
 * @param del  función que permite liberar el contenido de un nodo.
*/
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Itera sobre la lista ’lst’ y aplica la función ’f’
 * @param lst  dirección de un puntero al primer nodo de una lista.
 * @param f  dirección de la función que hay que aplicar.
*/
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Itera sobre la lista ’lst’ y aplica la función ’f’ a los nodos.
 * Crea una nueva lista con el resultado.
 * @param lst  dirección de un puntero al primer nodo de una lista.
 * @param f  función que hay que aplicar.
 * @return nueva lista.
*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
