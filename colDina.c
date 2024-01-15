// Archivo de colaDina.c
#include<stdio.h>
#include<stdlib.h>
#include "colDina.h"

void manejaMsg(int);
// CREACION DE UNA COLA VACÍA
COLA crearCola (  ){
	COLA C;
	C = (COLA)malloc(sizeof(Cola));
	if( C == NULL){
		manejaMsg(0); 
		exit(0);
	}
	C->primero = NULL;
	C->ultimo = NULL;
      return C;
}

// CREA UN ELEMENTO DE LA COLA
Nodo_Cola * crearNodoCola(  ){
   Nodo_Cola  * nvo;
   nvo = (Nodo_Cola *)malloc(sizeof(Nodo_Cola));
   if( nvo == NULL){
      manejaMsg(0);
      exit(0); 
   }
   return nvo;
}

// ESTA VACÍA LA COLA
int es_vaciaCola (COLA C){
	if( C-> primero == NULL && C-> ultimo == NULL)
		return TRUE;
	else
		return FALSE;
}

// CONSULTAR EL PRIMER ELEMENTO DE LA ESTRUCTURA COLA

int primero (COLA C){
	int v;
	if( es_vaciaCola(C)==TRUE){
		manejaMsg(4); //COLA VACIA
		exit(0);
	}
	v = C -> primero -> dato;
	return v;
}

// AGREGAR ELEMENTOS A LA COLA
void encolar (COLA C, int  e){
	Nodo_Cola  *  nvo;

	nvo = crearNodoCola( );
	nvo -> dato = e;
	nvo -> siguiente = NULL;
       if ( es_vaciaCola(C)==TRUE){
		C -> primero = nvo;
 		C -> ultimo = nvo;
	}
	else{
		C ->ultimo ->siguiente = nvo;
		C -> ultimo = nvo;
	}
	C -> ultimo = nvo;
}

// ELIMINAR UN ELEMENTO DE LA COLA
int desencolar(COLA C){
	int v;
	Nodo_Cola *  aux;

	if( es_vaciaCola(C)==TRUE){
        manejaMsg(4); //COLA VACIA
	  exit(0);
	}
	aux = C -> primero;
	v = aux -> dato;
	C-> primero = aux ->siguiente;
	if ( C-> primero == NULL)
		C -> ultimo =  NULL;
      free(aux);
	return v;
}
