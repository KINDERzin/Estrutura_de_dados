#ifndef VETOR_DESORDENADO_H
#define VETOR_DESORDENADO_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
   false, true
} boolean;

typedef struct Vetor {
   int tamanho;
   int* vetor;
} Vetor;

boolean eh_nulo_vd(struct Vetor* vetor) {
   return vetor->vetor == NULL;
}

void inicializa_vetor_vd(struct Vetor *vetor) {
   vetor->tamanho = 0;
   vetor->vetor = NULL;
}

void popular_vetor_vd(struct Vetor *vetor, int tamanho) {
   vetor->tamanho = tamanho;
   vetor->vetor = (int*) malloc(tamanho * sizeof(int));

   for(int i = 0; i < tamanho; i++)
      vetor->vetor[i] = rand();
}

void retornar_numeros_desordenados(struct Vetor* vetor, int numero, int *comparacoes) {
   for(int i = 0; i < vetor->tamanho; i++) {
      (*comparacoes)++;
      if(vetor->vetor[i] == numero) {
         printf("Número %d encontrado na posição %d\n", numero, i);
         return;
      }
   }

   printf("Número %d não encontrado no vetor desordenado.\n", numero);
}

#endif