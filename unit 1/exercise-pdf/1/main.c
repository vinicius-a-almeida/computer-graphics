#include <stdio.h>
#include "vetor.h"

int main() {
    int v1[MAX_DIM], v2[MAX_DIM], resultado[MAX_DIM];

    printf("\nEncontrando o vetor\n");
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

    printf("\nEncontrando a norma do vetor\n");
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

    printf("\nDeslocamento do vetor\n");
    criarVetor(v1, 2, -5, 0, 2);
    criarVetor(v2, 2, 4, 0, 2);
    deslocaVetores(v1, v2, resultado, 2);
    imprimirVetor("A", resultado, 2);

    criarVetor(v1, 3, 5, -6, 3);
    criarVetor(v2, -3, 2, -3, 3);
    deslocaVetores(v1, v2, resultado, 3);
    imprimirVetor("B", resultado, 3);
    printf("\n-----------------------------------\n");

    printf("\nOperações do vetor\n");
    criarVetor(v1, 2, -5, 0, 2);
    criarVetor(v2, 2, 4, 0, 2);
    somarVetores(v1, v2, resultado, 2);
    imprimirVetor("A", resultado, 2);

    criarVetor(v1, 3, 2, 0, 2);
    criarVetor(v2, 1, 7, 0, 2);
    subtrairVetores(v1, v2, resultado, 2);
    imprimirVetor("B", resultado, 2);

    criarVetor(v1, 3, 5, -6, 3);
    criarVetor(v2, -3, 2, -3, 3);
    somarVetores(v1, v2, resultado, 3);
    imprimirVetor("C", resultado, 3);

    criarVetor(v1, 5, 5, 1, 3);
    criarVetor(v2, 3, 1, 7, 3);
    subtrairVetores(v1, v2, resultado, 3);
    imprimirVetor("D", resultado, 3);

    printf("\n-----------------------------------\n");

    printf("\nOperações do vetor Multiplicar e Normalizar\n");

    criarVetor(v1, 2, 4, 0, 2);
    int escalar = 3;
    multiplicarVetoresEscalar(v1, escalar, resultado, 2);
    imprimirVetor("A", resultado, 2);

    criarVetor(v1, 1, 7, 5, 3);
    escalar = -5;
    multiplicarVetoresEscalar(v1, escalar, resultado, 3);
    imprimirVetor("B", resultado, 3);

    criarVetor(v1, 12, 3, 0, 2);
    normalizeVetores(v1, resultado, 1);
    imprimirVetor("C", resultado, 1);

    criarVetor(v1, -3, 4, -5, 3);
    normalizeVetores(v1, resultado, 1);
    imprimirVetor("D", resultado, 1);


    printf("\n-----------------------------------\n");

    printf("\nProduto vetorial\n");

    criarVetor(v1, 2, -4, 0, 3);
    criarVetor(v2, 5, 3, 0, 3);
    produtoVetorial2D(v1, v2, resultado);
    imprimirVetor("A", resultado, 1);

    criarVetor(v1, 1, 7, 5, 3);
    criarVetor(v2, 2, 4, 5, 3);
    produtoVetorial3D(v1, v2, resultado);
    imprimirVetor("B", resultado, 3);

    return 0;
}
