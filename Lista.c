#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"
#include "Integrantes.h"

ListaEnc* crearLista() {
    ListaEnc* lista = malloc(sizeof(*lista));
    if (lista == NULL)
        return NULL;
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

int liberarLista(ListaEnc* lista) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    // remove todos os elementos da lista
    while(!estaVacia(lista))
        remover(lista, NULL, 0);
    free(lista);
    lista = NULL;
    return OK;
}

int estaVacia(ListaEnc* lista) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (lista->inicio == NULL)
        return TRUE;
    return FALSE;
}

No* crearNo(Integrantes i, No* prox) {
	No *no = malloc(sizeof(*no));
	if (no == NULL)
        return NULL;
	no->i = i;
	no->prox = prox;
	return no;
}

int insertarInicio(ListaEnc* lista, Integrantes i) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    No *novoNo = crearNo(i, lista->inicio);
    if (novoNo == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    lista->inicio = novoNo;
    lista->tam++;
    return OK;
}

int insertar(ListaEnc* lista, Integrantes i, int pos) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (pos < 0 || pos > lista->tam)
        return INDICE_INVALIDO;

    No *novoNo;
    if (pos == 0) {
        return insertarInicio(lista, i);
    } else {
        // prepara para inserir
        No *aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        // adiciona o nó
        novoNo = novoNo = crearNo(i, aux->prox);
        if (novoNo == NULL)
            return ESTRUCTURA_NO_INICIALIZADA;
        aux->prox = novoNo;
    }
    lista->tam++;
    return OK;
}

int insertarFin(ListaEnc* lista, Integrantes i) {
    return insertar(lista, i, lista->tam);
}

int removerInicio(ListaEnc* lista, Integrantes *i) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;
    No *aux = lista->inicio;
    if (i != NULL)
        *i = aux->i;
    lista->inicio = aux->prox;
    free(aux);
    aux = NULL;
    lista->tam--;
    return OK;

}

int remover(ListaEnc* lista, Integrantes *i, int pos) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;
    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    No *ant, *atual;
    if (pos == 0) {
        return removerInicio(lista, i);
    } else {
        // prepara para remover
        ant = NULL;
        atual = lista->inicio;
        for(int i = 0; i < pos; i++) {
            ant = atual;
            atual = atual->prox;
        }

        // remove o nó atual
        ant->prox = atual->prox;
        if (i != NULL)
            *i = atual->i;
        free(atual);
        atual = NULL;
    }
    lista->tam--;
    return OK;
}

int removerFin(ListaEnc* lista, Integrantes *i) {
    return remover(lista, i, lista->tam - 1);
}

int obtenerElemento(ListaEnc* lista, Integrantes *i, int pos) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (estaVacia(lista))
        return ESTRUCTURA_VACIA;

    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    if (i== NULL)
        return PARAMETRO_INVALIDO;


    No *aux;
    aux = lista->inicio;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    *i = aux->i;

    return OK;
}

int obtenerTamanio(ListaEnc* lista, int* tam) {
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;
    if (tam == NULL)
        return PARAMETRO_INVALIDO;
    *tam = lista->tam;
    return OK;
}

void imprimir(ListaEnc* lista) {
    int qtdeElementos;
    obtenerTamanio(lista, &qtdeElementos);
    printf("\n");
    Integrantes el;

    for(int i = 0;i < qtdeElementos; i++) {

        obtenerElemento(lista, &el, i);
        mostrarIntegrantes(el);


    }
    printf("\n");
}
