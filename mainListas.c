#include<stdio.h>
#include<stdlib.h>
#include "listas.h"

void manejaMsg(int e);
void agregaDato(LISTA L);
void datosEntrada(LISTA L);
void liberarMem(LISTA);

void main(){
  LISTA L=crearLista();
  agregaDato(L);
  visualizaLista(L);

  liberarMem(L);

  
}

void manejaMsg(int e){
    char * errores[]={ "No hay memoria disponible\n","La pila esta llena\n","La pila esta vacia\n","La cola esta llena\n","La cola esta vacia\n","Se ha liberado memoria...\n","Lista vacia..\n"};
    
    printf("%s",errores[e]);
}


void agregaDato(LISTA L){
      char v;
      do{
        printf("Desea agregar datos a la lista? ('s' si, 'n' no):\t");
        scanf(" %c",&v);
        if(v!='N'&& v!='n'){
            datosEntrada(L);
        }
    }while (v!='N'&& v!='n');
}
void datosEntrada(LISTA L){
    int v;
        printf("Ingresa el valor:\t");
        scanf("%d",&v);
            insertar(L,v);
getchar();

}
void liberarMem(LISTA L) {
    free(L);
    manejaMsg(5);
}
