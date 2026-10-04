#ifndef VETOR_ORDENADO_H
#define VETOR_ORDENADO_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
   false, true
} boolean;

typedef struct Vetor {
   int tamanho;
   int* vetor;
} Vetor;

boolean eh_nulo_vo(struct Vetor* vetor) {
   return vetor->vetor == NULL;
}

void inicializa_vetor_vo(struct Vetor *vetor) {
   vetor->tamanho = 0;
   vetor->vetor = NULL;
}

void popular_vetor_vo(struct Vetor *vetor, int tamanho) {
   vetor->tamanho = tamanho;
   vetor->vetor = (int*) malloc(tamanho * sizeof(int));

   for(int i = 0; i < tamanho; i++)
      vetor->vetor[i] = rand();
}

void ordenar_vetor_vo(struct Vetor *vetor) {
   int aux;

   for(int i = 0; i < vetor->tamanho; i++)
      for(int j = 0; j < vetor->tamanho - 1; j++)
         if(vetor->vetor[j] > vetor->vetor[j + 1]) {
            aux = vetor->vetor[j];

            vetor->vetor[j] = vetor->vetor[j + 1];
            vetor->vetor[j + 1] = aux;
         }   
}

void retornar_numeros_ordenados(struct Vetor* vetor, int numero, int *comparacoes) {
   // Tamanmho -> 0 até (tamanho - 1)
   int esq = 0;
   int dir = vetor->tamanho - 1; 
   

   while (esq <= dir) {
      int meio = (esq + dir) / 2;

      (*comparacoes)++;
      if (numero == vetor->vetor[meio]) {
         printf("Número %d encontrado na posição %d\n", numero, meio);
         return;
      }

      else if (numero < vetor->vetor[meio])
         dir = meio - 1;

      else if (numero > vetor->vetor[meio])
         esq = meio + 1;
   }

   printf("Número %d não encontrado no vetor ordenado.\n", numero);
}

#endif