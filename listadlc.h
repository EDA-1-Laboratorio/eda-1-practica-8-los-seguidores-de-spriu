#ifndef LISTADLC_H
#define LISTADLC_H

#include <stdio.h>
#include <stdlib.h>

typedef int DATO;

/* Nodo de la lista doblemente ligada CIRCULAR */
typedef struct dlclista {
    DATO dato;
    struct dlclista *previo;
    struct dlclista *siguiente;
} dlclista;

/* Lista doblemente ligada circular */
typedef struct lista_dlc {
    dlclista *cabeza;
    int longitud;
} ListaDLC;

/*
 * Crea un nodo con el dato proporcionado.
 * Los punteros previo y siguiente se inicializan a NULL.
 * Retorna un puntero al nodo creado, o NULL si falla la asignación.
 */
dlclista *crear_elemento(DATO dato);

/*
 * Inicializa una lista doblemente ligada circular vacía.
 * Retorna un puntero a la lista creada, o NULL si falla la asignación.
 */
ListaDLC *crear_lista(void);

/*
 * Inserta un nuevo nodo con el dato dado al inicio de la lista.
 */
void insertar_inicio(ListaDLC *lista, DATO dato);

/*
 * Inserta un nuevo nodo con el dato dado al final de la lista.
 */
void insertar_final(ListaDLC *lista, DATO dato);

/*
 * Inserta un nuevo nodo con el dato dado en la posición indicada (0-indexada).
 */
void insertar_en_posicion(ListaDLC *lista, DATO dato, int posicion);

/*
 * Elimina el primer nodo de la lista y retorna su dato.
 * Si la lista está vacía, retorna -1.
 */
DATO eliminar_inicio(ListaDLC *lista);

/*
 * Elimina el último nodo de la lista y retorna su dato.
 * Si la lista está vacía, retorna -1.
 */
DATO eliminar_final(ListaDLC *lista);

/*
 * Elimina el nodo en la posición indicada (0-indexada) y retorna su dato.
 * Si la posición es inválida, retorna -1.
 */
DATO eliminar_en_posicion(ListaDLC *lista, int posicion);

/*
 * Busca la primera ocurrencia del dato en la lista.
 * Retorna la posición (0-indexada) si lo encuentra, -1 si no.
 */
int buscar(ListaDLC *lista, DATO dato);

/*
 * Obtiene el dato en la posición indicada (0-indexada).
 * Si la posición es inválida, retorna -1.
 */
DATO obtener(ListaDLC *lista, int posicion);

/*
 * Retorna 1 si la lista está vacía, 0 en caso contrario.
 */
int esta_vacia(ListaDLC *lista);

/*
 * Retorna la longitud de la lista.
 */
int longitud(ListaDLC *lista);

/*
 * Imprime la lista de inicio a fin, marcando cuando se finaliza una vuelta.
 */
void imprimir_lista(ListaDLC *lista);

/*
 * Imprime la lista de fin a inicio, marcando cuando se finaliza una vuelta.
 */
void imprimir_lista_reversa(ListaDLC *lista);

/*
 * Libera toda la memoria de la lista, incluyendo sus nodos.
 */
void liberar_lista(ListaDLC *lista);

#endif /* LISTADLC_H */
