// Archivo main.c

#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

void datosEntrada(PILA pila);
void mostrarPila(PILA pila);
void intercalar(PILA, PILA, PILA);
void liberarPila(PILA);



int main() {
    PILA A, B, C;
	A = crearPila();
	B = crearPila();
	C = crearPila();
	datosEntrada(A);
	printf("\n\n");
	datosEntrada(B);
	intercalar(A, B, C);
	mostrarPila(C);

	liberarPila(A);
	liberarPila(B);
	liberarPila(C);

    return 0;
}

void intercalar(PILA A, PILA B, PILA C){

	while ((!es_vaciaPila(A))&&(!es_vaciaPila(B))) {
		apilar(C, desapilar(A));
		apilar(C, desapilar(B));
	}

}


void datosEntrada(PILA pila) {
    char valor;
    char continuar;

    do {
        printf("Ingrese un caracter: ");
        scanf(" %c", &valor);

        apilar(pila, valor);

        printf("¿Desea ingresar otro caracter? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');
}


void mostrarPila(PILA pila) {
	
	printf("Contenido de la pila:\n");
	while (!es_vaciaPila(pila)) {
        	printf("%c", desapilar(pila));
    	}
    	
    	printf("\n");
}

void liberarPila(PILA pila){
	while (!es_vaciaPila(pila)) {
        desapilar(pila);
	}

	free(pila);
}
