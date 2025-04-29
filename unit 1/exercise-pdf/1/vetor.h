#ifndef VETOR_H
#define VETOR_H

#define MAX_DIM 3

void criarVetor(int vetor[], int x, int y, int z, int dim);
void subtrairVetores(int v1[], int v2[], int resultado[], int dim);
void imprimirVetor(const char *character, int vetor[], int dim);
void normaVetores(int v1[], int resultado[], int dim);
void deslocaVetores(int v1[],int v2[], int resultado[], int dim);

#endif
