#ifndef LISTADL_H
#define LISTADL_H

#include <stdio.h>
#include <stdlib.h>

typedef int DATO;

/* Nodo de la lista doblemente ligada */
typedef struct dllista {
    DATO dato;
    struct dllista *previo;
    struct dllista *siguiente;
} dllista;

/* Lista doblemente ligada */
typedef struct lista_dl {
    dllista *cabeza;
    int longitud;
} ListaDL;

/*
 * Crea un nodo con el dato proporcionado.
 * Los punteros previo y siguiente se inicializan a NULL.
 * Retorna un puntero al nodo creado, o NULL si falla la asignación.
 */
dllista *crear_elemento(DATO dato);

/*
 * Inicializa una lista doblemente ligada vacía.
 * Retorna un puntero a la lista creada, o NULL si falla la asignación.
 */
ListaDL *crear_lista(void);

/*
 * Inserta un nuevo nodo con el dato dado al inicio de la lista.
 */
void insertar_inicio(ListaDL *lista, DATO dato);

/*
 * Inserta un nuevo nodo con el dato dado al final de la lista.
 */
void insertar_final(ListaDL *lista, DATO dato);

/*
 * Inserta un nuevo nodo con el dato dado en la posición indicada (0-indexada).
 * Si la posición es 0, inserta al inicio.
 * Si la posición es igual a la longitud, inserta al final.
 * Si la posición es inválida, no hace nada.
 */
void insertar_en_posicion(ListaDL *lista, DATO dato, int posicion);

/*
 * Elimina el primer nodo de la lista y retorna su dato.
 * Si la lista está vacía, retorna -1.
 */
DATO eliminar_inicio(ListaDL *lista);

/*
 * Elimina el último nodo de la lista y retorna su dato.
 * Si la lista está vacía, retorna -1.
 */
DATO eliminar_final(ListaDL *lista);

/*
 * Elimina el nodo en la posición indicada (0-indexada) y retorna su dato.
 * Si la posición es inválida, retorna -1.
 */
DATO eliminar_en_posicion(ListaDL *lista, int posicion);

/*
 * Busca la primera ocurrencia del dato en la lista.
 * Retorna la posición (0-indexada) si lo encuentra, -1 si no.
 */
int buscar(ListaDL *lista, DATO dato);

/*
 * Obtiene el dato en la posición indicada (0-indexada).
 * Si la posición es inválida, retorna -1.
 */
DATO obtener(ListaDL *lista, int posicion);

/*
 * Retorna 1 si la lista está vacía, 0 en caso contrario.
 */
int esta_vacia(ListaDL *lista);

/*
 * Retorna la longitud de la lista.
 */
int longitud(ListaDL *lista);

/*
 * Imprime la lista de inicio a fin en el formato:
 * [dato0] <-> [dato1] <-> ... <-> [datoN] -> NULL
 */
void imprimir_lista(ListaDL *lista);

/*
 * Imprime la lista de fin a inicio en el formato:
 * [datoN] <-> ... <-> [dato1] <-> [dato0] -> NULL
 */
void imprimir_lista_reversa(ListaDL *lista);

/*
 * Libera toda la memoria de la lista, incluyendo sus nodos.
 */
void liberar_lista(ListaDL *lista);

#endif /* LISTADL_H */
