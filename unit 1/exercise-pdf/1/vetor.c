#include <stdio.h>
#include <math.h>
#include "vetor.h"

void criarVetor(int vetor[], int x, int y, int z, int dim) {
    vetor[0] = x;
    vetor[1] = y;
    if (dim == 3)
        vetor[2] = z;
}

void subtrairVetores(int v1[], int v2[], int resultado[], int dim) {
    for (int i = 0; i < dim; i++) {
        resultado[i] = v1[i] - v2[i];
    }
}

void imprimirVetor(const char *character, int vetor[], int dim) {
    printf("%s: (", character);
    for (int i = 0; i < dim; i++) {
        printf("%d", vetor[i]);
        if (i < dim - 1)
            printf(",");
    }
    printf(")\n");
}

void normaVetores(int v1[], int resultado[], int dim) {
    for (int i = 0; i < dim; i++) {
        resultado[i] = sqrt(pow(v1[i], 2) + pow(v1[i+1], 2));
    }
}

void deslocaVetores(int v1[], int v2[], int resultado[], int dim) {
    for (int i = 0; i < dim; i++) {
        resultado[i] = v1[i] + v2[i];
    }
}

void somarVetores(int v1[], int v2[], int resultado[], int dim) {
    for (int i = 0; i < dim; i++) {
        resultado[i] = v2[i] + v1[i];
    }
}

void multiplicarVetoresEscalar(int v1[], int esc, int resultado[], int dim) {
    for (int i = 0; i < dim; i++) {
        resultado[i] = v1[i] * esc;
    }
}

void normalizeVetores(int v1[], int resultado[], int dim) {
    for (int i = 0; i < dim; i++) {
        resultado[i] = v1[i] / sqrt(pow(v1[i], 2) + pow(v1[i+1], 2));
    }
}

void produtoVetorial2D(int v1[], int v2[], int resultado[]) {
    resultado[0] = v1[0] * v2[1] - v1[1] * v2[0];
}

void produtoVetorial3D(int v1[], int v2[], int resultado[]) {
    resultado[0] = v1[1] * v2[2] - v1[2] * v2[1]; 
    resultado[1] = v1[2] * v2[0] - v1[0] * v2[2]; 
    resultado[2] = v1[0] * v2[1] - v1[1] * v2[0]; 
}