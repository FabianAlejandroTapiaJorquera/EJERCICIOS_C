#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arreglo[10] = {};
int arregloCopia[10] = {};

// 1.    Crear una función que llene un arreglo ya definido de 10 elementos con números aleatorios.
void llenarArreglo(int *vector, int largo){
    int i;
    srand (time(NULL));   
    for(i=0; i<largo; i++){ vector[i] = rand()%10; }
}

// 2.	Una función que muestre los elementos del arreglo.
void mostrarArreglo(int *vector, int largo){
    int i;
    for(i=0; i<largo; i++){ printf("%d ", vector[i]); }
}

// 3.	Una función que copie los elementos del arreglo a otro.
void copiarArreglo(int *vector, int *copia, int largo){
    int i;
    for(i=0; i<largo; i++){ copia[i] = vector[i]; }
}

// 4.	Una función que ordene el arreglo de forma ascendente.
void insertionSort(int *arreglo, int largo){
    int i, posicion, aux;
    for(i = 0; i<largo; i++){
        posicion = i;
        aux = arreglo[i];
        while(posicion>0 && arreglo[posicion-1]>aux){
            arreglo[posicion] = arreglo[posicion-1];
            posicion--;
        }
        arreglo[posicion] = aux;
    }
}

/* 5.	Una función que compare 2 arreglos y coloque un 0 en la posición del arreglo donde el número 
        sea menor y un 1 donde sea mayor.*/
void comparacion(int *arreglo, int *arreglo2, int largo){
    int i;
    for(i=0; i<largo; i++){ 
        arreglo[i] = arreglo[i] > arreglo2[i] ? 1 : 0; 
        arreglo2[i] = arreglo[i] == 1 ? 0 : 1;
    }
}

// 6.	Una función que al detectar un número par en el arreglo 1 coloque impar en el arreglo 2.
void parImpar(int *arreglo, int *arreglo2, int largo){
    int i;
    for(i=0; i<largo; i++){
        arreglo2[i] =  arreglo[i]%2 == 0 ? (arreglo2[i]%2 == 0 ? arreglo2[i] + 1 : arreglo2[i]) : arreglo2[i];
    }
}


int main(){
    llenarArreglo(arreglo, 10);
    copiarArreglo(arreglo, arregloCopia, 10);
    printf("Arreglo original: ");
    mostrarArreglo(arreglo, 10);
    printf("\nArreglo copia:    ");
    mostrarArreglo(arregloCopia, 10);
    insertionSort(arreglo, 10);
    printf("\nArreglo Ordenado: ");
    mostrarArreglo(arreglo, 10);

    printf("\n\n--->Comparacion de arreglos<--- ");
    llenarArreglo(arreglo, 10);
    llenarArreglo(arregloCopia, 10);
    insertionSort(arregloCopia, 10);

    printf("\nArreglo 1: ");
    mostrarArreglo(arreglo, 10);
    printf("\nArreglo 2: ");
    mostrarArreglo(arregloCopia, 10);
    comparacion(arreglo, arregloCopia, 10);
    printf("\n\n--->Resultados de la comparacion<---");
    printf("\nArreglo 1: ");
    mostrarArreglo(arreglo, 10);
    printf("\nArreglo 2: ");
    mostrarArreglo(arregloCopia, 10);

    printf("\n\n--->Par e Impar<--- ");
    llenarArreglo(arreglo, 10);
    llenarArreglo(arregloCopia, 10);
    insertionSort(arregloCopia, 10);
    printf("\nArreglo 1: ");
    mostrarArreglo(arreglo, 10);
    printf("\nArreglo 2: ");
    mostrarArreglo(arregloCopia, 10);
    parImpar(arreglo, arregloCopia, 10);
    printf("\n\n--->Resultados de Par e Impar<---");
    printf("\nArreglo 1: ");
    mostrarArreglo(arreglo, 10);
    printf("\nArreglo 2: ");
    mostrarArreglo(arregloCopia, 10);

    return 0;
}