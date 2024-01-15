#include <stdio.h>
#include "colaEj1.h"
#include "pila.h"
#include <stdlib.h>
#include<string.h>

void manejaMsg(int);
void liberarMem(COLA);
void datosEntrada(COLA);
void mostrarCola(COLA);
void agregaDato(COLA C);
void lee(char *ent);
void agregarCadP(PILA S, char *ent);
void agregarCadC(COLA C, char *ent);
void verifica(int palin);
int esPalindrome(COLA C, PILA S);

//int ultimoCola(COLA);

void main() {
    COLA C;
    PILA S;
    char ent[TAMPILA];
    int palin;
    C= crearCola();
    S=crearPila();
    lee(ent);
    agregarCadP(S,ent);
    agregarCadC(C,ent);
    palin=esPalindrome(C,S);
    verifica(palin);
    //mostrarCola(C);
    liberarMem(C);

}

void verifica(int palin){
   if(palin==1){
     printf("La cadena si es palindrome.\n");
   }
   else{
   printf("La cadena no es palindrome.\n");
   }
}
int esPalindrome(COLA C, PILA S){
COLA aux=crearCola();
  while(es_vaciaCola(C)!=TRUE && es_vaciaPila(S)!=TRUE){
      char c1=desencolar(C);
      char c2=desapilar(S);
      if(c1==c2){
         encolar(aux,c1);
      }
      else
      break;
  }
  if(es_vaciaCola(aux)!=TRUE)
     return 1;
    else
      return 0;     
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
void lee(char *ent){
  printf("\n\n Introduce una cadena: ");
  scanf("%[^\n]",ent);
}
void agregarCadP(PILA S, char *ent){
    int tam=strlen(ent);
    int i;
    for(i=0;i<tam;i++){
        apilar(S,ent[i]);
    }
}
void agregarCadC(COLA C, char *ent){
    int tam=strlen(ent);
    int i;
    for(i=0;i<tam;i++){
        encolar(C,ent[i]);
    }
}
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
