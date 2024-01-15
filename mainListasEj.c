#include<stdio.h>
#include<stdlib.h>
#include "listaEj.h"

void manejaMsg(int e);
void agregaDato(LISTA L);
void datosEntrada(LISTA L);
void liberarMem(LISTA);
Animal crearAnimal();
LISTA leerDatos(LISTA L);
void ordenar(LISTA L);
void ordenarPorIden(LISTA L);

void main(){
  LISTA L=crearLista();
  L=leerDatos(L);
  visualizaLista(L);
  ordenarPorIden(L);
  printf("Ordenadas por numero de identificacion:\n");
  visualizaLista(L);

  liberarMem(L);

  
}

Animal crearAnimal(){
     Animal a;
     printf("Ingrese el numero de identificacion:\n");
     scanf("%d",&a.iden);
     getchar();
     printf("Ingrese la raza del animal:\n");
     scanf("%[^\n]",a.raza);
     getchar();
     printf("Ingrese el peso del animal:\n");
     scanf("%f",&a.peso);
     
     return a;
}
LISTA leerDatos(LISTA L){
	Animal a;
	int op;
	do{
		printf("Ingrese los datos de cada animal\n");
		a=crearAnimal();
		L=insertar(L, a);
		printf("Desea ingresar un animal a la lista? (1=Si 0=No)\n");
		scanf("%d",&op);
		getchar();
	} while (op!=0);
    return L;
}
void imprimirAnimal(Animal a){
	printf("Identificacion: %d\n",a.iden);
	printf("Raza: %s\n",a.raza);
	printf("Peso: %.2f\n",a.peso);
	printf("\n");
}

void ordenarPorIden(LISTA L) {
    //creando nodos para tener mas cajitas de la lista
    Nodo_Lista *actual, *siguiente;
    Animal temp;//temporal para guardar el dato e ir intercambiando

    if (es_vaciaLista(L) == TRUE) {
        manejaMsg(6); // LISTA VACIA
        return;
    }

    actual = L;

    while (actual != NULL) {
        siguiente = actual->siguiente;

        while (siguiente != NULL) {
            if (actual->dato.iden > siguiente->dato.iden) {
                //intercambiar los valores completos de Animal
                temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;
            }
            siguiente = siguiente->siguiente;
        }

        actual = actual->siguiente;
    }
}

void manejaMsg(int e){
    char * errores[]={ "No hay memoria disponible\n","La pila esta llena\n","La pila esta vacia\n","La cola esta llena\n","La cola esta vacia\n","Se ha liberado memoria...\n","Lista vacia..\n"};
    
    printf("%s",errores[e]);
}


/*void agregaDato(LISTA L){
      char v;
      do{
        printf("Desea agregar datos a la lista? ('s' si, 'n' no): ");
        scanf(" %c",&v);
        if(v!='N'&& v!='n'){
            datosEntrada(L);
        }
    }while (v!='N'&& v!='n');
}*/
/*void datosEntrada(LISTA L){
    int v;
        printf("Ingresa el valor:\t");
        scanf("%d",&v);
            insertar(L,v);
getchar();

}*/
void liberarMem(LISTA L) {
    free(L);
    manejaMsg(5);
}
