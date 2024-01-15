#include <stdio.h>
#include "colDina.h"
#include <stdlib.h>

void manejaMsg(int);
void liberarMem(COLA);
void datosEntrada(COLA);
void mostrarCola(COLA);
void agregaDato(COLA C);
//int ultimoCola(COLA);

void main() {
    COLA C;
    C= crearCola();
    //datosEntrada(C);
    agregaDato(C);
    mostrarCola(C);
    liberarMem(C);

}

/*void datosEntrada(COLA C) {
    int v;
    printf("Ingrese los datos de la cola:\n");
    do {
        printf("Ingrese dato (0 para detener):\n");
        scanf("%d", &v);
        if (v != 0) {
            encolar(C, v);
        }
    } while (v != 0);
}*/
void agregaDato(COLA C){
      char v;
      do{
        printf("Desea agregar datos? ('s' si, 'n' no):\t");
        scanf("%c",&v);
        if(v!='N'&& v!='n'){
            datosEntrada(C);
        }
    }while (v!='N'&& v!='n');
}
void datosEntrada(COLA C){
    int v;
        printf("Ingresa el valor:\t");
        scanf("%d",&v);
            encolar(C,v);
getchar();

}

void mostrarCola(COLA C){
int v;
printf("Los datos de la cola son:\n");
while(es_vaciaCola(C)!=TRUE){
     v=desencolar(C);
     printf("%d\n",v);
}
}
void liberarMem(COLA C) {
    free(C);
    manejaMsg(5);
}
void manejaMsg(int e){
    char * errores[]={ "No hay memoria disponible\n","La pila esta llena\n","La pila esta vacia\n","La cola esta llena\n","La cola esta vacia\n","Se ha liberado memoria...\n"};
    
    printf("%s",errores[e]);
}
