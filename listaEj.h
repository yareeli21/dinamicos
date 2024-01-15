#include<stdio.h>
#include<stdlib.h>

// Archivo listaSimple.h

// DEFINICION DEL TAD
#ifndef  _listaSimple_
#define  _listaSimple_

#define TRUE    1
#define FALSE  0

typedef struct{
    int iden;
    char raza[25];
    float peso;
}Animal;


typedef struct Nodo_Lista{
    Animal dato;
    struct Nodo_Lista * siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

// AGREGAR LOS PROTOTIPO DE LAS
LISTA crearLista(  );
int es_vaciaLista(LISTA L);
Nodo_Lista * crearNodoLista(  );
LISTA insertar(LISTA L, Animal e);
void visualizaLista(LISTA L);
void  buscarElem(LISTA L, Animal elem);
LISTA borrar(LISTA L, Animal elem);
void mostrar(Animal e, int msg, int p);
// OPERAICONES DEL TAD


#endif
