#include <stdio.h>
#include "vetor.h"

int main() {
    int v1[MAX_DIM], v2[MAX_DIM], resultado[MAX_DIM];

    criarVetor(v1, 2, 4, 0, 2);
    criarVetor(v2, 6, 2, 0, 2);
    subtrairVetores(v1, v2, resultado, 2);
    imprimirVetor("A", resultado, 2);

    criarVetor(v1, 6, 7, 0, 2);
    criarVetor(v2, -1, -2, 0, 2);
    subtrairVetores(v1, v2, resultado, 2);
    imprimirVetor("B", resultado, 2);

    criarVetor(v1, 2, 2, 4, 3);
    criarVetor(v2, 1, 1, 1, 3);
    subtrairVetores(v1, v2, resultado, 3);
    imprimirVetor("C", resultado, 3);

    criarVetor(v1, -2, 4, -5, 3);
    criarVetor(v2, 5, 2, -5, 3);
    subtrairVetores(v1, v2, resultado, 3);
    imprimirVetor("D", resultado, 3);
    printf("\n-----------------------------------\n");

    criarVetor(v1, 2, -5, 0, 2);
    normaVetores(v1, resultado, 2);
    imprimirVetor("A", resultado, 1);

    criarVetor(v1, 4, 2, 0, 2);
    normaVetores(v1, resultado, 2);
    imprimirVetor("B", resultado, 1);

    criarVetor(v1, 3, 5, -6, 3);
    normaVetores(v1, resultado, 3);
    imprimirVetor("C", resultado, 1);

    criarVetor(v1, 6, -2, 1, 3);
    normaVetores(v1, resultado, 3);
    imprimirVetor("D", resultado, 1);
    printf("\n-----------------------------------\n");

    criarVetor(v1, 2, -5, 0, 2);
    criarVetor(v2, 2, 4, 0, 2);
    deslocaVetores(v1, v2, resultado, 2);
    imprimirVetor("A", resultado, 2);

    criarVetor(v1, 3, 5, -6, 3);
    criarVetor(v2, -3, 2, -3, 3);
    deslocaVetores(v1, v2, resultado, 3);
    imprimirVetor("B", resultado, 3);
    printf("\n-----------------------------------\n");

    

    return 0;
}
