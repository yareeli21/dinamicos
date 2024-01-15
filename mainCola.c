#include <stdio.h>
#include "cola.h"
#include <stdlib.h>

void manejaMsg(int);
void liberarMem(COLA);
void datosEntrada(COLA);
void mostrarCola(COLA);


void main() {
    COLA C;
    C= crearCola();
    datosEntrada(C);
    mostrarCola(C);
    liberarMem(C);

}
void datosEntrada(COLA C){
    int v;
    do{
        printf("Ingrese dato (0 para detener)");
        scanf("%d",&v);
        if(v!=0){
            encolar(C,v);
        }
    }while (v!=0);
}
void mostrarCola(COLA C){
    printf("Los datos de la cola son:\n");
    while(es_vaciaCola(C)!=TRUE){
        int v;
        v=desencolar(C);
        printf("%d\n",v);
    }
}
void liberarMem(COLA C) {
    free(C);
    manejaMsg(1);
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","Pila vacia. . .","Pila llena. . ."};
     printf("%s", mensajes[msg] );
}
