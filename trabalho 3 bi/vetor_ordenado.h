#ifndef VETOR_ORDENADO_H
#define VETOR_ORDENADO_H

#include "boolean.h"

typedef struct VetorOrdenado {
   int tamanho;
   int* vetor;
} VetorOrdenado;

void inicializa_vetor_vo(struct VetorOrdenado *vetor);
void popular_vetor_vo(struct VetorOrdenado *vetor, int tamanho);
void ordenar_vetor_vo(struct VetorOrdenado *vetor);
void retornar_numeros_ordenados(struct VetorOrdenado* vetor, int numero, int *comparacoes);

#endif