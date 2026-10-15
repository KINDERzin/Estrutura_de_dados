#ifndef VETOR_DESORDENADO_H
#define VETOR_DESORDENADO_H

#include "boolean.h"

typedef struct VetorDesordenado {
   int tamanho;
   int* vetor;
} VetorDesordenado; 

void inicializa_vetor_vd(struct VetorDesordenado *vetor);
void popular_vetor_vd(struct VetorDesordenado *vetor, int tamanho);
void retornar_numeros_desordenados(struct VetorDesordenado* vetor, int numero, int *comparacoes);

#endif