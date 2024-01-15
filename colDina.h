//Archivo colaDina.h

#ifndef colaDina
#define colaDina

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Cola{
	int dato;
	struct Nodo_Cola * siguiente;
}Nodo_Cola;

typedef struct{	
	Nodo_Cola * primero;
	Nodo_Cola * ultimo;
}Cola;

typedef Cola * COLA;

//FALTAN LOS PROTOTIPOS DE LAS
COLA crearCola (  );
Nodo_Cola * crearNodoCola(  );
int es_vaciaCola (COLA C);
int primero (COLA C);
void encolar (COLA C, int  e);
int desencolar(COLA C);
// OPERACIONES DE LA COLA

#endif

