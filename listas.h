#include<stdio.h>
#include<stdlib.h>

// Archivo listaSimple.h

// DEFINICION DEL TAD
#ifndef  _listaSimple_
#define  _listaSimple_

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Lista{
    int dato;
    struct Nodo_Lista * siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

// AGREGAR LOS PROTOTIPO DE LAS
LISTA crearLista(  );
int es_vaciaLista(LISTA L);
Nodo_Lista * crearNodoLista(  );
LISTA insertar(LISTA L, int e);
void visualizaLista(LISTA L);
void  buscarElem(LISTA L, int elem);
LISTA borrar(LISTA L, int elem);
void mostrar(int e, int msg, int p);
// OPERAICONES DEL TAD


#endif

