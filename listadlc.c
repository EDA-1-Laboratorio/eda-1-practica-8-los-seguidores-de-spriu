#include "listadlc.h"

dlclista *crear_elemento(DATO dato) {
    dlclista *nuevo = (dlclista *)malloc(sizeof(dlclista));
    if (nuevo == NULL)
        return NULL;
    nuevo->dato = dato;
    nuevo->previo = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

ListaDLC *crear_lista(void) {
    ListaDLC *lista = (ListaDLC *)malloc(sizeof(ListaDLC));
    if (lista == NULL)
        return NULL;
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

void insertar_inicio(ListaDLC *lista, DATO dato) {
    dlclista *nuevo = crear_elemento(dato);
    if (nuevo == NULL)
        return;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->previo = nuevo;
    } else {
        dlclista *ultimo = lista->cabeza->previo;
        nuevo->siguiente = lista->cabeza;
        nuevo->previo = ultimo;
        lista->cabeza->previo = nuevo;
        ultimo->siguiente = nuevo;
        lista->cabeza = nuevo;
    }
    lista->longitud++;
}

void insertar_final(ListaDLC *lista, DATO dato) {
    dlclista *nuevo = crear_elemento(dato);
    if (nuevo == NULL)
        return;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->previo = nuevo;
    } else {
        dlclista *ultimo = lista->cabeza->previo;
        nuevo->siguiente = lista->cabeza;
        nuevo->previo = ultimo;
        ultimo->siguiente = nuevo;
        lista->cabeza->previo = nuevo;
    }
    lista->longitud++;
}

void insertar_en_posicion(ListaDLC *lista, DATO dato, int posicion) {
    if (posicion < 0 || posicion > lista->longitud)
        return;

    if (posicion == 0) {
        insertar_inicio(lista, dato);
        return;
    }
    if (posicion == lista->longitud) {
        insertar_final(lista, dato);
        return;
    }

    dlclista *nuevo = crear_elemento(dato);
    if (nuevo == NULL)
        return;

    dlclista *actual = lista->cabeza;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;

    nuevo->previo = actual->previo;
    nuevo->siguiente = actual;
    actual->previo->siguiente = nuevo;
    actual->previo = nuevo;
    lista->longitud++;
}

DATO eliminar_inicio(ListaDLC *lista) {
    if (lista->cabeza == NULL)
        return -1;

    dlclista *eliminado = lista->cabeza;
    DATO dato = eliminado->dato;

    if (lista->longitud == 1) {
        lista->cabeza = NULL;
    } else {
        dlclista *ultimo = lista->cabeza->previo;
        lista->cabeza = lista->cabeza->siguiente;
        lista->cabeza->previo = ultimo;
        ultimo->siguiente = lista->cabeza;
    }

    free(eliminado);
    lista->longitud--;
    return dato;
}

DATO eliminar_final(ListaDLC *lista) {
    if (lista->cabeza == NULL)      return -1;

    dlclista *eliminado = lista->cabeza->previo;
    DATO dato = eliminado->dato;

    if (lista->longitud == 1) {
        lista->cabeza = NULL;
    } else {
        dlclista *penultimo = eliminado->previo;
        penultimo->siguiente = lista->cabeza;
        lista->cabeza->previo = penultimo;
    }

    free(eliminado);
    lista->longitud--;
    return dato;
}

DATO eliminar_en_posicion(ListaDLC *lista, int posicion) {
    if (posicion < 0 || posicion >= lista->longitud)
        return -1;

    if (posicion == 0)
        return eliminar_inicio(lista);
    if (posicion == lista->longitud - 1)
        return eliminar_final(lista);

    dlclista *actual = lista->cabeza;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;

    DATO dato = actual->dato;
    actual->previo->siguiente = actual->siguiente;
    actual->siguiente->previo = actual->previo;
    free(actual);
    lista->longitud--;
    return dato;
}

int buscar(ListaDLC *lista, DATO dato) {
    dlclista *actual = lista->cabeza;
    for (int i = 0; i < lista->longitud; i++) {
        if (actual->dato == dato)
            return i;
        actual = actual->siguiente;
    }
    return -1;
}

DATO obtener(ListaDLC *lista, int posicion) {
    if (posicion < 0 || posicion >= lista->longitud)
        return -1;

    dlclista *actual = lista->cabeza;
    for (int i = 0; i < posicion; i++)
        actual = actual->siguiente;
    return actual->dato;
}

int esta_vacia(ListaDLC *lista) {
    return lista->cabeza == NULL;
}

int longitud(ListaDLC *lista) {
    return lista->longitud;
}

void imprimir_lista(ListaDLC *lista) {
    if (lista->cabeza == NULL) {
        printf("Lista vacia -> NULL\n");
        return;
    }
    
    dlclista *actual = lista->cabeza;
    for (int i = 0; i < lista->longitud; i++) {
        printf("[%d]", actual->dato);
        if (i < lista->longitud - 1)
            printf(" <-> ");
        actual = actual->siguiente;
    }

    printf(" ||| regresamos a [%d]\n", lista->cabeza->dato);
}

void imprimir_lista_reversa(ListaDLC *lista) {
    if (lista->cabeza == NULL) {
        printf("Lista vacia -> NULL\n");
        return;
    }
    
    dlclista *actual = lista->cabeza->previo;
    for (int i = 0; i < lista->longitud; i++) {
        printf("[%d]", actual->dato);
        if (i < lista->longitud - 1)
            printf(" <-> ");
        actual = actual->previo;
    }
    printf(" ||| regresamos a [%d]\n", lista->cabeza->previo->dato);
}

void liberar_lista(ListaDLC *lista) {
    if (lista->cabeza != NULL) {
        dlclista *actual = lista->cabeza;
        for (int i = 0; i < lista->longitud; i++) {
            dlclista *siguiente = actual->siguiente;
            free(actual);
            actual = siguiente;
        }
    }
    free(lista);
}
