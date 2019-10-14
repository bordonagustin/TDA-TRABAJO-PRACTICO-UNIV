#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define TRUE 1
#define FALSE 0

#define OK 1
#define ESTRUCTURA_NO_INICIALIZADA -1
#define ESTRUCTURA_VACIA-2
#define INDICE_INVALIDO -3
#define PARAMETRO_INVALIDO -4

#include "Integrantes.h"

// Declaramos la estructura del nodo, prox es un puntero al siguiente nodo
typedef struct {
  Integrantes i;
  struct No* prox;
} No;

typedef struct {
  No* inicio;
  int tam;
} ListaEnc;

ListaEnc* crearLista();

int liberarLista(ListaEnc* lista);
int estaVacia(ListaEnc* lista);

int insertarInicio(ListaEnc* lista, Integrantes i);
int insertar(ListaEnc* lista, Integrantes i, int pos);
int insertarFin(ListaEnc* lista, Integrantes i);

int removerInicio(ListaEnc* lista, Integrantes *i);
int remover(ListaEnc* lista, Integrantes *i, int pos);
int removerFin(ListaEnc* lista, Integrantes *i);

int obtenerElemento(ListaEnc* lista, Integrantes *i, int pos);
int obtenerTamanio(ListaEnc* lista, int* tam);

void imprimir(ListaEnc* lista);

#endif // LISTA_H_INCLUDED
